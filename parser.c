#include "parser.h"
#include <string.h>   // 用于strlen计算字符串长度
#include <stdio.h>    // 用于文件操作

// 实现字符串解析函数
int parse_string(const char *input) {
    if (input == NULL) {
        return -1;
    }
    return strlen(input);
}

// 实现文件行数统计函数
int count_file_lines(const char *filename) {
    // 校验文件名是否为空
    if (filename == NULL) {
        return -1;
    }
    // 只读方式打开文件
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -2;
    }
    // 逐行读取文件，统计行数
    int line_count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        line_count++;
    }
    // 关闭文件
    fclose(file);
    return line_count;
}
