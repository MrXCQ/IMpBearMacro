//
//  Created by IMpBear on 2018/3/10.
//  Copyright © 2018年 IMpBear. All rights reserved.
//
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  佛祖镇楼                  BUG辟易
//          佛曰:
//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？

#ifndef ChompAPI_h
#define ChompAPI_h

/**
 iPad Air {{0, 0}, {768, 1024}}
 iphone4s {{0, 0}, {320, 480}}     960*640
 iphone5 5s {{0, 0}, {320, 568}}      1136*640
 iphone6 6s {{0, 0}, {375, 667}}     1334*750
 iphone6Plus 6sPlus {{0, 0}, {414, 736}}  1920*1080
 Apple Watch 1.65英寸 320*640
 */

// 控件或机型尺寸
#define NavigationBarHeight 44
#define StatusBarHeight 20
#define TopBarHeight 64
#define ToolBarHeight 44
#define TabBarHeight 49

#define iPhone4_W 320
#define iPhone4_H 480
#define iPhone5_W 320
#define iPhone5_H 568
#define iPhone6_W 375
#define iPhone6_H 667
#define iPhone6P_W 414
#define iPhone6P_H 736

// 判断是真机还是模拟器
#define IS_IPHONE                                  ([[[UIDevice currentDevice] model] isEqualToString: @"iPhone"] || [[[UIDevice currentDevice] model] isEqualToString: @"iPhone Simulator"])
#define IS_IPOD                                    ([[[UIDevice currentDevice] model] isEqualToString: @"iPod touch"])
#define IS_PAD                                     (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_5                                (IS_IPHONE && IS_WIDESCREEN_5)
#define IS_IPHONE_6                                (IS_IPHONE && IS_WIDESCREEN_6)
#define IS_IPHONE_6Plus                            (IS_IPHONE && IS_WIDESCREEN_6Plus)

#define ScreenMargin 16
#define Bit 1024
#define DefaultFontSize 17

/** 弱指针*/
#define XCQ_WeakSelf(weakSelf) __weak __typeof(&*self)weakSelf = self;

/** 加载本地文件*/
#define XCQ_LoadImage(file,type) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define XCQ_LoadArray(file,type) [NSArray arrayWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]
#define XCQ_LoadDict(file,type) [NSDictionary dictionaryWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]]

/** 快速进入一个bundle的宏*/
#define XCQ_Bundle(bundleName) [NSBundle bundleWithURL:[[NSBundle mainBundle] URLForResource:(bundleName) withExtension:@"bundle"]]
/** 加载bundle内nib或图片*/
// 这里返回的是一个nib内的元素
#define XCQ_LoadBundleNib(bundleName,nibName,index) [XCQ_Bundle(bundleName) loadNibNamed:(nibName) owner:nil options:nil][(index)];
// 这里返回的是包装后的图片名
#define XCQ_BundleImgName(bundleName,iconName) (iconName)?[[NSString stringWithFormat:@"%@.bundle/",((bundleName))] stringByAppendingString:(iconName)]:(iconName)

/** 裁切图片的宏*/
#define MTBStretchImg(image) [(image) stretchableImageWithLeftCapWidth:(image.size.width/3.0) topCapHeight:image.size.height/3.0]?:[UIImage new]
#define MTBStretchImgCustom(image,w,h) [(image) stretchableImageWithLeftCapWidth:(image.size.width*(w)) topCapHeight:image.size.height*(h)]?:[UIImage new]

/** 多线程GCD*/
#define XCQ_GlobalGCD(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define XCQ_MainGCD(block) dispatch_async(dispatch_get_main_queue(),block)

/** 数据存储*/
#define kXCQ_UserDefaults [NSUserDefaults standardUserDefaults]
#define kXCQ_CacheDir [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]
#define kXCQ_DocumentDir [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
#define kXCQ_TempDir NSTemporaryDirectory()


// 保存到plist文件
#define WriteToPlist(dic,s) [dic writeToFile:filePath(s) atomically:YES];
// 读取plist文件到字典
#define ReadToPlist(s) [[[NSMutableDictionary alloc] initWithContentsOfFile:filePath(s)] mutableCopy]


/** 非空block，把block和参数都写好，如果block不为空才执行*/
#define XCQ_NotNilBlock(block, ...) if (block) { block(__VA_ARGS__); };

