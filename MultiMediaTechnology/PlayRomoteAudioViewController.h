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









@end
