//
//  VideoPlayViewController.h
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//


//视频播放
#import <UIKit/UIKit.h>

@interface VideoPlayViewController : UIViewController


//在iOS中播放视频可以使用MediaPlayer.framework中的MPMoviePlayerController类来完成，它支持本地视频和网络视频播放。这个类实现了MPMediaPlayback协议，因此具备一般的播放器控制功能，例如播放、暂停、停止等。但是MPMediaPlayerController自身并不是一个完整的视图控制器，如果要在UI中展示视频需要将view属性添加到界面中。下面列出了MPMoviePlayerController的常用属性和方法：

//属性	说明
//@property (nonatomic, copy) NSURL *contentURL	播放媒体URL，这个URL可以是本地路径，也可以是网络路径
//@property (nonatomic, readonly) UIView *view	播放器视图，如果要显示视频必须将此视图添加到控制器视图中
//@property (nonatomic, readonly) UIView *backgroundView	播放器背景视图
//@property (nonatomic, readonly) MPMoviePlaybackState playbackState	媒体播放状态，枚举类型：
//MPMoviePlaybackStateStopped：停止播放
//MPMoviePlaybackStatePlaying：正在播放
//MPMoviePlaybackStatePaused：暂停
//MPMoviePlaybackStateInterrupted：中断
//MPMoviePlaybackStateSeekingForward：向前定位
//MPMoviePlaybackStateSeekingBackward：向后定位
//@property (nonatomic, readonly) MPMovieLoadState loadState	网络媒体加载状态，枚举类型：
//MPMovieLoadStateUnknown：位置类型
//MPMovieLoadStatePlayable：
//MPMovieLoadStatePlaythroughOK：这种状态如果shouldAutoPlay为YES将自动播放
//MPMovieLoadStateStalled：停滞状态
//@property (nonatomic) MPMovieControlStyle controlStyle	控制面板风格，枚举类型：
//MPMovieControlStyleNone：无控制面板
//MPMovieControlStyleEmbedded：嵌入视频风格
//MPMovieControlStyleFullscreen：全屏
//MPMovieControlStyleDefault：默认风格
//@property (nonatomic) MPMovieRepeatMode repeatMode;	重复播放模式，枚举类型:
//MPMovieRepeatModeNone:不重复，默认值
//MPMovieRepeatModeOne:重复播放
//@property (nonatomic) BOOL shouldAutoplay	当网络媒体缓存到一定数据时是否自动播放，默认为YES
//@property (nonatomic, getter=isFullscreen) BOOL fullscreen	是否全屏展示，默认为NO，注意如果要通过此属性设置全屏必须在视图显示完成后设置，否则无效
//@property (nonatomic) MPMovieScalingMode scalingMode	视频缩放填充模式，枚举类型：
//MPMovieScalingModeNone：不进行任何缩放
//MPMovieScalingModeAspectFit：固定缩放比例并且尽量全部展示视频，不会裁切视频
//MPMovieScalingModeAspectFill：固定缩放比例并填充满整个视图展示，可能会裁切视频
//MPMovieScalingModeFill：不固定缩放比例压缩填充整个视图，视频不会被裁切但是比例失衡
//@property (nonatomic, readonly) BOOL readyForDisplay	是否有相关媒体被播放
//@property (nonatomic, readonly) MPMovieMediaTypeMask movieMediaTypes	媒体类别，枚举类型：
//MPMovieMediaTypeMaskNone：未知类型
//MPMovieMediaTypeMaskVideo：视频
//MPMovieMediaTypeMaskAudio：音频
//@property (nonatomic) MPMovieSourceType movieSourceType	媒体源，枚举类型：
//MPMovieSourceTypeUnknown：未知来源
//MPMovieSourceTypeFile：本地文件
//MPMovieSourceTypeStreaming：流媒体（直播或点播）
//@property (nonatomic, readonly) NSTimeInterval duration	媒体时长，如果未知则返回0
//@property (nonatomic, readonly) NSTimeInterval playableDuration	媒体可播放时长，主要用于表示网络媒体已下载视频时长
//@property (nonatomic, readonly) CGSize naturalSize	视频实际尺寸，如果未知则返回CGSizeZero
//@property (nonatomic) NSTimeInterval initialPlaybackTime	起始播放时间
//@property (nonatomic) NSTimeInterval endPlaybackTime	终止播放时间
//@property (nonatomic) BOOL allowsAirPlay	是否允许无线播放，默认为YES
//@property (nonatomic, readonly, getter=isAirPlayVideoActive) BOOL airPlayVideoActive	当前媒体是否正在通过AirPlay播放
//@property(nonatomic, readonly) BOOL isPreparedToPlay	是否准备好播放
//@property(nonatomic) NSTimeInterval currentPlaybackTime	当前播放时间，单位：秒
//@property(nonatomic) float currentPlaybackRate	当前播放速度，如果暂停则为0，正常速度为1.0，非0数据表示倍率
//对象方法	说明
//- (instancetype)initWithContentURL:(NSURL *)url	使用指定的URL初始化媒体播放控制器对象
//- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated	设置视频全屏，注意如果要通过此方法设置全屏则必须在其视图显示之后设置，否则无效
//- (void)requestThumbnailImagesAtTimes:(NSArray *)playbackTimes timeOption:(MPMovieTimeOption)option	获取在指定播放时间的视频缩略图，第一个参数是获取缩略图的时间点数组；第二个参数代表时间点精度，枚举类型：
//MPMovieTimeOptionNearestKeyFrame：时间点附近
//MPMovieTimeOptionExact：准确时间
//- (void)cancelAllThumbnailImageRequests	取消所有缩略图获取请求
//- (void)prepareToPlay	准备播放，加载视频数据到缓存，当调用play方法时如果没有准备好会自动调用此方法
//- (void)play	开始播放
//- (void)pause	暂停播放
//- (void)stop	停止播放
//- (void)beginSeekingForward	向前定位
//- (void)beginSeekingBackward	向后定位
//- (void)endSeeking	停止快进/快退
//通知	说明
//MPMoviePlayerScalingModeDidChangeNotification	视频缩放填充模式发生改变
//MPMoviePlayerPlaybackDidFinishNotification	媒体播放完成或用户手动退出，具体完成原因可以通过通知userInfo中的key为MPMoviePlayerPlaybackDidFinishReasonUserInfoKey的对象获取
//MPMoviePlayerPlaybackStateDidChangeNotification	播放状态改变，可配合playbakcState属性获取具体状态
//MPMoviePlayerLoadStateDidChangeNotification	媒体网络加载状态改变
//MPMoviePlayerNowPlayingMovieDidChangeNotification	当前播放的媒体内容发生改变
//MPMoviePlayerWillEnterFullscreenNotification	将要进入全屏
//MPMoviePlayerDidEnterFullscreenNotification	进入全屏后
//MPMoviePlayerWillExitFullscreenNotification	将要退出全屏
//MPMoviePlayerDidExitFullscreenNotification	退出全屏后
//MPMoviePlayerIsAirPlayVideoActiveDidChangeNotification	当媒体开始通过AirPlay播放或者结束AirPlay播放
//MPMoviePlayerReadyForDisplayDidChangeNotification	视频显示状态改变
//MPMovieMediaTypesAvailableNotification	确定了媒体可用类型后
//MPMovieSourceTypeAvailableNotification	确定了媒体来源后
//MPMovieDurationAvailableNotification	确定了媒体播放时长后
//MPMovieNaturalSizeAvailableNotification	确定了媒体的实际尺寸后
//MPMoviePlayerThumbnailImageRequestDidFinishNotification	缩略图请求完成之后
//MPMediaPlaybackIsPreparedToPlayDidChangeNotification	做好播放准备后