/** 获取相机权限状态（一般是直接用下面两个 拒绝或同意）*/
#define XCQ_CameraStatus [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo]
#define XCQ_CameraDenied ((XCQ_CameraStatus == AVAuthorizationStatusRestricted)||(XCQ_CameraStatus == AVAuthorizationStatusDenied))
#define XCQ_CameraAllowed (!XCQ_CameraDenyed)

/** 定位权限*/
#define XCQ_LocationStatus [CLLocationManager authorizationStatus];
#define XCQ_LocationAllowed ([CLLocationManager locationServicesEnabled] && !((status == kCLAuthorizationStatusDenied) || (status == kCLAuthorizationStatusRestricted)))
#define XCQ_LocationDenied (!XCQ_LocationAllowed)

/** 消息推送权限*/
#define XCQ_PushClose (([[UIDevice currentDevice].systemVersion floatValue]>=8.0f)?(UIUserNotificationTypeNone == [[UIApplication sharedApplication] currentUserNotificationSettings].types):(UIRemoteNotificationTypeNone == [[UIApplication sharedApplication] enabledRemoteNotificationTypes]))
#define XCQ_PushOpen (!XCQ_PushClose)

/** 直接跳到系统内本App的设置页面*/
#define XCQ_GoToApplicationSettingPage [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];


/** 字体*/
#define XCQ_Font(x) [UIFont systemFontOfSize:x]
#define XCQ_BoldFont(x) [UIFont boldSystemFontOfSize:x]
// s=flash文件中字体大小/3.0f，也即经过屏幕密度处理后的大小
#define XCQ_FONT_ADAPTED_WIDTH(s) (IOS9 ? [UIFont systemFontOfSize:(int)round(s * SCREEN_WIDTH_RATIO55)] : [UIFont fontWithName:@"STHeitiSC-Light" size:(int)round(s * SCREEN_WIDTH_RATIO55)])
#define XCQ_FONTBOLD_ADAPTED_WIDTH(s) (IOS9 ? [UIFont boldSystemFontOfSize:(int)round(s * SCREEN_WIDTH_RATIO55)] : [UIFont fontWithName:@"STHeitiSC-Medium" size:(int)round(s * SCREEN_WIDTH_RATIO55)])
#define FONT_ADAPTED_NUM(s)    [UIFont fontWithName:@"Avenir-Light" size:(int)round(s * SCREEN_WIDTH_RATIO55)]

/** 颜色(RGB) */
#define XCQ_RGB(r,g,b)  [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1];
#define XCQ_RGBA(r,g,b,a)   [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define XCQ_RandomColor [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]

/** 颜色(0xFFFFFF) */
#define XCQ_HEX_RGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define XCQ_HEX_RGBA(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]


/** 资源路径 */
#define XCQ_PNG_PATH(NAME) [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"png"]
#define XCQ_JPG_PATH(NAME) [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:NAME] ofType:@"jpg"]
#define XCQ_PATH(NAME,EXT) [[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]

/** 加载图片 */
#define XCQ_PNG_IMAGE_FILE(NAME)         [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define XCQ_JPG_IMAGE_FILE(NAME)         [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define XCQ_IMAGE_FILE(NAME,EXT)         [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]
#define XCQ_IMAGE_NAMED(NAME)            [UIImage imageNamed:NAME]

/** 输出*/
#ifdef DEBUG
#define XCQ_Log(...) NSLog(__VA_ARGS__)
#else
#define XCQ_Log(...)
#endif

#define XCQ_Print_CurrentMethod XCQ_Log(@"%s",__FUNCTION__);
#define XCQ_Print_CurrentLine XCQ_Log(@"%d",__LINE__);
#define XCQ_Print_CurrentClass XCQ_Log(@"%s",__FILE__);
#define XCQ_Print_CurrentStack XCQ_Log(@"%@",[NSThread callStackSymbols]);
#define XCQ_Print_CurrentPath XCQ_Log(@"%s",__FILE__);
#define XCQ_Print_CurrentDetail XCQ_Log(@"class==>%@, method==>%s, line==>%d",[self class],__FUNCTION__,__LINE__);


