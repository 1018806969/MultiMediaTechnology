//
//  AudioRecordViewController.h
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

//录音

#import <UIKit/UIKit.h>

@interface AudioRecordViewController : UIViewController

//在AVFoundation框架中还有一个AVAudioRecorder类专门处理录音操作，它同样支持多种音频格式。与AVAudioPlayer类似，你完全可以将它看成是一个录音机控制类，下面是常用的属性和方法：

//属性	说明
//@property(readonly, getter=isRecording) BOOL recording;	是否正在录音，只读
//@property(readonly) NSURL *url	录音文件地址，只读
//@property(readonly) NSDictionary *settings	录音文件设置，只读
//@property(readonly) NSTimeInterval currentTime	录音时长，只读，注意仅仅在录音状态可用
//@property(readonly) NSTimeInterval deviceCurrentTime	输入设置的时间长度，只读，注意此属性一直可访问
//@property(getter=isMeteringEnabled) BOOL meteringEnabled;	是否启用录音测量，如果启用录音测量可以获得录音分贝等数据信息
//@property(nonatomic, copy) NSArray *channelAssignments	当前录音的通道

//对象方法	说明
//- (instancetype)initWithURL:(NSURL *)url settings:(NSDictionary *)settings error:(NSError **)outError	录音机对象初始化方法，注意其中的url必须是本地文件url，settings是录音格式、编码等设置
//- (BOOL)prepareToRecord	准备录音，主要用于创建缓冲区，如果不手动调用，在调用record录音时也会自动调用
//- (BOOL)record	开始录音
//- (BOOL)recordAtTime:(NSTimeInterval)time	在指定的时间开始录音，一般用于录音暂停再恢复录音
//- (BOOL)recordForDuration:(NSTimeInterval) duration	按指定的时长开始录音
//- (BOOL)recordAtTime:(NSTimeInterval)time forDuration:(NSTimeInterval) duration	在指定的时间开始录音，并指定录音时长
//- (void)pause;	暂停录音
//- (void)stop;	停止录音
//- (BOOL)deleteRecording;	删除录音，注意要删除录音此时录音机必须处于停止状态
//- (void)updateMeters;	更新测量数据，注意只有meteringEnabled为YES此方法才可用
//- (float)peakPowerForChannel:(NSUInteger)channelNumber;	指定通道的测量峰值，注意只有调用完updateMeters才有值
//- (float)averagePowerForChannel:(NSUInteger)channelNumber	指定通道的测量平均值，注意只有调用完updateMeters才有值

//代理方法	说明
//- (void)audioRecorderDidFinishRecording:(AVAudioRecorder *)recorder successfully:(BOOL)flag	完成录音
//- (void)audioRecorderEncodeErrorDidOccur:(AVAudioRecorder *)recorder error:(NSError *)error	录音编码发生错误


//AVAudioRecorder很多属性和方法跟AVAudioPlayer都是类似的,但是它的创建有所不同，在创建录音机时除了指定路径外还必须指定录音设置信息，因为录音机必须知道录音文件的格式、采样率、通道数、每个采样点的位数等信息，但是也并不是所有的信息都必须设置，通常只需要几个常用设置。关于录音设置详见帮助文档中的“AV Foundation Audio Settings Constants”https://developer.apple.com/reference/avfoundation/1668872-av_foundation_audio_settings_con。

//此vc就使用AVAudioRecorder创建一个录音机，实现了录音、暂停、停止、播放等功能，实现效果大致如下：
//在这个示例中将实行一个完整的录音控制，包括录音、暂停、恢复、停止，同时还会实时展示用户录音的声音波动，当用户点击完停止按钮还会自动播放录音文件。程序的构建主要分为以下几步：
//1.设置音频会话类型为AVAudioSessionCategoryPlayAndRecord，因为程序中牵扯到录音和播放操作。
//2.创建录音机AVAudioRecorder，指定录音保存的路径并且设置录音属性，注意对于一般的录音文件要求的采样率、位数并不高，需要适当设置以保证录音文件的大小和效果。
//3.设置录音机代理以便在录音完成后播放录音，打开录音测量保证能够实时获得录音时的声音强度。（注意声音强度范围-160到0,0代表最大输入）
//4.创建音频播放器AVAudioPlayer，用于在录音完成之后播放录音。
//5.创建一个定时器以便实时刷新录音测量值并更新录音强度到UIProgressView中显示。
//6.添加录音、暂停、恢复、停止操作，需要注意录音的恢复操作其实是有音频会话管理的，恢复时只要再次调用record方法即可，无需手动管理恢复时间等。




@end
