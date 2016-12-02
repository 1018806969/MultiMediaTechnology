//
//  PlayRomoteAudioViewController.h
//  MultiMediaTechnology
//
//  Created by txx on 16/12/2.
//  Copyright © 2016年 txx. All rights reserved.
//

//流媒体技术播放网上Audio

#import <UIKit/UIKit.h>

@interface PlayRomoteAudioViewController : UIViewController

//音频队列服务

//大家应该已经注意到了，无论是前面的录音还是音频播放均不支持网络流媒体播放，当然对于录音来说这种需求可能不大，但是对于音频播放来说有时候就很有必要了。AVAudioPlayer只能播放本地文件，并且是一次性加载所有音频数据，初始化AVAudioPlayer时指定的URL也只能是File URL而不能是HTTP URL。当然，将音频文件下载到本地然后再调用AVAudioPlayer来播放也是一种播放网络音频的办法，但是这种方式最大的弊端就是必须等到整个音频下载完成才能播放，而不能使用流式播放，这往往在实际开发中是不切实际的。
//那么在iOS中如何播放网络流媒体呢？就是使用AudioToolbox框架中的音频队列服务Audio Queue Services。
//使用音频队列服务完全可以做到音频播放和录制

//音频服务队列：






//当然，要明白音频队列服务的原理并不难，问题是如何实现这个自定义的回调函数，这其中我们有大量的工作要做，控制播放状态、处理异常中断、进行音频编码等等。由于牵扯内容过多，而且不是本文目的，如果以后有时间将另开一篇文章重点介绍，目前有很多第三方优秀框架可以直接使用，例如AudioStreamer、FreeStreamer。由于前者当前只有非ARC版本，所以下面不妨使用FreeStreamer来简单演示在线音频播放的过程，当然在使用之前要做如下准备工作：
//
//1.拷贝FreeStreamer中的Reachability.h、Reachability.m和Common、astreamer两个文件夹中的内容到项目中。
//
//2.添加FreeStreamer使用的类库：CFNetwork.framework、AudioToolbox.framework、AVFoundation.framework
//、libxml2.dylib、MediaPlayer.framework。
//
//3.如果引用libxml2.dylib编译不通过，需要在Xcode的Targets-Build Settings-Header Build Path中添加$(SDKROOT)/usr/include/libxml2。
//
//4.将FreeStreamer中的FreeStreamerMobile-Prefix.pch文件添加到项目中并将Targets-Build Settings-Precompile Prefix Header设置为YES，在Targets-Build Settings-Prefix Header设置为$(SRCROOT)/项目名称/FreeStreamerMobile-Prefix.pch（因为Xcode6默认没有pch文件）
//
//然后就可以编写代码播放网络音频了

//其实FreeStreamer的功能很强大，不仅仅是播放本地、网络音频那么简单，它还支持播放列表、检查包内容、RSS订阅、播放中断等很多强大的功能，甚至还包含了一个音频分析器，有兴趣的朋友可以访问官网查看详细用法





@end
