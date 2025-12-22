#ifndef PARSER_H
#define PARSER_H

// 字符串长度解析函数声明
// 参数：input - 待解析的字符串；返回值：-1=空指针，>=0=字符串长度
int parse_string(const char *input);

// 文件行数统计函数声明
// 参数：filename - 待统计的文件名；返回值：-1=文件名空，-2=文件打开失败，>=0=行数
int count_file_lines(const char *filename);

#endif
