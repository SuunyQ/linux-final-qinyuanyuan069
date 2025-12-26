#include "parser.h" 
#include <ctype.h>   

int parse_number_sum(const char *input) {
    int sum = 0;    
    int current = 0;

    
    while (*input != '\0') {
        
        if (isdigit(*input)) {
           
            current = current * 10 + (*input - '0');
        } else {
            
            sum += current;
            current = 0;
        }
        input++;  
    }

    
    sum += current;
    return sum; 
}