//注意MPMediaPlayerController的状态等信息并不是通过代理来和外界交互的，而是通过通知中心，因此从上面的列表中可以看到常用的一些通知。由于MPMoviePlayerController本身对于媒体播放做了深度的封装，使用起来就相当简单：创建MPMoviePlayerController对象，设置frame属性，将MPMoviePlayerController的view添加到控制器视图中。下面的示例中将创建一个播放控制器并添加播放状态改变及播放完成的通知：


//从本vc大家也不难看出其实MPMoviePlayerController功能相当强大，日常开发中作为一般的媒体播放器也完全没有问题。MPMoviePlayerController除了一般的视频播放和控制外还有一些强大的功能，例如截取视频缩略图。请求视频缩略图时只要调用- (void)requestThumbnailImagesAtTimes:(NSArray *)playbackTimes timeOption:(MPMovieTimeOption)option方法指定获得缩略图的时间点，然后监控MPMoviePlayerThumbnailImageRequestDidFinishNotification通知，每个时间点的缩略图请求完成就会调用通知，在通知调用方法中可以通过MPMoviePlayerThumbnailImageKey获得UIImage对象处理即可。例如下面的程序演示了在程序启动后获得两个时间点的缩略图的过程，截图成功后保存到相册：


//扩展--使用AVFoundation生成缩略图
//
//通过前面的方法大家应该已经看到，使用MPMoviePlayerController来生成缩略图足够简单，但是如果仅仅是是为了生成缩略图而不进行视频播放的话，此刻使用MPMoviePlayerController就有点大材小用了。其实使用AVFundation框架中的AVAssetImageGenerator就可以获取视频缩略图。使用AVAssetImageGenerator获取缩略图大致分为三个步骤：
//
//创建AVURLAsset对象（此类主要用于获取媒体信息，包括视频、声音等）。
//根据AVURLAsset创建AVAssetImageGenerator对象。
//使用AVAssetImageGenerator的copyCGImageAtTime::方法获得指定时间点的截图。
////
////  ViewController.m
////  AVAssetImageGenerator
////
////  Created by Kenshin Cui on 14/03/30.
////  Copyright (c) 2014年 cmjstudio. All rights reserved.
////
//
//#import "ViewController.h"
//#import <AVFoundation/AVFoundation.h>
//
//@interface ViewController ()
//
//@end
//
//@implementation ViewController
//
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    
//    //获取第13.0s的缩略图
//    [self thumbnailImageRequest:13.0];
//}
//
//#pragma mark - 私有方法
///**
// *  取得本地文件路径
// *
// *  @return 文件路径
// */
//-(NSURL *)getFileUrl{
//    NSString *urlStr=[[NSBundle mainBundle] pathForResource:@"The New Look of OS X Yosemite.mp4" ofType:nil];
//    NSURL *url=[NSURL fileURLWithPath:urlStr];
//    return url;
//}
//
///**
// *  取得网络文件路径
// *
// *  @return 文件路径
// */
//-(NSURL *)getNetworkUrl{
//    NSString *urlStr=@"http://192.168.1.161/The New Look of OS X Yosemite.mp4";
//    urlStr=[urlStr stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
//    NSURL *url=[NSURL URLWithString:urlStr];
//    return url;
//}
//
///**
// *  截取指定时间的视频缩略图
// *
// *  @param timeBySecond 时间点
// */
//-(void)thumbnailImageRequest:(CGFloat )timeBySecond{
//    //创建URL
//    NSURL *url=[self getNetworkUrl];
//    //根据url创建AVURLAsset
//    AVURLAsset *urlAsset=[AVURLAsset assetWithURL:url];
//    //根据AVURLAsset创建AVAssetImageGenerator
//    AVAssetImageGenerator *imageGenerator=[AVAssetImageGenerator assetImageGeneratorWithAsset:urlAsset];
//    /*截图
//     * requestTime:缩略图创建时间
//     * actualTime:缩略图实际生成的时间
//     */
//    NSError *error=nil;
//    CMTime time=CMTimeMakeWithSeconds(timeBySecond, 10);//CMTime是表示电影时间信息的结构体，第一个参数表示是视频第几秒，第二个参数表示每秒帧数.(如果要活的某一秒的第几帧可以使用CMTimeMake方法)
//    CMTime actualTime;
//    CGImageRef cgImage= [imageGenerator copyCGImageAtTime:time actualTime:&actualTime error:&error];
//    if(error){
//        NSLog(@"截取视频缩略图时发生错误，错误信息：%@",error.localizedDescription);
//        return;
//    }
//    CMTimeShow(actualTime);
//    UIImage *image=[UIImage imageWithCGImage:cgImage];//转化为UIImage
//    //保存到相册
//    UIImageWriteToSavedPhotosAlbum(image,nil, nil, nil);
//    CGImageRelease(cgImage);
//}
//
//@end



