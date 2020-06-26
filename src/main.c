/**
 *  @author:yuzhanglong
 *  @email:yuzl1123@163.com
 *  @version: 1.0
 *
 *
 *  注意：请在linux系统下调试运行，切记切记！
 *  若你在macos系统下运行(虽然可以跑)，会出现你不期望的情况，
 *  例如：某些量的单位会不同(eg.costResource.ru_maxrss)
 *       或者某些功能无法实现（eg.内存超限检测）
 *
 *  另外，在调试的时候请使用日志记录（当然可以printf，但是在生产环境下不建议）
 *
 */
#include "common/common.h"
#include "judger/judger.h"


int main(int argc, char *argv[]) {
    struct execConfig execConfig;
    struct judgeResult judgeResult;
    initExecConfigAndJudgeResult(&execConfig, &judgeResult);
    if (getAndSetOptions(argc, argv, &execConfig)) {
        if (validateForExecConfig(&execConfig)) {
            runJudger(&execConfig, &judgeResult);
        } else {
            judgeResult.condition = VALIDATE_ERROR;
        }
    }
    generateResult(&execConfig, &judgeResult);
    return 0;
}