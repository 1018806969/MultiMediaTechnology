//
//  VideoRecordViewController.h
//  MultiMediaTechnology
//
//  Created by txx on 16/12/1.
//  Copyright © 2016年 txx. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VideoRecordViewController : UIViewController


//UIImagePickerController拍照和视频录制
//
//下面看一下在iOS如何拍照和录制视频。在iOS中要拍照和录制视频最简单的方法就是使用UIImagePickerController。UIImagePickerController继承于UINavigationController，前面的文章中主要使用它来选取照片，其实UIImagePickerController的功能不仅如此，它还可以用来拍照和录制视频。首先看一下这个类常用的属性和方法：
//
//属性	说明
//@property(nonatomic)           UIImagePickerControllerSourceType     sourceType	拾取源类型，sourceType是枚举类型：
//UIImagePickerControllerSourceTypePhotoLibrary：照片库
//，默认值
//UIImagePickerControllerSourceTypeCamera：摄像头
//UIImagePickerControllerSourceTypeSavedPhotosAlbum：相簿
//@property(nonatomic,copy)      NSArray                              *mediaTypes	媒体类型,默认情况下此数组包含kUTTypeImage，所以拍照时可以不用设置；但是当要录像的时候必须设置，可以设置为kUTTypeVideo（视频，但不带声音）或者kUTTypeMovie（视频并带有声音）
//@property(nonatomic)           NSTimeInterval                        videoMaximumDuration	视频最大录制时长，默认为10 s
//@property(nonatomic)           UIImagePickerControllerQualityType    videoQuality	视频质量，枚举类型：
//UIImagePickerControllerQualityTypeHigh：高清质量
//UIImagePickerControllerQualityTypeMedium：中等质量，适合WiFi传输
//UIImagePickerControllerQualityTypeLow：低质量，适合蜂窝网传输
//UIImagePickerControllerQualityType640x480：640*480
//UIImagePickerControllerQualityTypeIFrame1280x720：1280*720
//UIImagePickerControllerQualityTypeIFrame960x540：960*540
//@property(nonatomic)           BOOL                                  showsCameraControls	是否显示摄像头控制面板，默认为YES
//@property(nonatomic,retain)    UIView                                *cameraOverlayView	摄像头上覆盖的视图，可用通过这个视频来自定义拍照或录像界面
//@property(nonatomic)           CGAffineTransform                     cameraViewTransform	摄像头形变
//@property(nonatomic) UIImagePickerControllerCameraCaptureMode cameraCaptureMode	摄像头捕获模式，捕获模式是枚举类型：
//UIImagePickerControllerCameraCaptureModePhoto：拍照模式
//UIImagePickerControllerCameraCaptureModeVideo：视频录制模式
//@property(nonatomic) UIImagePickerControllerCameraDevice      cameraDevice	摄像头设备，cameraDevice是枚举类型：
//UIImagePickerControllerCameraDeviceRear：前置摄像头
//UIImagePickerControllerCameraDeviceFront：后置摄像头
//@property(nonatomic) UIImagePickerControllerCameraFlashMode   cameraFlashMode	闪光灯模式，枚举类型：
//UIImagePickerControllerCameraFlashModeOff：关闭闪光灯
//UIImagePickerControllerCameraFlashModeAuto：闪光灯自动
//UIImagePickerControllerCameraFlashModeOn：打开闪光灯
//类方法	说明
//+ (BOOL)isSourceTypeAvailable:(UIImagePickerControllerSourceType)sourceType	指定的源类型是否可用，sourceType是枚举类型：
//UIImagePickerControllerSourceTypePhotoLibrary：照片库
//UIImagePickerControllerSourceTypeCamera：摄像头
//UIImagePickerControllerSourceTypeSavedPhotosAlbum：相簿
//+ (NSArray *)availableMediaTypesForSourceType:(UIImagePickerControllerSourceType)sourceType	指定的源设备上可用的媒体类型，一般就是图片和视频
//+ (BOOL)isCameraDeviceAvailable:(UIImagePickerControllerCameraDevice)cameraDevice	指定的摄像头是否可用，cameraDevice是枚举类型：
//UIImagePickerControllerCameraDeviceRear：前置摄像头
//UIImagePickerControllerCameraDeviceFront：后置摄像头
//+ (BOOL)isFlashAvailableForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice	指定摄像头的闪光灯是否可用
//+ (NSArray *)availableCaptureModesForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice	获得指定摄像头上的可用捕获模式，捕获模式是枚举类型：
//UIImagePickerControllerCameraCaptureModePhoto：拍照模式
//UIImagePickerControllerCameraCaptureModeVideo：视频录制模式
//对象方法	说明
//- (void)takePicture	编程方式拍照
//- (BOOL)startVideoCapture	编程方式录制视频
//- (void)stopVideoCapture	编程方式停止录制视频
//代理方法	说明
//- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info	媒体拾取完成
//- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker	取消拾取
//扩展方法（主要用于保存照片、视频到相簿）	说明
//UIImageWriteToSavedPhotosAlbum(UIImage *image, id completionTarget, SEL completionSelector, void *contextInfo)	保存照片到相簿
//UIVideoAtPathIsCompatibleWithSavedPhotosAlbum(NSString *videoPath)	能否将视频保存到相簿
//void UISaveVideoAtPathToSavedPhotosAlbum(NSString *videoPath, id completionTarget, SEL completionSelector, void *contextInfo)	保存视频到相簿
//要用UIImagePickerController来拍照或者录制视频通常可以分为如下步骤：
//
//创建UIImagePickerController对象。
//指定拾取源，平时选择照片时使用的拾取源是照片库或者相簿，此刻需要指定为摄像头类型。
//指定摄像头，前置摄像头或者后置摄像头。
//设置媒体类型mediaType，注意如果是录像必须设置，如果是拍照此步骤可以省略，因为mediaType默认包含kUTTypeImage（注意媒体类型定义在MobileCoreServices.framework中）
//指定捕获模式，拍照或者录制视频。（视频录制时必须先设置媒体类型再设置捕获模式
//）
//展示UIImagePickerController(通常以模态窗口形式打开）。
//拍照和录制视频结束后在代理方法中展示/保存照片或视频。
//当然这个过程中有很多细节可以设置，例如是否显示拍照控制面板，拍照后是否允许编辑等等，通过上面的属性/方法列表相信并不难理解。下面就以一个示例展示如何使用UIImagePickerController来拍照和录制视频，下面的程序中只要将_isVideo设置为YES就是视频录制模式，录制完后在主视图控制器中自动播放；如果将_isVideo设置为NO则为拍照模式，拍照完成之后在主视图控制器中显示拍摄的照片：
@end