//MPMoviePlayerViewController
//
//其实MPMoviePlayerController如果不作为嵌入视频来播放（例如在新闻中嵌入一个视频），通常在播放时都是占满一个屏幕的，特别是在iPhone、iTouch上。因此从iOS3.2以后苹果也在思考既然MPMoviePlayerController在使用时通常都是将其视图view添加到另外一个视图控制器中作为子视图，那么何不直接创建一个控制器视图内部创建一个MPMoviePlayerController属性并且默认全屏播放，开发者在开发的时候直接使用这个视图控制器。这个内部有一个MPMoviePlayerController的视图控制器就是MPMoviePlayerViewController，它继承于UIViewController。MPMoviePlayerViewController内部多了一个moviePlayer属性和一个带有url的初始化方法，同时它内部实现了一些作为模态视图展示所特有的功能，例如默认是全屏模式展示、弹出后自动播放、作为模态窗口展示时如果点击“Done”按钮会自动退出模态窗口等。在下面的示例中就不直接将播放器放到主视图控制器，而是放到一个模态视图控制器中，简单演示MPMoviePlayerViewController的使用。
//
////
////  ViewController.m
////  MPMoviePlayerViewController
////
////  Created by Kenshin Cui on 14/03/30.
////  Copyright (c) 2014年 cmjstudio. All rights reserved.
////  MPMoviePlayerViewController使用
//
//#import "ViewController.h"
//#import <MediaPlayer/MediaPlayer.h>
//
//@interface ViewController ()
//
////播放器视图控制器
//@property (nonatomic,strong) MPMoviePlayerViewController *moviePlayerViewController;
//
//@end
//
//@implementation ViewController
//
//#pragma mark - 控制器视图方法
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    
//}
//
//-(void)dealloc{
//    //移除所有通知监控
//    [[NSNotificationCenter defaultCenter] removeObserver:self];
//}
//
//
//#pragma mark - 私有方法
///**
// *  取得本地文件路径
// *
// *  @return 文件路径
// */
//-(NSURL *)getFileUrl{
//    NSString *urlStr=[[NSBundle mainBundle] pathForResource:@"The New Look of OS X Yosemite.mp4" ofType:nil];
//    NSURL *url=[NSURL fileURLWithPath:urlStr];
//    return url;
//}
//
///**
// *  取得网络文件路径
// *
// *  @return 文件路径
// */
//-(NSURL *)getNetworkUrl{
//    NSString *urlStr=@"http://192.168.1.161/The New Look of OS X Yosemite.mp4";
//    urlStr=[urlStr stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
//    NSURL *url=[NSURL URLWithString:urlStr];
//    return url;
//}
//
//-(MPMoviePlayerViewController *)moviePlayerViewController{
//    if (!_moviePlayerViewController) {
//        NSURL *url=[self getNetworkUrl];
//        _moviePlayerViewController=[[MPMoviePlayerViewController alloc]initWithContentURL:url];
//        [self addNotification];
//    }
//    return _moviePlayerViewController;
//}
//#pragma mark - UI事件
//- (IBAction)playClick:(UIButton *)sender {
//    self.moviePlayerViewController=nil;//保证每次点击都重新创建视频播放控制器视图，避免再次点击时由于不播放的问题
//    //    [self presentViewController:self.moviePlayerViewController animated:YES completion:nil];
//    //注意，在MPMoviePlayerViewController.h中对UIViewController扩展两个用于模态展示和关闭MPMoviePlayerViewController的方法，增加了一种下拉展示动画效果
//    [self presentMoviePlayerViewControllerAnimated:self.moviePlayerViewController];
//}
//
//#pragma mark - 控制器通知
///**
// *  添加通知监控媒体播放控制器状态
// */
//-(void)addNotification{
//    NSNotificationCenter *notificationCenter=[NSNotificationCenter defaultCenter];
//    [notificationCenter addObserver:self selector:@selector(mediaPlayerPlaybackStateChange:) name:MPMoviePlayerPlaybackStateDidChangeNotification object:self.moviePlayerViewController.moviePlayer];
//    [notificationCenter addObserver:self selector:@selector(mediaPlayerPlaybackFinished:) name:MPMoviePlayerPlaybackDidFinishNotification object:self.moviePlayerViewController.moviePlayer];
//    
//}
//
///**
// *  播放状态改变，注意播放完成时的状态是暂停
// *
// *  @param notification 通知对象
// */
//-(void)mediaPlayerPlaybackStateChange:(NSNotification *)notification{
//    switch (self.moviePlayerViewController.moviePlayer.playbackState) {
//        case MPMoviePlaybackStatePlaying:
//            NSLog(@"正在播放...");
//            break;
//        case MPMoviePlaybackStatePaused:
//            NSLog(@"暂停播放.");
//            break;
//        case MPMoviePlaybackStateStopped:
//            NSLog(@"停止播放.");
//            break;
//        default:
//            NSLog(@"播放状态:%li",self.moviePlayerViewController.moviePlayer.playbackState);
//            break;
//    }
//}
//
///**
// *  播放完成
// *
// *  @param notification 通知对象
// */
//-(void)mediaPlayerPlaybackFinished:(NSNotification *)notification{
//    NSLog(@"播放完成.%li",self.moviePlayerViewController.moviePlayer.playbackState);
//}
//
//@end
//这里需要强调一下，由于MPMoviePlayerViewController的初始化方法做了大量工作（例如设置URL、自动播放、添加点击Done完成的监控等），所以当再次点击播放弹出新的模态窗口的时如果不销毁之前的MPMoviePlayerViewController，那么新的对象就无法完成初始化，这样也就不能再次进行播放。


