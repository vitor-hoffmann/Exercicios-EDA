#include <stdio.h>
#include <ctype.h>

int convertnum(const char **str){
    int num = 0;
    while (isdigit(**str)){
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    return num;
}

int eval(const char **str){
    int result = 0;
    char op = '+';

    while (**str){
        if (**str == ' '){
            (*str)++;
            continue;
        }
        if (**str == '('){
            (*str)++;
            int subresult = eval(str);
            if (op == '+') result += subresult;
            if (op == '-') result -= subresult;
        }
        else if (isdigit(**str)){
            int num = convertnum(str);
            if (op == '+') result += num;
            if (op == '-') result -= num;
        }
        else if (**str == ')'){
            (*str)++;
            return result;
        }
        else {
            op = **str;
            (*str)++;
        }
    }
    return result;
}

int main() {
    const char *expression = "1 + (2 - (4 + 5) + (1 - 6))";
    printf("Resultado da expressao %s ", expression);
    printf("e %d", eval(&expression));
    return 0;
}