# Parser项目说明
本项目是Linux操作系统期末大作业（任务七）的代码实现，提供简单的“字符串数字解析功能”。

## 项目功能
- 解析字符串中的所有连续数字，计算并返回数字总和（如"abc123def45"→168）
- 支持生成静态链接库（libparser.a）和动态链接库（libparser.so），供其他程序调用
- 提供Makefile，支持一键编译、生成库文件、清理编译产物

## 使用说明
1. **编译主程序**：在项目根目录执行`make parser_app`，生成可执行文件`parser_app`
2. **运行主程序**：执行`./parser_app`，查看测试结果
3. **生成静态库**：执行`make libparser.a`，生成静态库`libparser.a`
4. **生成动态库**：执行`make libparser.so`，生成动态库`libparser.so`
5. **清理编译产物**：执行`make clean`，删除所有编译生成的文件

## 作者信息
- 姓名：[qinyuanyuan]
- 学号：[0244069]
- 课程：Linux操作系统期末大作业
