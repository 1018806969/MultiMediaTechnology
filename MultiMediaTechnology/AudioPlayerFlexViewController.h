//
//  AudioPlayerFlexViewController.h
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//


//后台播放、音频会话、远程控制

#import <UIKit/UIKit.h>

@interface AudioPlayerFlexViewController : UIViewController

//1.设置退出到后台也可以播放：
//a.设置后台运行模式：在plist文件中添加Required background modes，并且设置item 0=App plays audio or streams audio/video using AirPlay（其实可以直接通过Xcode在Project Targets-Capabilities-Background Modes中设置）
//b.设置AVAudioSession的类型为AVAudioSessionCategoryPlayback并且调用setActive::方法启动会话。
//AVAudioSession *audioSession=[AVAudioSession sharedInstance];
//[audioSession setCategory:AVAudioSessionCategoryPlayback error:nil];
//[audioSession setActive:YES error:nil];
//c.为了能够让应用退到后台之后支持耳机控制，可以添加远程控制事件http://www.cnblogs.com/kenshincui/p/3950646.html#remoteControl

//音频会话：
//前两步是后台播放所必须设置的，第三步主要用于接收远程事件，如果这一步不设置虽然也能够在后台播放，但是无法获得音频控制权（如果在使用当前应用之前使用其他播放器播放音乐的话，此时如果按耳机播放键或者控制中心的播放按钮则会播放前一个应用的音频），并且不能使用耳机进行音频控制。第一步操作相信大家都很容易理解，如果应用程序要允许运行到后台必须设置，正常情况下应用如果进入后台会被挂起，通过该设置可以上应用程序继续在后台运行。但是第二步使用的AVAudioSession有必要进行一下详细的说明：                                           在iOS中每个应用都有一个音频会话，这个会话就通过AVAudioSession来表示。AVAudioSession同样存在于AVFoundation框架中，它是单例模式设计，通过sharedInstance进行访问。在使用Apple设备时大家会发现有些应用只要打开其他音频播放就会终止，而有些应用却可以和其他应用同时播放，在多种音频环境中如何去控制播放的方式就是通过音频会话来完成的。下面是音频会话的几种会话模式：
//会话类型	                            说明	     是否要求输入	   是否要求输出	是否遵从静音键
//AVAudioSessionCategoryAmbient	        混音播放，可以与其他音频应用同时播放	   否	是	 是
//AVAudioSessionCategorySoloAmbient	    独占播放	                           否	是	 是
//AVAudioSessionCategoryPlayback	    后台播放，也是独占的	                 否	 是	 否
//AVAudioSessionCategoryRecord	        录音模式，用于录音时使用	                 是  否   否
//AVAudioSessionCategoryPlayAndRecord	播放和录音，此时可以录音也可以播放        	 是	 是	 否
//AVAudioSessionCategoryAudioProcessing	硬件解码音频，此时不能播放和录制	         否	 否	 否
//AVAudioSessionCategoryMultiRoute	    多种输入输出，例如可以耳机、USB设备同时播放	 是	 是	 否
//是否遵循静音键表示在播放过程中如果用户通过硬件设置为静音是否能关闭声音。

//如果一个应用已经在播放音频，打开我们的应用之后设置了在后台播放的会话类型，此时其他应用的音频会停止而播放我们的音频，如果希望我们的程序音频播放完之后（关闭或退出到后台之后）能够继续播放其他应用的音频的话则可以调用setActive::方法关闭会话

//此vc还实现了拔出耳机暂停音乐播放的功能，这也是一个比较常见的功能。在iOS7及以后的版本中可以通过通知获得输出改变的通知，然后拿到通知对象后根据userInfo获得是何种改变类型，进而根据情况对音乐进行暂停操作。


@end
