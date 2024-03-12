#ifndef CALC_H
#include <ctype.h>
#include <string.h>

int priority(char c);
void rpn(char* infix_str, char* output_str);
double calc(char* out);

#endif