/** 获取硬件信息*/
#define XCQ_SCREEN_W [UIScreen mainScreen].bounds.size.width
#define XCQ_SCREEN_H [UIScreen mainScreen].bounds.size.height
#define XCQ_CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])
#define XCQ_CurrentSystemVersion [[[UIDevice currentDevice] systemVersion] floatValue]


/** 适配  ios 11 后系统提供了一套 判断方法**/
#define XCQ_iOS_5_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 5.0)
#define XCQ_iOS_6_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0)
#define XCQ_iOS_7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define XCQ_iOS_8_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define XCQ_iOS_9_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)
#define XCQ_iOS_10_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define XCQ_iOS_11_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0)

#define XCQ_iPhone4_OR_4s    (XCQ_SCREEN_H == 480)
#define XCQ_iPhone5_OR_5c_OR_5s   (XCQ_SCREEN_H == 568)
#define XCQ_iPhone6_OR_6s   (XCQ_SCREEN_H == 667)
#define XCQ_iPhone6Plus_OR_6sPlus   (XCQ_SCREEN_H == 736)
#define XCQ_iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

/** 系统的版本号 */
#define XCQ_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

/** APP版本号 */
#define XCQ_APP_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

/** APP BUILD 版本号 */
#define XCQ_APP_BUILD_VERSION  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

/** APP名字 */
#define XCQ_APP_DISPLAY_NAME  [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]

/** 当前语言 */
#define XCQ_LOCAL_LANGUAGE [[NSLocale currentLocale] objectForKey:NSLocaleLanguageCode]

/** 当前国家 */
#define XCQ_LOCAL_COUNTRY [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode]

/** 中英状态下键盘的高度 */
#define XCQ_ENG_KEY_BOARD_H  (216.f)
#define XCQ_CHN_KEY_BOARD_H  (252.f)

// 计算文本的尺寸
#define XCQ_textSize(text, fontSize, width) [text boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:fontSize]} context:nil].size;

#define XCQ_textSize1(text, font, width) [text boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:font} context:nil].size;

#define XCQ_textSize_IOS6 (text, font , width) [text sizeWithFont:font constrainedToSize:CGSizeMake(width, MAXFLOAT)];

// 计算文本的尺寸
#define XCQ_textSizeFont(text, fontSizeFont, width, height) [text boundingRectWithSize:CGSizeMake(width, height) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:fontSizeFont} context:nil].size;

// *************************** 其他方法 ********************************

#define NumToString(n) [NSString stringWithFormat:@"%@",n]

//app主窗口
#define SCKeyWindow [UIApplication sharedApplication].keyWindow

// 状态条高度
#define SCStatusBarHeight [UIApplication sharedApplication].statusBarFrame.size.height

// 去掉图片渲染
#define KImageOriginalWithName(imageName) [[UIImage imageNamed:imageName] imageWithRenderingMode: UIImageRenderingModeAlwaysOriginal]

// G－C－D
// 在Main线程上运行
#define DISPATCH_ON_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
// 在Global Queue上运行
#define DISPATCH_ON_GLOBAL_QUEUE_HIGH(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_DEFAULT(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_LOW(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_BACKGROUND(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), globalQueueBlocl);

// 由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

// 加载xib
#define LoadNib(x) [[NSBundle mainBundle] loadNibNamed:@(x) owner:nil options:nil][0]

// 在宏的参数前加上一个#，宏的参数会自动转换成c语言的字符串
#define MRKeyPath(objc,keyPath) @(((void)objc.keyPath, #keyPath))

//** 获得当前的 年 月 日 时 分 秒 *****************************************************************************
#define CurrentSec [[NSCalendar currentCalendar] component:NSCalendarUnitSecond fromDate:[NSDate date]]
#define CurrentMin [[NSCalendar currentCalendar] component:NSCalendarUnitMinute fromDate:[NSDate date]]
#define CurrentHour [[NSCalendar currentCalendar] component:NSCalendarUnitHour fromDate:[NSDate date]]
#define CurrentDay [[NSCalendar currentCalendar] component:NSCalendarUnitDay fromDate:[NSDate date]]
#define CurrentMonth [[NSCalendar currentCalendar] component:NSCalendarUnitMonth fromDate:[NSDate date]]
#define CurrentYear [[NSCalendar currentCalendar] component:NSCalendarUnitYear fromDate:[NSDate date]]



#endif /* ChompAPI_h */
