# 定义编译器
CC = gcc
# 编译选项：-Wall显示所有警告，-g生成调试信息（用于GDB）
CFLAGS = -Wall -g

# 默认目标：生成可执行文件parser（输入make即执行）
all: parser

# 生成可执行文件parser：依赖main.o和parser.o
parser: main.o parser.o
	$(CC) $(CFLAGS) -o parser main.o parser.o

# 生成main.o：依赖main.c和parser.h
main.o: main.c parser.h
	$(CC) $(CFLAGS) -c main.c

# 生成parser.o：依赖parser.c和parser.h
parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

# 生成静态链接库libparser.a
static: parser.o
	ar rs libparser.a parser.o

# 生成动态链接库libparser.so
dynamic:
	$(CC) -fPIC -shared $(CFLAGS) parser.c -o libparser.so

# 清理编译产物（输入make clean执行）
clean:
	rm -rf parser *.o libparser.a libparser.so test_static test_dynamic core*
