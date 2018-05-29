#include <stdio.h>
#define MTFE_C_EXPORTS_C_EXPORTS
#include "include/cw_mutil_thread_feature_extract.h"

/*
brief 创建句柄
输入：
    const char* configure： 配置文件路径
    const char* cw_key_licence： cw_key licence
输出：
    long long *handle,句柄的指针。
返回值：
    返回 0 正确
    返回 -3 ,cw_key授权码不正确。
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_create_handle(long long* handle, const char* configure, const char* cw_key_licence)
{
    printf("call cw_mutil_thread_feature_extract_create_handle\n");
    return 0;
}

/*
brief 创建句柄
输入：
    long long handle    句柄的指针
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_release_handle(long long handle)
{
    printf("call cw_mutil_thread_feature_extract_release_handle\n");
    return 0;
}

/* 获取版本号 szVersion预先分配1024个字节 */
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_get_version(long long handle,char* szVersion)
{
    printf("call cw_mutil_thread_feature_extract_get_version\n");
    return 0;
}

/*
brief 获取特征长度
输入：
    long long  handle    特征提取句柄
输出：
    int fea_length[10]   大小为 10 的 int 数组, 返回结果为每个特征的长度
    int* n               特征个数
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_get_feature_length(long long handle,
                                                                           int fea_length[10],
                                                                           int* n)
{
    printf("call cw_mutil_thread_feature_extract_get_feature_length\n");
    return 0;
}

/*
brief 计算两个人脸的相似度
输入：
    long long  handle    特征提取句柄
    char* fea_a          人脸a的特征，备注：该特特征为 cw_mutil_thread_feature_extract_get_feature 获取的特征
    char* fea_b          人脸b的特征，备注：同上
输出：
    float* score         返回两个人脸的相似度,取值范围[0,1]
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_get_compute_similarity(long long handle,
                                                                               char* fea_a,
                                                                               char* fea_b,
                                                                               float* score)
{
    printf("call cw_mutil_thread_feature_extract_get_compute_similarity\n");
    return 0;
}


/*
brief 将需要提取特征的图片push到队列
输入：
    long long handle        特征提取句柄
    char* image_data        图片数据
    int image_data_len      图片数据长度
    int idx                 图片索引号
    int x,y,width,height    预先知道的人脸位置，当 width == 0 或 height == 0 时表示不知道人脸位置，需要进行检测
    bool id_card_flag       该图片是否为证件照
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_push_image(long long handle ,
                                                                   char* image_data,
                                                                   int image_data_len,
                                                                   int idx,
                                                                   int x, int y, int width, int height,
                                                                   bool id_card_flag)
{
    printf("call cw_mutil_thread_feature_extract_push_image\n");
    return 0;
}


/*
brief 将需要提取特征的图片push到队列
输入：
    long long handle            特征提取句柄
    char* image_data            图片数据
    int image_data_len          图片数据长度
    int idx                     图片索引号
    float pointArray[]          关键点坐标:       pointArray[0] 和 pointArray[1] 为左眼中心点坐标
                                                  pointArray[2] 和 pointArray[3] 为右眼中心点坐标
                                                  pointArray[4] 和 pointArray[5] 为嘴部中心点坐标
    int actionParameter         动作参数，其中每一位的作用如下：

                     2          是否使用传入的关键点数组
                     4          图片是否是证件照
    例：如果图片是证件照，是否使用传入的关键点数组，就传： 4 + 2 = 6
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_push_image_with_point(long long handle ,
                                                                              char* image_data,
                                                                              int image_data_len,
                                                                              int idx,
                                                                              float pointArray[20],
                                                                              int actionParameter
                                                                              // bool id_card_flag,
                                                                              // bool externalPointEnable
                                                                              )
{
    printf("call cw_mutil_thread_feature_extract_push_image_with_point\n");
    return 0;
}



//int *num既是输入又是输出

/*
brief 将需要提取特征的图片push到队列
输入：
    long long handle        特征提取句柄
输出：
    char* fea               提取到的特征，该特征为多模型的串联，字符数组
    int* idx                特征对应的序号, 这个序号是和图片一起传入的
    float* quality_score    提取到的人脸质量分，需要预先分配 30 个 float
返回值
    返回  0 正确
    返回 -1 表示获取特征失败，因为队列为空
    返回  1 表示未检测到人脸
    返回  3 表示图片解码失败
    返回  5 表示人脸框范围和图片无交集

10个质量分分别为
[0]人脸质量总分                                      0.65
[1]光照分，越大表示光照越适合                        0.4
[2]口罩得分, 分数越大表示越不可能戴口罩              0.44
[3]
[4]清晰度分，越大表示越清晰                          0.65
[5]是否戴眼镜分数，越大表示越可能没戴眼镜            0.5
[6]闭嘴分数， 越大表示越可能是闭嘴                   0.5
[7]人脸特征点质量分数, 越大表示人脸越清晰            0.6
[8]                                                  1.0
[9]戴墨镜的置信分，分数越高，表示戴墨镜的可能性越大  0.5
[10] 年龄
[11] 性别       1 男       2 女
[12] 国籍       1 中国人   2 外国人
[13] 年龄段     1 小孩     2 中年人   4 老人
[14] 正脸侧脸                                        1.0
[15] 人种       1 黄种人   2 黑种人   4 白种人   8 新疆人
[16] 人脸旋转角 pitch
[17] 人脸旋转角 yaw
[18] 人脸旋转角 roll
[19] 人脸框     x
[20] 人脸框     y
[21] 人脸框     width
[22] 人脸框     height
[23] 是否黑白打印纸张，越大表示越可能是真人          0.5
[24]                                                 0
后面到30号位保留字段
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_get_feature(long long handle,
                                                                    char* fea,
                                                                    int* idx,
                                                                    float quality_score[30])
{
    printf("call cw_mutil_thread_feature_extract_get_feature\n");
    return 0;
}

/*
@brief 把注册特征（filed）转为检索特征（probe）
输入：
    long long  handle       特征提取句柄
    int fea_dim             单个样本特征长度
    const char* filed_fea   注册特征
输出:
    char* probe_fea         检索特征，需要预先分配与filed_fea同样大小的空间
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_convert_feature_to_probe(long long handle,
                                                                                 char* probe_fea,
                                                                                 int fea_dim,
                                                                                 const char* filed_fea)
{
    printf("call cw_mutil_thread_feature_extract_convert_feature_to_probe\n");
    return 0;
}

/*
brief 获取特征长度
输入：
    long long  handle    特征提取句柄
    char** fea_filed     注册样本特征
    int* filed_idx       注册样本的 id 号
    int fea_filed_num    注册样本个数
    bool use_gpu         是否使用 GPU 比对
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_push_feature(long long handle,
                                                                     char** fea_filed,
                                                                     long long* filed_idx,
                                                                     int fea_filed_num ,
                                                                     bool use_gpu)
{
    printf("call cw_mutil_thread_feature_extract_push_feature\n");
    return 0;
}

/*
brief 获取特征长度
输入：
    long long handle                特征提取句柄
    char** fea_probe                检索样本特征
    int fea_probe_num               检索样本个数
    int num_models                  暂时没有使用
    int TopN                        获取排名前N的分数与索引
    unsigned char* valid_idx_array  匹配原型的位置数组 (如果需要和某个人比对, 相应位置 1, 数组长度和 fea_filed_num 一致)
输出
    float* topN_scores              排名前 N 的分数
    long long* topN_idx             排名前 N 的 ID 号
    int* reuslt_topN                实际返回的最高分的数量
*/
MTFE_C_EXPORTSDLL_C int cw_mutil_thread_feature_extract_compute_match_score(long long handle,
                                                                            char** fea_probe,
                                                                            int fea_probe_num,
                                                                            int num_models,
                                                                            int TopN,
                                                                            unsigned char* valid_idx_array,
                                                                            float* topN_scores,
                                                                            long long* topN_idx,
                                                                            int* reuslt_topN)
{
    printf("call cw_mutil_thread_feature_extract_compute_match_score\n");
    return 0;
}


MTFE_C_EXPORTSDLL_C int cw_cGO_test(CGO_TEST  *test)
{
    test->intX = 1024;
    test->stringY = "this is string";
    memcpy(test->pCharZ, "this is point", sizeof("this is point"));
    return 1011;
}

