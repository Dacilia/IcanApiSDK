//
/**
- Copyright © 2022 dzl. All rights reserved.
- Author: Created  by DZL on 28/3/2022
- File name:  IcanApiObject.h
- Description:
- Function List:
*/
        

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*! @brief 错误码
 *
 */
typedef NS_ENUM(NSInteger,IcanErrCode){
    IcanSuccess           = 0,    /**< 成功    */
    IcanErrCodeCommon     = -1,   /**< 普通错误类型    */
    IcanErrCodeUserCancel = -2,   /**< 用户点击取消并返回    */
    IcanErrCodeSentFail   = -3,   /**< 发送失败    */
    IcanErrCodeAuthDeny   = -4,   /**< 授权失败    */
    IcanErrCodeUnsupport  = -5,   /**< ICan Meat不支持    */
};


#pragma mark - BaseReq
/*! @brief 该类为ICan Meat终端SDK所有请求类的基类
 *
 */
@interface IcanApiBaseReq : NSObject

/** 请求类型 */
@property (nonatomic, assign) int type;

/**
 需要选择哪个APP支付 默认是ICan Meat (国际版)
 0 ICan Meat (国际版包含c2c)
 1 ICan Chat (任信 中国版)
 */
@property (nonatomic, assign) int appType;
@end



#pragma mark - BaseResp
/*! @brief 该类为ICan Meat终端SDK所有响应类的基类
 *
 */
@interface IcanApiBaseResp : NSObject
/** 错误码  */
@property (nonatomic, assign) int errCode;
/** 错误提示字符串(有可能为空) */
@property (nonatomic, copy) NSString *errStr;
/** 响应类型 */
@property (nonatomic, assign) int type;


@end
#pragma mark - SendAuthReq
/*! @brief 第三方程序向ICan Meat终端请求认证的消息结构
 *
 * 第三方程序要向ICan Meat申请认证，并请求某些权限，需要调用IcanApi的sendReq成员函数，
 * 向ICan Meat终端发送一个SendAuthReq消息结构。ICan Meat终端处理完后会向第三方程序发送一个处理结果。
 * @see SendAuthResp
 */
@interface IcanApiSendAuthReq : IcanApiBaseReq
/**
 该字段不能为空
 
 */
@property (nonatomic, copy) NSString *access_token;

@end

#pragma mark - SendAuthResp

@interface IcanApiSendAuthResp : IcanApiBaseResp


@end

/*
 第三方程序向ICan Meat终端请求我行支付的消息结构
 */
@interface IcanApiSendPayReq : IcanApiBaseReq
/**
 交易的订单ID
 */
@property (nonatomic, copy) NSString *transactionId;
@end


@interface IcanApiSendPayResp : IcanApiBaseResp



@end

/*
 第三方程序向ICan Meat终端请求c2c支付的消息结构
 */
@interface IcanApiSendC2CPayReq : IcanApiBaseReq
/**
 交易的订单ID
 */
@property (nonatomic, copy) NSString *transactionId;
@end


/*
 第三方程序向ICan终端请求客服的消息结构
 */
@interface IcanApiSendServiceReq : IcanApiBaseReq

/**
 用户ID
 */
@property (nonatomic, copy) NSString *userId;

@end

/*
 第三方程序向ICan终端请求商品分享的消息结构
 */
@interface IcanApiSendGoodsReq : IcanApiBaseReq
/**
 商品内容
 */
@property (nonatomic, copy) NSString *content;

@end
NS_ASSUME_NONNULL_END
