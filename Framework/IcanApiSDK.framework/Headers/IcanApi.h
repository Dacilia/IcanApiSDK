//
/**
- Copyright © 2022 dzl. All rights reserved.
- Author: Created  by DZL on 28/3/2022
- File name:  IcanChatApi.h
- Description: ICan Meatapi
- Function List:
*/
        

#import <Foundation/Foundation.h>
#import "IcanApiObject.h"
NS_ASSUME_NONNULL_BEGIN

#pragma mark - WXApiDelegate
/*! @brief 接收并处理来自Ican终端程序的事件消息
 *
 * 接收并处理来自ICan Meat终端程序的事件消息，期间ICan Meat界面会切换到第三方应用程序。
 * WXApiDelegate 会在handleOpenURL:delegate:中使用并触发。
 */
@protocol IcanApiDelegate <NSObject>
@optional

/*! @brief 收到一个来自ICan Meat的请求，第三方应用程序处理完后调用sendResp向ICan Meat发送结果
 *
 * 收到一个来自ICan Meat的请求，异步处理完成后必须调用sendResp发送处理结果给ICan Meat。
 * 可能收到的请求有GetMessageFromWXReq、ShowMessageFromWXReq等。
 * @param req 具体请求内容，是自动释放的
 */
- (void)onReq:(IcanApiBaseReq*)req;



/*! @brief 发送一个sendReq后，收到ICan Meat的回应
 *
 * 收到一个来自ICan Meat的处理结果。调用一次sendReq后会收到onResp。
 * 可能收到的处理结果有SendMessageToWXResp、SendAuthResp等。
 */
- (void)onResp:(IcanApiBaseResp*)resp;

@end
@interface IcanApi : NSObject
/*!
 * @brief IcanChatApi的成员函数，向ICan Meat终端程序注册第三方应用。
 * 需要在每次启动第三方应用程序时调用。
 * @attention 请保证在主线程中调用此函数
 * @param appid 唯一标志 用户自定义
 */
+ (void)registerApp:(NSString *)appid;
/*! @brief 处理ICanURL启动App时传递的数据
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url ICan Meat启动第三方应用时传递过来的URL
 * @param delegate  WXApiDelegate对象，用来接收ICan Meat触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)url delegate:(nullable id<IcanApiDelegate>)delegate;

/*! @brief 检查iCan Chat是否已被用户安装
 *
 * @return iCan Chat已安装返回YES，未安装返回NO。
 */
+ (BOOL)isiCanChatInstalled;

/*! @brief 检查ICan Meat是否已被用户安装 国际版
 *
 * @return ICan Meat已安装返回YES，未安装返回NO。
 */
+ (BOOL)isICanMeatInstalled;

/*! @brief 发送请求到ICan Meat，等待ICan Meat返回onResp
 *
 * 函数调用后，会切换到ICan Meat的界面。第三方应用程序等待ICan Meat返回onResp。ICan Meat在异步处理完成后一定会调用onResp。
 * @param req 具体的发送请求。
 * @param completion 调用结果回调block
 */
+ (void)sendReq:(IcanApiBaseReq *)req completion:(void (^ __nullable)(BOOL success))completion;
@end

NS_ASSUME_NONNULL_END
