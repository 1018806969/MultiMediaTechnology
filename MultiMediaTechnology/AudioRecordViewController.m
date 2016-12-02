//
//  AudioRecordViewController.m
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

#import "AudioRecordViewController.h"
#import <AVFoundation/AVFoundation.h>

#define SCREEN_W [UIScreen mainScreen].bounds.size.width
#define SCREEN_H [UIScreen mainScreen].bounds.size.height

@interface AudioRecordViewController ()<AVAudioRecorderDelegate>

@property(nonatomic,strong)AVAudioRecorder *audioRecorder;
@property(nonatomic,strong)AVAudioPlayer   *audioPlayer;
@property(nonatomic,strong)NSTimer         *timer;
@property(nonatomic,strong)UIButton        *startButton;
@property(nonatomic,strong)UIButton        *playOrPauseButton;
@property(nonatomic,strong)UIButton        *stopButton;
/**
 录音时的音频波动
 */
@property(nonatomic,strong)UIProgressView  *progressView;

@end

@implementation AudioRecordViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self layoutUI];
    [self setAudioSession];
    
}
-(void)buttonClick:(UIButton *)button
{
    switch (button.tag) {
        case 0:{
            if (![self.audioRecorder isRecording]) {
                //首次使用应用时如果调用record方法会询问用户是否允许使用麦克风，在iOS10之后需要在info.plist文件中添加隐私询问，否则会crash
                [self.audioRecorder record];
                self.timer.fireDate=[NSDate distantPast];
            }
            break;
        }
        case 1:{
            if ([self.audioRecorder isRecording]) {
                [self.audioRecorder pause];
                self.timer.fireDate=[NSDate distantFuture];
            }else
            {
                //恢复录音只需要再次调用record，AVAudioSession会帮助你记录上次录音位置并追加录音
                [self.audioRecorder record];
                self.timer.fireDate=[NSDate distantPast];
            }
            break;
        }
        case 2:{
            [self.audioRecorder stop];
            self.timer.fireDate=[NSDate distantFuture];
            self.progressView.progress=0.0;
            break;
        }
        default:
            break;
    }
}
-(void)updateProgress
{
    [self.audioRecorder updateMeters];//更新测量值
    float power= [self.audioRecorder averagePowerForChannel:0];//取得第一个通道的音频，注意音频强度范围时-160到0
    CGFloat progress=(1.0/160.0)*(power+160.0);
    [self.progressView setProgress:progress];
}
/**
 录音完成的代理方法，默认录音完成之后播放录音

 @param recorder 录音对象
 @param flag 是否成功
 */
-(void)audioRecorderDidFinishRecording:(AVAudioRecorder *)recorder successfully:(BOOL)flag
{
    if (![self.audioPlayer isPlaying]) {
        [self.audioPlayer play];
    }
    NSLog(@"录音完成");
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}



-(NSTimer *)timer
{
    if (!_timer) {
        _timer = [NSTimer scheduledTimerWithTimeInterval:0.1 target:self selector:@selector(updateProgress) userInfo:nil repeats:YES];
    }
    return _timer ;
}
/**
 *  创建播放器
 *
 *  @return 播放器
 */
-(AVAudioPlayer *)audioPlayer{
    if (!_audioPlayer) {
        NSURL *url=[self getSaveUrl];
        NSError *error=nil;
        _audioPlayer=[[AVAudioPlayer alloc]initWithContentsOfURL:url error:&error];
        _audioPlayer.numberOfLoops=0;
        [_audioPlayer prepareToPlay];
        if (error) {
            NSLog(@"创建播放器过程中发生错误，错误信息：%@",error.localizedDescription);
            return nil;
        }
    }
    return _audioPlayer;
}/**
 录音对象创建

 */
-(AVAudioRecorder *)audioRecorder
{
    if (!_audioRecorder) {
        NSURL *url = [self getSaveUrl];
        NSDictionary *setting = [self recordSetting];
        NSError *error = nil;
        _audioRecorder = [[AVAudioRecorder alloc]initWithURL:url settings:setting error:&error];
        _audioRecorder.delegate = self;
        //如果要监控声波则必须设置为YES
        _audioRecorder.meteringEnabled = YES;
        if (error) {
            NSLog(@"创建录音机对象时发生错误：%@",error.localizedDescription);
        }
    }
    return _audioRecorder;
}
/**
 设置音频会话
 */
-(void)setAudioSession
{
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    [audioSession setCategory:AVAudioSessionCategoryRecord error:nil];
    [audioSession setActive:YES error:nil];
}
-(void)layoutUI
{
    self.view.backgroundColor = [UIColor whiteColor];
    NSArray *titles = @[@"begin",@"pOrP",@"stop"];
    for (int i = 0; i<3; i++) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        [button setTitle:titles[i] forState:UIControlStateNormal];
        button.frame = CGRectMake(50+80*(i%3),300, 70, 40);
        button.backgroundColor = [UIColor grayColor];
        [button addTarget:self action:@selector(buttonClick:) forControlEvents:UIControlEventTouchUpInside];
        button.tag = i ;
        [self.view addSubview:button];
    }
}
/**
 录音文件设置

 @return dic
 */
-(NSDictionary *)recordSetting
{
    NSMutableDictionary *dicM = [NSMutableDictionary dictionary];
    //设置录音格式
    [dicM setObject:@(kAudioFormatLinearPCM) forKey:AVFormatIDKey];
    //设置录音采样率，8000是电话采样率，对于一般录音已经够了
    [dicM setObject:@(8000) forKey:AVSampleRateKey];
    //设置通道,这里采用单声道
    [dicM setObject:@(1) forKey:AVNumberOfChannelsKey];
    //每个采样点位数,分为8、16、24、32
    [dicM setObject:@(8) forKey:AVLinearPCMBitDepthKey];
    //是否使用浮点数采样
    [dicM setObject:@(YES) forKey:AVLinearPCMIsFloatKey];
    //....其他设置等
    return dicM;
}
-(UIProgressView *)progressView
{
    if (!_progressView) {
        _progressView = [[UIProgressView alloc]initWithFrame:CGRectMake(0, 200, SCREEN_W, 20)];
        _progressView.progress = 0 ;
        [self.view addSubview:_progressView];
    }
    return _progressView ;
}
/**
 录音文件保存路径

 @return URL
 */
-(NSURL *)getSaveUrl
{
    NSString *path = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/record.caf"];
    NSLog(@"path=%@",path);
    NSURL *url = [NSURL fileURLWithPath:path];
    return url;
}
@end
