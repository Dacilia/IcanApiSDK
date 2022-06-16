#  唤起我行
### 在白名单中LSApplicationQueriesSchemes添加icanchat 或者 icancn 这两个scheme 具体看业务需求添加
icanchat 唤起的是国际版的APP
icancn 是国内版的APP

### 在程序启动的时候调用下面的方法注册你的APP  该appid由自己定义
`
[IcanApi registerApp:@"testapp1234"];
`
### 支付
#### 我行余额支付
1. 初始化一个 IcanApiSendPayReq 的对象 然后给transactionId 赋值你拿到的transactionId 然后调用`sendReq `的方法
`
IcanApiSendPayReq * requ = [[IcanApiSendPayReq alloc]init];
    requ.transactionId = self.transactionIdTextFiled.text;
    [IcanApi sendReq:requ completion:nil];
`
#### c2c支付
1. 初始化一个 IcanApiSendC2CPayReq 的对象 然后给transactionId 赋值你拿到的transactionId 然后调用`sendReq `的方法
`
IcanApiSendC2CPayReq * requ = [[IcanApiSendC2CPayReq alloc]init];
    requ.transactionId = self.transactionIdTextFiled.text;
    [IcanApi sendReq:requ completion:nil];
`
### 授权登录
1. 初始化一个 IcanApiSendAuthReq 的对象  然后调用`sendReq `的方法
`
IcanApiSendAuthReq * requ = [[IcanApiSendC2CPayReq alloc]init];
    requ.access_token = access_token;
    [IcanApi sendReq:requ completion:nil];
`
### 客服
1. 初始化一个 IcanApiSendServiceReq 的对象  然后调用`sendReq `的方法
`
IcanApiSendServiceReq * requ = [[IcanApiSendServiceReq alloc]init];
    requ.userId = userId;
    [IcanApi sendReq:requ completion:nil];
`
### 商品分享
1. 初始化一个 IcanApiSendGoodsReq 的对象  然后调用`sendReq `的方法
`
IcanApiSendGoodsReq * requ = [[IcanApiSendGoodsReq alloc]init];
    requ.content = content;
    [IcanApi sendReq:requ completion:nil];
`
### 回调
在AppDelegate中实现以下方法 并且实现代理方法`-(void)onResp:(IcanApiBaseResp *)resp`
`
 (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    [IcanApi handleOpenURL:url delegate:self];
    return YES;
}
`
### 参数说明具体请看`IcanApiObject.h `该头文件
