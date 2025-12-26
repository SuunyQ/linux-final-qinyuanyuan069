#include "parser.h"  
#include <stdio.h>   
#include <string.h>  

int main() {
    
    const char *test_str1 = "Linux2025Final100";  
    
    const char *test_str2 = "NoNumbersHere";      

    
    int result1 = parse_number_sum(test_str1);
    int result2 = parse_number_sum(test_str2);

    
    printf("测试1：字符串\"%s\"中的数字总和 = %d\n", test_str1, result1);  // 预期：2025+100=2125
    printf("测试2：字符串\"%s\"中的数字总和 = %d\n", test_str2, result2);  // 预期：0

    return 0;  
}
