/*
* Module:   TRTC 统计信息定义
*
* Function: 通话质量相关的定义
*
*/

#ifndef __TRTCSTATISTICS_H__
#define __TRTCSTATISTICS_H__

#include "TRTCCloudDef.h"

#include <stdint.h>

 /**
 * 自己本地的音视频统计信息
 */
struct TRTCLocalStatistics
{
    uint32_t width;                                 ///< 视频宽度

    uint32_t height;                                ///< 视频高度

    uint32_t frameRate;                             ///< 帧率（fps）

    uint32_t videoBitrate;                          ///< 视频发送码率（Kbps）

    uint32_t audioSampleRate;                       ///< 音频采样率（Hz）

    uint32_t audioBitrate;                          ///< 音频发送码率（Kbps）

    TRTCVideoStreamType streamType;                 ///< 流类型（大画面 | 小画面 | 辅路画面）
};

/**
* 远端成员的音视频统计信息
*/
struct TRTCRemoteStatistics
{
    const char* userId;                                ///< 用户 ID，指定是哪个用户的视频流

    /** 该线路的总丢包率（％）
     *
     * 这个值越小越好，比如：0%的丢包率代表网络很好。
     * 这个丢包率是该线路的 userId 从上行到服务器再到下行的总丢包率。
     * 如果 downLoss 为 0%, 但是 finalLoss 不为0%，说明该 userId 在上行就出现了无法恢复的丢包。
     */
    uint32_t finalLoss;                            

    uint32_t width;                                 ///< 视频宽度

    uint32_t height;                                ///< 视频高度

    uint32_t frameRate;                             ///< 接收帧率（fps）

    uint32_t videoBitrate;                          ///< 视频码率（Kbps）

    uint32_t audioSampleRate;                       ///< 音频采样率（Hz）

    uint32_t audioBitrate;                          ///< 音频码率（Kbps）

    TRTCVideoStreamType streamType;                 ///< 流类型（大画面 | 小画面 | 辅路画面）
};

/**
* 统计数据
*/
struct TRTCStatistics
{

    /** C -> S 上行丢包率（％），
     * 这个值越小越好，例如，0%的丢包率代表网络很好，
     * 而 30% 的丢包率则意味着 SDK 向服务器发送的每10个数据包中就会有3个会在上行传输中丢失。
     */
    uint32_t upLoss;         

    /** S -> C 下行丢包率（％），
     * 这个值越小越好，例如，0%的丢包率代表网络很好，
     * 而 30% 的丢包率则意味着服务器向 SDK 发送的每10个数据包中就会有3个会在下行传输中丢失。
     */
    uint32_t downLoss;                              

    ///当前 App 的 CPU 使用率（％）
    uint32_t appCpu;

    /// 当前系统的 CPU 使用率（％）
    uint32_t systemCpu;

    /// 延迟（毫秒），
    /// 代表 SDK 跟服务器一来一回之间所消耗的时间，这个值越小越好。
    /// 一般低于50ms的 rtt 是比较理想的情况，而高于100ms的 rtt 会引入较大的通话延时。
    /// 由于数据上下行共享一条网络连接，所以 local 和 remote 的 rtt 相同。
    uint32_t rtt;         

    /// 总接收字节数（包含信令和音视频）
    uint32_t receivedBytes;                  

    /// 总发送字节总数（包含信令和音视频）
    uint32_t sentBytes; 

    /// 自己本地的音视频统计信息，由于可能有大画面、小画面以及辅路画面等多路的情况，所以是一个数组
    TRTCLocalStatistics* localStatisticsArray;     

    /// 数组 localStatisticsArray 的大小
    uint32_t localStatisticsArraySize;              

    /// 远端成员的音视频统计信息，由于可能有大画面、小画面以及辅路画面等多路的情况，所以是一个数组
    TRTCRemoteStatistics* remoteStatisticsArray;    

    /// 数组 remoteStatisticsArray 的大小
    uint32_t remoteStatisticsArraySize;             
};

#endif /* __TRTCSTATISTICS_H__ */
