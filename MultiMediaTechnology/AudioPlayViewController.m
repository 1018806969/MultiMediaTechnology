//
//  AudioPlayViewController.m
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

#import "AudioPlayViewController.h"
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#define SCREEN_W [UIScreen mainScreen].bounds.size.width
#define SCREEN_H [UIScreen mainScreen].bounds.size.height

@interface AudioPlayViewController ()<AVAudioPlayerDelegate>
@property(nonatomic,strong)AVAudioPlayer   *audioPlayer;
@property(nonatomic,strong)UIView          *controlView;
@property(nonatomic,strong)UIProgressView  *progressView;
@property(nonatomic,strong)UILabel         *singerLabel;
@property(nonatomic,strong)UIButton        *playOrPauseButton;
@property(nonatomic,strong)NSTimer         *timer;

@end

@implementation AudioPlayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Audio Play";
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    [self playMusic];

//    [self playSoundEffect:@"order.wav"];
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
        if (error) {
            NSLog(@"初始化播放器过程发生错误：%@",error.localizedDescription);
            return nil;
        }
        _timer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self selector:@selector(updateProgress) userInfo:nil repeats:YES];
        [_timer fire];
    }
    return _audioPlayer;
}


#pragma mark--------------------播放音效 AudioToolBox.framework-------------------
/**
 播放音效完成回调函数

 @param soundID 文件声音ID
 @param clientData 回调时传递的数据
 */
void soundCompleteCallback(SystemSoundID soundID,void * clientData){
    NSLog(@"play complete...%d...%@",soundID,clientData);
}
/**
 播放音效文件

 @param name 文件名
 */
-(void)playSoundEffect:(NSString *)name
{
    NSString *filePath = [[NSBundle mainBundle]pathForResource:name ofType:nil];
    NSURL *fileUrl = [NSURL fileURLWithPath:filePath];
    //1.获取系统声音ID
    SystemSoundID soundId = 0 ;
    /**
        此函数会将音效文件加入到系统音频服务中并返回一个长整形ID
     
     @param inFileURL#> 文件URL description#>
     @param outSystemSoundID#> 声音ID description#>
     */
    AudioServicesCreateSystemSoundID((__bridge CFURLRef)fileUrl, &soundId);
    
    //如果需要在播放完成之后执行某些操作，可以调用如下方法注册一个播放完成的回调函数
    AudioServicesAddSystemSoundCompletion(soundId, NULL, NULL, soundCompleteCallback, NULL);
    
    //2.播放音效
    AudioServicesPlaySystemSound(soundId);
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
