#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // 校验命令行参数数量（必须为3个：程序名+模式+输入）
    if (argc != 3) {
        printf("【使用说明】\n");
        printf("1. 字符串解析：%s -str <待解析字符串>\n", argv[0]);
        printf("2. 文件行数统计：%s -file <待统计文件名>\n", argv[0]);
        exit(1); // 参数错误，退出程序
    }

    // 字符串解析模式
    if (strcmp(argv[1], "-str") == 0) {
        int result = parse_string(argv[2]);
        if (result == -1) {
            printf("解析失败：输入的字符串为空！\n");
        } else {
            printf("解析成功：字符串长度为 %d\n", result);
        }
    }
    // 文件行数统计模式
    else if (strcmp(argv[1], "-file") == 0) {
        int result = count_file_lines(argv[2]);
        switch (result) {
            case -1:
                printf("统计失败：文件名为空！\n");
                break;
            case -2:
                printf("统计失败：文件「%s」不存在或无访问权限！\n", argv[2]);
                break;
            default:
                printf("统计成功：文件「%s」的行数为 %d\n", argv[2], result);
                break;
        }
    }
    // 无效模式
    else {
        printf("错误：无效模式！仅支持 -str / -file 两种模式\n");
        exit(1);
    }

    return 0;
}
