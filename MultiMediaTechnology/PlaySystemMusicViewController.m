//
//  PlaySystemMusicViewController.m
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

#import "PlaySystemMusicViewController.h"

#define SCREEN_W [UIScreen mainScreen].bounds.size.width
#define SCREEN_H [UIScreen mainScreen].bounds.size.height

@interface PlaySystemMusicViewController ()<MPMediaPickerControllerDelegate>


/**
 媒体选择控制器
 */
@property(nonatomic,strong)MPMediaPickerController *mediaPickerController;

/**
 音乐播放器
 */
@property(nonatomic,strong)MPMusicPlayerController *musicPlayerController;

@end

@implementation PlaySystemMusicViewController
-(void)dealloc
{
    [_musicPlayerController endGeneratingPlaybackNotifications];
}
- (void)viewDidLoad {
    [super viewDidLoad];
    [self layoutUI];
}
/**
 选择完成代理

 @param mediaPicker 媒体选择控制器
 @param mediaItemCollection 媒体项目集合
 */
-(void)mediaPicker:(MPMediaPickerController *)mediaPicker didPickMediaItems:(MPMediaItemCollection *)mediaItemCollection
{
    //第一个播放音乐
    MPMediaItem *mediaItem = [mediaItemCollection.items firstObject];
    //注意很多音乐信息如标题、专辑、表演者、封面、时长等信息都可以通过MPMediaItem的valueForKey:方法得到,
    //但是从iOS7开始都有对应的属性可以直接访问
    NSLog(@"标题：%@,表演者：%@,专辑：%@",mediaItem.title ,mediaItem.artist,mediaItem.albumTitle);
    
    [self.musicPlayerController setQueueWithItemCollection:mediaItemCollection];
    [self dismissViewControllerAnimated:YES completion:nil];
}
/**
 取消选择
 */
-(void)mediaPickerDidCancel:(MPMediaPickerController *)mediaPicker
{
    [self dismissViewControllerAnimated:YES completion:nil];
}
-(void)buttonClick:(UIButton *)button
{
    switch (button.tag) {
        case 0:{
            //select music
            [self presentViewController:self.mediaPickerController animated:YES completion:nil];
            break;
        }
        case 1:{
            
            break;
        }
        case 2:{
            
            break;
        }
        case 3:{
            
            break;
        }
        case 4:{
            
            break;
        }
        case 5:{
            
            break;
        }

        default:
            break;
    }
}
/**
 *  播放状态改变通知
 *
 *  @param notification 通知对象
 */
-(void)playbackStateChange:(NSNotification *)notification{
    switch (self.musicPlayerController.playbackState) {
        case MPMusicPlaybackStatePlaying:
            NSLog(@"正在播放...");
            break;
        case MPMusicPlaybackStatePaused:
            NSLog(@"播放暂停.");
            break;
        case MPMusicPlaybackStateStopped:
            NSLog(@"播放停止.");
            break;
        default:
            break;
    }
}
/**
 设计界面
 */
-(void)layoutUI
{
    self.view.backgroundColor = [UIColor whiteColor];
    NSArray *titles = @[@"select",@"play",@"pause",@"stop",@"next",@"pre"];
    for (int i = 0; i<6; i++) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        [button setTitle:titles[i] forState:UIControlStateNormal];
        button.frame = CGRectMake(50+90*(i%3),200+50*(i/3), 80, 40);
        button.backgroundColor = [UIColor grayColor];
        [button addTarget:self action:@selector(buttonClick:) forControlEvents:UIControlEventTouchUpInside];
        button.tag = i ;
        [self.view addSubview:button];
    }
}
/**
 *  取得媒体队列
 *
 *  @return 媒体队列
 */
-(MPMediaQuery *)getLocalMediaQuery{
    MPMediaQuery *mediaQueue=[MPMediaQuery songsQuery];
    for (MPMediaItem *item in mediaQueue.items) {
        NSLog(@"标题：%@,%@",item.title,item.albumTitle);
    }
    return mediaQueue;
}

/**
 *  取得媒体集合
 *
 *  @return 媒体集合
 */
-(MPMediaItemCollection *)getLocalMediaItemCollection{
    MPMediaQuery *mediaQueue=[MPMediaQuery songsQuery];
    NSMutableArray *array=[NSMutableArray array];
    for (MPMediaItem *item in mediaQueue.items) {
        [array addObject:item];
        NSLog(@"标题：%@,%@",item.title,item.albumTitle);
    }
    MPMediaItemCollection *mediaItemCollection=[[MPMediaItemCollection alloc]initWithItems:[array copy]];
    return mediaItemCollection;
}
/**
 创建媒体选择器

 @return 媒体选择器
 */
-(MPMediaPickerController *)mediaPickerController
{
    if (!_mediaPickerController) {
        //初始化媒体选择器，这里设置媒体类型为音乐，其实这里也可以选择视频、广播等
        _mediaPickerController = [[MPMediaPickerController alloc]initWithMediaTypes:MPMediaTypeMusic];
        // _mediaPicker=[[MPMediaPickerController alloc]initWithMediaTypes:MPMediaTypeAny];
        //允许多选
        _mediaPickerController.allowsPickingMultipleItems = YES ;
        //显示iCloud选项
//        _mediaPickerController.showsCloudItems = YES ;
        _mediaPickerController.prompt = @"请选择要播放的音乐";
        _mediaPickerController.delegate = self ;
    }
    return _mediaPickerController ;
}
/**
 获取音乐播放器

 @return 音乐播放器
 */
-(MPMusicPlayerController *)musicPlayerController
{
    if (!_musicPlayerController) {
        _musicPlayerController = [MPMusicPlayerController systemMusicPlayer];
        //开启通知，否则监控不到MPMusicPlayerController的通知
        [_musicPlayerController beginGeneratingPlaybackNotifications];
        
        //添加通知
        NSNotificationCenter *notificationCenter=[NSNotificationCenter defaultCenter];
        [notificationCenter addObserver:self selector:@selector(playbackStateChange:) name:MPMusicPlayerControllerPlaybackStateDidChangeNotification object:self.musicPlayerController];
        
        //如果不使用MPMediaPickerController可以使用如下方法获得音乐库媒体队列
        //[_musicPlayer setQueueWithItemCollection:[self getLocalMediaItemCollection]];

    }
    return _musicPlayerController;
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
