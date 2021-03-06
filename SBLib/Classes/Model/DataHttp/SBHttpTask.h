
/*
 #####################################################################
 # File    : SBHttpTask.h
 # Project :
 # Created : 2013-03-30
 # DevTeam : Thomas Develop
 # Author  :
 # Notes   :
 #####################################################################
 ### Change Logs   ###################################################
 #####################################################################
 ---------------------------------------------------------------------
 # Date  : 2016-1-8
 # Author: thomas
 # Notes : 改成nsurlsession   ios7
 #
 #####################################################################
 ### Change Logs   ###################################################
 #####################################################################
 ---------------------------------------------------------------------
 # Date  :
 # Author:
 # Notes :
 #
 #####################################################################
 */

#import <Foundation/Foundation.h>
#import <Foundation/NSObject.h>
#import "AFNetworking.h"


typedef enum {
    SBHttpTaskStateReady = 1,               //开始
    SBHttpTaskStateExecuting = 2,           //执行中
    SBHttpTaskStateFinished = 3             //结束
} SBHttpTaskState;

// 网络连接用到的常量
#define APPCONFIG_CONN_ADD_PREFIX           @"/"                    // WAP 接口前缀 东方财富网没有专门为客户端的接口前缀
#define APPCONFIG_CONN_USER_AGENT           @"app-iphone-client"      // 连接WAP接口的客户端声明
#define APPCONFIG_CONN_TIMEOUT              30                          // 连接超时时间
#define APPCONFIG_CONN_URL_CACHE              (60*60*24*7)                          // 缓存失效时间

@class SBHttpTask;

//该协议用于约束响应 SBHttpTask 事件的类，确保其拥有 onError 和 onReceived 两个方法。
@protocol SBHttpTaskDelegate <NSObject>

@required

/** onError 方法，在 SBHttpTask 请求出错时回调的方法 */
- (void)task:(SBHttpTask *)task onError:(NSError *)error;

/** onReceived 方法，在 SBHttpTask 数据加载完成后回调的方法 */
- (void)task:(SBHttpTask *)task onReceived:(NSData *)data;

@optional

/** 请求即将开始 第一次开始，不包括重试） */
- (void)taskWillStart:(SBHttpTask *)task;

/** 请求已经发出字节 */
- (void)task:(SBHttpTask *)task didSendData:(NSInteger)sendedBytes totalData:(NSInteger)totalBytes;

@end

/**
 *   1.该类用于响应网络请求。
 *   2.该类会封装超时时间，用户代理和处理请求异常。
 */
@interface SBHttpTask : NSOperation

/** 网络*/
@property (nonatomic, strong) NSURLSessionTask *sessionDataTask;

/** url为最基本的参数，必须指定 */
@property (nonatomic, strong) NSString *aURLString;

/** http header 参数 */
@property (nonatomic, strong) NSDictionary *aHTTPHeaderField;

/** 接收到的网络数据 */
@property (nonatomic, strong) NSMutableData *recieveData;

/** 代理 */
@property (nonatomic, weak) id<SBHttpTaskDelegate> delegate;

/** 网络请求状态码 */
@property (nonatomic, assign) NSInteger statusCode;

/** 错误信息 */
@property (strong, nonatomic) NSError *httpError;

/** 标签，用以区分同一个delegate的不同task */
@property (nonatomic, assign) NSInteger tag;

/** 附带的用户信息 */
@property (nonatomic, retain) id userInfo;

/** post请求的post数据 */
@property (nonatomic, strong) NSData *postData;

/** 超时时间，默认为xx秒 */
@property (nonatomic, assign) NSTimeInterval timeout;

/** 超时时间，默认为xx秒 */
@property (nonatomic, assign) NSTimeInterval durationTime;

/** 数据压缩  */
@property (nonatomic, assign) BOOL gzip;

/** json方式传参  */
@property (nonatomic, strong) NSMutableDictionary *jsonDict;

/** 网络操作状态 */
@property (nonatomic, assign) SBHttpTaskState sbHttpTaskState;

/** 初始化一个HTTP请求 */
- (id)initWithURLString:(NSString *)aURLString
             httpMethod:(NSString *)method
               delegate:(id<SBHttpTaskDelegate>)delegate;

/** 终止数据加载 */
- (void)stopLoading;

@end
