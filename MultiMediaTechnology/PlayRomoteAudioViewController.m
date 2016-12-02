//
//  PlayRomoteAudioViewController.m
//  MultiMediaTechnology
//
//  Created by txx on 16/12/2.
//  Copyright © 2016年 txx. All rights reserved.
//

#import "PlayRomoteAudioViewController.h"
#import "FSAudioStream.h"

@interface PlayRomoteAudioViewController ()

@property(nonatomic,strong)FSAudioStream *audioStream;


@end

@implementation PlayRomoteAudioViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"play remote";
    [self.audioStream play];
}
-(NSURL *)getFileUrl{
    NSString *urlStr=[[NSBundle mainBundle]pathForResource:@"陈姿彤-我的世界.mp3" ofType:nil];
    NSURL *url=[NSURL fileURLWithPath:urlStr];
    return url;
}
-(NSURL *)getNetworkUrl{
    NSString *urlStr=@"网络资源路径";
    NSURL *url=[NSURL URLWithString:urlStr];
    return url;
}
-(FSAudioStream *)audioStream
{
    if (!_audioStream) {
        NSURL *url = [self getFileUrl];
        _audioStream = [[FSAudioStream alloc]initWithUrl:url];
        _audioStream.onFailure = ^(FSAudioStreamError error,NSString *description){
            NSLog(@"播放过程发生错误，错误信息：%@",description);
        };
        _audioStream.onCompletion = ^{
            NSLog(@"播放完成");
        };
        //设置声音
        [_audioStream setVolume:0.5];
    }
    return _audioStream;
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
