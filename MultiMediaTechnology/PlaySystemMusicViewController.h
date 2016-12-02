//
//  PlaySystemMusicViewController.h
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//


//播放音乐库中的音乐

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

@interface PlaySystemMusicViewController : UIViewController

//众所周知音乐是iOS的重要组成播放，无论是iPod、iTouch、iPhone还是iPad都可以在iTunes购买音乐或添加本地音乐到音乐库中同步到你的iOS设备。在MediaPlayer.frameowork中有一个MPMusicPlayerController用于播放音乐库中的音乐。



//MPMusicPlayerController常用的属性和方法
//@property (nonatomic, readonly) MPMusicPlaybackState playbackState
//播放器状态，枚举类型：
//MPMusicPlaybackStateStopped：停止播放 MPMusicPlaybackStatePlaying：正在播放
//MPMusicPlaybackStatePaused：暂停播放
//MPMusicPlaybackStateInterrupted：播放中断
//MPMusicPlaybackStateSeekingForward：向前查找
//MPMusicPlaybackStateSeekingBackward：向后查找
//@property (nonatomic) MPMusicRepeatMode repeatMode	重复模式，枚举类型：
//MPMusicRepeatModeDefault：默认模式，使用用户的首选项（系统音乐程序设置）
//MPMusicRepeatModeNone：不重复
//MPMusicRepeatModeOne：单曲循环
//MPMusicRepeatModeAll：在当前列表内循环
//@property (nonatomic) MPMusicShuffleMode shuffleMode	随机播放模式，枚举类型：
//MPMusicShuffleModeDefault：默认模式，使用用户首选项（系统音乐程序设置）
//MPMusicShuffleModeOff：不随机播放
//MPMusicShuffleModeSongs：按歌曲随机播放
//MPMusicShuffleModeAlbums：按专辑随机播放
//@property (nonatomic, copy) MPMediaItem *nowPlayingItem	正在播放的音乐项
//@property (nonatomic, readonly) NSUInteger indexOfNowPlayingItem	当前正在播放的音乐在播放队列中的索引
//@property(nonatomic, readonly) BOOL isPreparedToPlay	是否准好播放准备
//@property(nonatomic) NSTimeInterval currentPlaybackTime	当前已播放时间，单位：秒
//@property(nonatomic) float currentPlaybackRate	当前播放速度，是一个播放速度倍率，0表示暂停播放，1代表正常速度
//类方法	说明
//+ (MPMusicPlayerController *)applicationMusicPlayer;	获取应用播放器，注意此类播放器无法在后台播放
//+ (MPMusicPlayerController *)systemMusicPlayer	获取系统播放器，支持后台播放
//对象方法	说明
//- (void)setQueueWithQuery:(MPMediaQuery *)query	使用媒体队列设置播放源媒体队列
//- (void)setQueueWithItemCollection:(MPMediaItemCollection *)itemCollection	使用媒体项集合设置播放源媒体队列
//- (void)skipToNextItem	下一曲
//- (void)skipToBeginning	从起始位置播放
//- (void)skipToPreviousItem	上一曲
//- (void)beginGeneratingPlaybackNotifications	开启播放通知，注意不同于其他播放器，MPMusicPlayerController要想获得通知必须首先开启，默认情况无法获得通知
//- (void)endGeneratingPlaybackNotifications	关闭播放通知
//- (void)prepareToPlay	做好播放准备（加载音频到缓冲区），在使用play方法播放时如果没有做好准备回自动调用该方法
//- (void)play	开始播放
//- (void)pause	暂停播放
//- (void)stop	停止播放
//- (void)beginSeekingForward	开始向前查找（快进）
//- (void)beginSeekingBackward	开始向后查找（快退）
//- (void)endSeeking	结束查找
//通知	说明
//（注意：要想获得MPMusicPlayerController通知必须首先调用beginGeneratingPlaybackNotifications开启通知）
//MPMusicPlayerControllerPlaybackStateDidChangeNotification	播放状态改变
//MPMusicPlayerControllerNowPlayingItemDidChangeNotification	当前播放音频改变
//MPMusicPlayerControllerVolumeDidChangeNotification	声音大小改变
//MPMediaPlaybackIsPreparedToPlayDidChangeNotification	准备好播放



//MPMusicPlayerController有两种播放器：applicationMusicPlayer和systemMusicPlayer，前者在应用退出后音乐播放会自动停止，后者在应用停止后不会退出播放状态。
//MPMusicPlayerController加载音乐不同于前面的AVAudioPlayer是通过一个文件路径来加载，而是需要一个播放队列。在MPMusicPlayerController中提供了两个方法来加载播放队列：- (void)setQueueWithQuery:(MPMediaQuery *)query和- (void)setQueueWithItemCollection:(MPMediaItemCollection *)itemCollection，正是由于它的播放音频来源是一个队列，因此MPMusicPlayerController支持上一曲、下一曲等操作。
//那么接下来的问题就是如何获取MPMediaQueue或者MPMediaItemCollection？MPMediaQueue对象有一系列的类方法来获得媒体队列：
//+ (MPMediaQuery *)albumsQuery;
//+ (MPMediaQuery *)artistsQuery;
//+ (MPMediaQuery *)songsQuery;
//+ (MPMediaQuery *)playlistsQuery;
//+ (MPMediaQuery *)podcastsQuery;
//+ (MPMediaQuery *)audiobooksQuery;
//+ (MPMediaQuery *)compilationsQuery;
//+ (MPMediaQuery *)composersQuery;
//+ (MPMediaQuery *)genresQuery;
//有了这些方法，就可以很容易获到歌曲、播放列表、专辑媒体等媒体队列了，这样就可以通过：- (void)setQueueWithQuery:(MPMediaQuery *)query方法设置音乐来源了。又或者得到MPMediaQueue之后创建MPMediaItemCollection，使用- (void)setQueueWithItemCollection:(MPMediaItemCollection *)itemCollection设置音乐来源。
//有时候可能希望用户自己来选择要播放的音乐，这时可以使用MPMediaPickerController，它是一个视图控制器，类似于UIImagePickerController，选择完播放来源后可以在其代理方法中获得MPMediaItemCollection对象。
//无论是通过哪种方式获得MPMusicPlayerController的媒体源，可能都希望将每个媒体的信息显示出来，这时候可以通过MPMediaItem对象获得。一个MPMediaItem代表一个媒体文件，通过它可以访问媒体标题、专辑名称、专辑封面、音乐时长等等。无论是MPMediaQueue还是MPMediaItemCollection都有一个items属性，它是MPMediaItem数组，通过这个属性可以获得MPMediaItem对象。

//此vc简单看一下MPMusicPlayerController的使用，在下面的例子中简单演示了音乐的选择、播放、暂停、通知、下一曲、上一曲功能，相信有了上面的概念，代码读起来并不复杂（示例中是直接通过MPMeidaPicker进行音乐选择的，但是仍然提供了两个方法getLocalMediaQuery和getLocalMediaItemCollection来演示如何直接通过MPMediaQueue获得媒体队列或媒体集合）：


@end