//AVPlayer
//
//MPMoviePlayerController足够强大，几乎不用写几行代码就能完成一个播放器，但是正是由于它的高度封装使得要自定义这个播放器变得很复杂，甚至是不可能完成。例如有些时候需要自定义播放器的样式，那么如果要使用MPMoviePlayerController就不合适了，如果要对视频有自由的控制则可以使用AVPlayer。AVPlayer存在于AVFoundation中，它更加接近于底层，所以灵活性也更强：
//
//AVFoundation_Framework
//
//AVPlayer本身并不能显示视频，而且它也不像MPMoviePlayerController有一个view属性。如果AVPlayer要显示必须创建一个播放器层AVPlayerLayer用于展示，播放器层继承于CALayer，有了AVPlayerLayer之添加到控制器视图的layer中即可。要使用AVPlayer首先了解一下几个常用的类：
//
//AVAsset：主要用于获取多媒体信息，是一个抽象类，不能直接使用。
//
//AVURLAsset：AVAsset的子类，可以根据一个URL路径创建一个包含媒体信息的AVURLAsset对象。
//
//AVPlayerItem：一个媒体资源管理对象，管理者视频的一些基本信息和状态，一个AVPlayerItem对应着一个视频资源。
//
//下面简单通过一个播放器来演示AVPlayer的使用，播放器的效果如下：
//
//AVPlayer_Thumbnail
//
//在这个自定义的播放器中实现了视频播放、暂停、进度展示和视频列表功能，下面将对这些功能一一介绍。
//
//首先说一下视频的播放、暂停功能，这也是最基本的功能，AVPlayer对应着两个方法play、pause来实现。但是关键问题是如何判断当前视频是否在播放，在前面的内容中无论是音频播放器还是视频播放器都有对应的状态来判断，但是AVPlayer却没有这样的状态属性，通常情况下可以通过判断播放器的播放速度来获得播放状态。如果rate为0说明是停止状态，1是则是正常播放状态。
//
//其次要展示播放进度就没有其他播放器那么简单了。在前面的播放器中通常是使用通知来获得播放器的状态，媒体加载状态等，但是无论是AVPlayer还是AVPlayerItem（AVPlayer有一个属性currentItem是AVPlayerItem类型，表示当前播放的视频对象）都无法获得这些信息。当然AVPlayerItem是有通知的，但是对于获得播放状态和加载状态有用的通知只有一个：播放完成通知AVPlayerItemDidPlayToEndTimeNotification。在播放视频时，特别是播放网络视频往往需要知道视频加载情况、缓冲情况、播放情况，这些信息可以通过KVO监控AVPlayerItem的status、loadedTimeRanges属性来获得。当AVPlayerItem的status属性为AVPlayerStatusReadyToPlay是说明正在播放，只有处于这个状态时才能获得视频时长等信息；当loadedTimeRanges的改变时（每缓冲一部分数据就会更新此属性）可以获得本次缓冲加载的视频范围（包含起始时间、本次加载时长），这样一来就可以实时获得缓冲情况。然后就是依靠AVPlayer的- (id)addPeriodicTimeObserverForInterval:(CMTime)interval queue:(dispatch_queue_t)queue usingBlock:(void (^)(CMTime time))block方法获得播放进度，这个方法会在设定的时间间隔内定时更新播放进度，通过time参数通知客户端。相信有了这些视频信息播放进度就不成问题了，事实上通过这些信息就算是平时看到的其他播放器的缓冲进度显示以及拖动播放的功能也可以顺利的实现。
//
//最后就是视频切换的功能，在前面介绍的所有播放器中每个播放器对象一次只能播放一个视频，如果要切换视频只能重新创建一个对象，但是AVPlayer却提供了- (void)replaceCurrentItemWithPlayerItem:(AVPlayerItem *)item方法用于在不同的视频之间切换（事实上在AVFoundation内部还有一个AVQueuePlayer专门处理播放列表切换，有兴趣的朋友可以自行研究，这里不再赘述）。
//
//下面附上代码：
//
////
////  ViewController.m
////  AVPlayer
////
////  Created by Kenshin Cui on 14/03/30.
////  Copyright (c) 2014年 cmjstudio. All rights reserved.
////
//
//#import "ViewController.h"
//#import <AVFoundation/AVFoundation.h>
//
//@interface ViewController ()
//
//@property (nonatomic,strong) AVPlayer *player;//播放器对象
//
//@property (weak, nonatomic) IBOutlet UIView *container; //播放器容器
//@property (weak, nonatomic) IBOutlet UIButton *playOrPause; //播放/暂停按钮
//@property (weak, nonatomic) IBOutlet UIProgressView *progress;//播放进度
//
//@end
//
//@implementation ViewController
//
//#pragma mark - 控制器视图方法
//- (void)viewDidLoad {
//    [super viewDidLoad];
//    [self setupUI];
//    [self.player play];
//}
//
//-(void)dealloc{
//    [self removeObserverFromPlayerItem:self.player.currentItem];
//    [self removeNotification];
//}
//
//#pragma mark - 私有方法
//-(void)setupUI{
//    //创建播放器层
//    AVPlayerLayer *playerLayer=[AVPlayerLayer playerLayerWithPlayer:self.player];
//    playerLayer.frame=self.container.frame;
//    //playerLayer.videoGravity=AVLayerVideoGravityResizeAspect;//视频填充模式
//    [self.container.layer addSublayer:playerLayer];
//}
//
///**
// *  截取指定时间的视频缩略图
// *
// *  @param timeBySecond 时间点
// */
//
///**
// *  初始化播放器
// *
// *  @return 播放器对象
// */
//-(AVPlayer *)player{
//    if (!_player) {
//        AVPlayerItem *playerItem=[self getPlayItem:0];
//        _player=[AVPlayer playerWithPlayerItem:playerItem];
//        [self addProgressObserver];
//        [self addObserverToPlayerItem:playerItem];
//    }
//    return _player;
//}
//
///**
// *  根据视频索引取得AVPlayerItem对象
// *
// *  @param videoIndex 视频顺序索引
// *
// *  @return AVPlayerItem对象
// */
//-(AVPlayerItem *)getPlayItem:(int)videoIndex{
//    NSString *urlStr=[NSString stringWithFormat:@"http://192.168.1.161/%i.mp4",videoIndex];
//    urlStr =[urlStr stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
//    NSURL *url=[NSURL URLWithString:urlStr];
//    AVPlayerItem *playerItem=[AVPlayerItem playerItemWithURL:url];
//    return playerItem;
//}
//#pragma mark - 通知
///**
// *  添加播放器通知
// */
//-(void)addNotification{
//    //给AVPlayerItem添加播放完成通知
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playbackFinished:) name:AVPlayerItemDidPlayToEndTimeNotification object:self.player.currentItem];
//}
//
//-(void)removeNotification{
//    [[NSNotificationCenter defaultCenter] removeObserver:self];
//}
//
///**
// *  播放完成通知
// *
// *  @param notification 通知对象
// */
//-(void)playbackFinished:(NSNotification *)notification{
//    NSLog(@"视频播放完成.");
//}
//
//#pragma mark - 监控
///**
// *  给播放器添加进度更新
// */
//-(void)addProgressObserver{
//    AVPlayerItem *playerItem=self.player.currentItem;
//    UIProgressView *progress=self.progress;
//    //这里设置每秒执行一次
//    [self.player addPeriodicTimeObserverForInterval:CMTimeMake(1.0, 1.0) queue:dispatch_get_main_queue() usingBlock:^(CMTime time) {
//        float current=CMTimeGetSeconds(time);
//        float total=CMTimeGetSeconds([playerItem duration]);
//        NSLog(@"当前已经播放%.2fs.",current);
//        if (current) {
//            [progress setProgress:(current/total) animated:YES];
//        }
//    }];
//}
//
///**
// *  给AVPlayerItem添加监控
// *
// *  @param playerItem AVPlayerItem对象
// */
//-(void)addObserverToPlayerItem:(AVPlayerItem *)playerItem{
//    //监控状态属性，注意AVPlayer也有一个status属性，通过监控它的status也可以获得播放状态
//    [playerItem addObserver:self forKeyPath:@"status" options:NSKeyValueObservingOptionNew context:nil];
//    //监控网络加载情况属性
//    [playerItem addObserver:self forKeyPath:@"loadedTimeRanges" options:NSKeyValueObservingOptionNew context:nil];
//}
//-(void)removeObserverFromPlayerItem:(AVPlayerItem *)playerItem{
//    [playerItem removeObserver:self forKeyPath:@"status"];
//    [playerItem removeObserver:self forKeyPath:@"loadedTimeRanges"];
//}
///**
// *  通过KVO监控播放器状态
// *
// *  @param keyPath 监控属性
// *  @param object  监视器
// *  @param change  状态改变
// *  @param context 上下文
// */
//-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context{
//    AVPlayerItem *playerItem=object;
//    if ([keyPath isEqualToString:@"status"]) {
//        AVPlayerStatus status= [[change objectForKey:@"new"] intValue];
//        if(status==AVPlayerStatusReadyToPlay){
//            NSLog(@"正在播放...，视频总长度:%.2f",CMTimeGetSeconds(playerItem.duration));
//        }
//    }else if([keyPath isEqualToString:@"loadedTimeRanges"]){
//        NSArray *array=playerItem.loadedTimeRanges;
//        CMTimeRange timeRange = [array.firstObject CMTimeRangeValue];//本次缓冲时间范围
//        float startSeconds = CMTimeGetSeconds(timeRange.start);
//        float durationSeconds = CMTimeGetSeconds(timeRange.duration);
//        NSTimeInterval totalBuffer = startSeconds + durationSeconds;//缓冲总长度
//        NSLog(@"共缓冲：%.2f",totalBuffer);
//        //
//    }
//}
//
//#pragma mark - UI事件
///**
// *  点击播放/暂停按钮
// *
// *  @param sender 播放/暂停按钮
// */
//- (IBAction)playClick:(UIButton *)sender {
//    //    AVPlayerItemDidPlayToEndTimeNotification
//    //AVPlayerItem *playerItem= self.player.currentItem;
//    if(self.player.rate==0){ //说明时暂停
//        [sender setImage:[UIImage imageNamed:@"player_pause"] forState:UIControlStateNormal];
//        [self.player play];
//    }else if(self.player.rate==1){//正在播放
//        [self.player pause];
//        [sender setImage:[UIImage imageNamed:@"player_play"] forState:UIControlStateNormal];
//    }
//}
//
//
///**
// *  切换选集，这里使用按钮的tag代表视频名称
// *
// *  @param sender 点击按钮对象
// */
//- (IBAction)navigationButtonClick:(UIButton *)sender {
//    [self removeNotification];
//    [self removeObserverFromPlayerItem:self.player.currentItem];
//    AVPlayerItem *playerItem=[self getPlayItem:sender.tag];
//    [self addObserverToPlayerItem:playerItem];
//    //切换视频
//    [self.player replaceCurrentItemWithPlayerItem:playerItem];
//    [self addNotification];
//}
//
//@end
//到目前为止无论是MPMoviePlayerController还是AVPlayer来播放视频都相当强大，但是它也存在着一些不可回避的问题，那就是支持的视频编码格式很有限：H.264、MPEG-4，扩展名（压缩格式）：.mp4、.mov、.m4v、.m2v、.3gp、.3g2等。但是无论是MPMoviePlayerController还是AVPlayer它们都支持绝大多数音频编码，所以大家如果纯粹是为了播放音乐的话也可以考虑使用这两个播放器。那么如何支持更多视频编码格式呢？目前来说主要还是依靠第三方框架，在iOS上常用的视频编码、解码框架有：VLC、ffmpeg， 具体使用方式今天就不再做详细介绍。
@end
