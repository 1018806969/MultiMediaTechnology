//
//  AudioPlayerFlexViewController.m
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

#import "AudioPlayerFlexViewController.h"
#import <AVFoundation/AVFoundation.h>
#define SCREEN_W [UIScreen mainScreen].bounds.size.width
#define SCREEN_H [UIScreen mainScreen].bounds.size.height


@interface AudioPlayerFlexViewController ()<AVAudioPlayerDelegate>
@property(nonatomic,strong)AVAudioPlayer   *audioPlayer;
@property(nonatomic,strong)UIView          *controlView;
@property(nonatomic,strong)UIProgressView  *progressView;
@property(nonatomic,strong)UILabel         *singerLabel;
@property(nonatomic,strong)UIButton        *playOrPauseButton;
@property(nonatomic,strong)NSTimer         *timer;

@end

@implementation AudioPlayerFlexViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Audio Play";
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    [self playMusic];
}
-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    //开启远程控制
    [[UIApplication sharedApplication]beginReceivingRemoteControlEvents];
    //作为第一响应者
    [self becomeFirstResponder];
}
-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    [[UIApplication sharedApplication]endReceivingRemoteControlEvents];
    [self resignFirstResponder];
}

-(void)playMusic
{
    _controlView = [[UIView alloc]initWithFrame:CGRectMake(0, SCREEN_H-200, SCREEN_W, 200)];
    _controlView.backgroundColor = [UIColor grayColor];
    [self.view addSubview:_controlView];
    
    _singerLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 10, SCREEN_W, 40)];
    _singerLabel.text = @"陈姿彤-我的世界";
    _singerLabel.textAlignment = YES ;
    [_controlView addSubview:_singerLabel];
    
    _progressView = [[UIProgressView alloc]initWithFrame:CGRectMake(0, 55, SCREEN_W, 20)];
    _progressView.progress = 0 ;
    [_controlView addSubview:_progressView];
    
    _playOrPauseButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _playOrPauseButton.frame = CGRectMake(SCREEN_W/2-25, 80, 50, 50);
    _playOrPauseButton.backgroundColor = [UIColor redColor];
    [_playOrPauseButton addTarget:self action:@selector(playOrPauseClick) forControlEvents:UIControlEventTouchUpInside];
    [_controlView addSubview:_playOrPauseButton];
    
}
-(void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag
{
    NSLog(@"play complete %@-%d",player,flag);
    //根据实际情况播放完成可以将会话关闭，其他音频应用继续播放
    [[AVAudioSession sharedInstance]setActive:NO error:nil];
}
-(void)updateProgress
{
    float progress = self.audioPlayer.currentTime/self.audioPlayer.duration;
    _progressView.progress = progress ;
}
-(void)playOrPauseClick
{
    if ([self.audioPlayer isPlaying]) {
        [_audioPlayer pause];
        //暂停定时器，不能使用invalidate方法，此方法是将定时器损毁，之后不能回复
        _timer.fireDate = [NSDate distantFuture];
        _playOrPauseButton.backgroundColor = [UIColor blueColor];
    }else
    {
        [self.audioPlayer play];
        _playOrPauseButton.backgroundColor = [UIColor redColor];
        //回复定时器
        _timer.fireDate = [NSDate distantPast];
    }
}
/**
 一但输出改变则会受到此通知

 @param notif 输出改变通知对象
 */
-(void)routeChange:(NSNotification *)notif
{
    NSDictionary *info = notif.userInfo;
    int changeReason= [info[AVAudioSessionRouteChangeReasonKey] intValue];
    //等于AVAudioSessionRouteChangeReasonOldDeviceUnavailable表示旧输出不可用
    if (changeReason==AVAudioSessionRouteChangeReasonOldDeviceUnavailable) {
        AVAudioSessionRouteDescription *routeDescription=info[AVAudioSessionRouteChangePreviousRouteKey];
        AVAudioSessionPortDescription *portDescription= [routeDescription.outputs firstObject];
        //原设备为耳机则暂停
        if ([portDescription.portType isEqualToString:@"Headphones"]) {
            [_audioPlayer pause];
            //暂停定时器，不能使用invalidate方法，此方法是将定时器损毁，之后不能回复
            _timer.fireDate = [NSDate distantFuture];
            _playOrPauseButton.backgroundColor = [UIColor blueColor];
        }
    }
}
-(AVAudioPlayer *)audioPlayer
{
    if (!_audioPlayer) {
        NSString *filePath = [[NSBundle mainBundle]pathForResource:@"陈姿彤-我的世界.mp3" ofType:nil];
        NSURL *fileUrl = [NSURL fileURLWithPath:filePath];
        NSError *error = nil ;
        //1.初始化播放器，这里的URL参数只能是文件路径，不支持HTTP URL
        _audioPlayer = [[AVAudioPlayer alloc]initWithContentsOfURL:fileUrl error:&error];
        //2.设置播放器属性
        _audioPlayer.numberOfLoops = 0 ;//设置为0为不循环
        _audioPlayer.delegate = self ;
        [_audioPlayer prepareToPlay];
        
        //设置后台播放模式
        AVAudioSession *audioSession=[AVAudioSession sharedInstance];
        [audioSession setCategory:AVAudioSessionCategoryPlayback error:nil];
        [audioSession setActive:YES error:nil];
        
        //添加通知，拔出耳机后暂停播放
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(routeChange:) name:AVAudioSessionRouteChangeNotification object:nil];
        if (error) {
            NSLog(@"初始化播放器过程发生错误：%@",error.localizedDescription);
            return nil;
        }
        _timer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self selector:@selector(updateProgress) userInfo:nil repeats:YES];
        [_timer fire];
    }
    return _audioPlayer;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
