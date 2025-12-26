#include "parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // 新增：包含exit()函数（处理文件打开失败）

// 新增函数：统计指定文件的行数（新增功能：linecount分支专属）
int count_file_lines(const char *filename) {
    FILE *file = fopen(filename, "r");  // 以只读模式打开文件
    if (file == NULL) {  // 判断文件是否成功打开（如文件不存在）
        perror("Failed to open file");  // 打印错误信息（如“Failed to open file: No such file or directory”）
        exit(1);  // 退出程序，返回1表示错误
    }

    int line_count = 0;  // 存储行数，初始为0
    char buffer[1024];   // 缓冲区，用于读取文件内容

    // 逐行读取文件，直到读取到文件末尾（fgets返回NULL表示末尾）
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_count++;  // 每读取一行，行数+1
    }

    fclose(file);  // 关闭文件（避免资源泄漏）
    return line_count;  // 返回文件行数
}

int main() {
    const char *test_str1 = "Linux2025Final100";
    const char *test_str2 = "NoNumbersHere";

    int result1 = parse_number_sum(test_str1);
    int result2 = parse_number_sum(test_str2);

    printf("测试1：字符串\"%s\"中的数字总和 = %d\n", test_str1, result1);
    printf("测试2：字符串\"%s\"中的数字总和 = %d\n", test_str2, result2);

    // 新增：调用行统计函数，统计main.c的行数
    const char *target_file = "main.c";
    int lines = count_file_lines(target_file);
    printf("统计：文件\"%s\"的总行数 = %d\n", target_file, lines);

    return 0;
}
