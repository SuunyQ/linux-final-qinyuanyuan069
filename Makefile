# 定义编译器（此处为gcc，C语言编译器）
CC = gcc  
# 定义编译选项：-Wall（显示所有警告，帮助排查错误）、-g（生成调试信息，供gdb使用）
CFLAGS = -Wall -g  

# 目标1：编译主程序（生成可执行文件parser_app）
# 依赖：main.c和parser.c（这两个文件修改后，执行make会重新编译）
parser_app: main.c parser.c parser.h
	$(CC) $(CFLAGS) main.c parser.c -o parser_app  # 编译命令：将两个源文件编译为parser_app

# 目标2：生成静态链接库libparser.a（静态库：编译时直接嵌入程序，不依赖外部文件）
# 步骤：1. 将parser.c编译为目标文件parser.o；2. 用ar命令打包为静态库
libparser.a: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c -o parser.o  # -c：只编译不链接，生成目标文件parser.o
	ar rs libparser.a parser.o  # ar命令：将parser.o打包为静态库，rs=替换旧文件+建立索引

# 目标3：生成动态链接库libparser.so（动态库：运行时才加载，可被多个程序共享）
# 步骤：1. 编译时加-fPIC（生成位置无关代码，动态库必需）；2. 用-shared生成动态库
libparser.so: parser.c parser.h
	$(CC) $(CFLAGS) -fPIC -shared parser.c -o libparser.so  # -shared：生成动态库

# 目标4：清理编译生成的文件（执行make clean时触发）
# 清理内容：可执行文件parser_app、目标文件parser.o、静态库、动态库
clean:
	rm -f parser_app parser.o libparser.a libparser.so  
