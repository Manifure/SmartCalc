#include "smartcalc.h"

#include <stdio.h>

#include "calc.h"
#include "stack.h"
void calc_main(char* input_str, char* result_str) {
  // char input_str[MAX_SIZE] =
  //    "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
  char output[MAX_SIZE];
  rpn(input_str, output);
  //----------------------calc-----------------------
  // printf("%f",result);
  // char operator;
  // int operand1 = 0, operand2 = 0, result = 0;
  // sscanf(str_char,"%d%c%d", &operand1, &operator, &operand2);

  // switch(operator) {
  // case '+':
  //     result = operand1 + operand2;
  //     break;
  // case '-':
  //     result = operand1 - operand2;
  //     break;
  // case '*':
  //     result = operand1 * operand2;
  //     break;
  // case '/':
  //     result = operand1 / operand2;
  //     break;
  // } //тест работы без стека

  // memset(str_char, 0, sizeof(char) * strlen(str_char));
  // char result_str[256];
  sprintf(result_str, "%.10g", calc(output));
  // strncpy(str_char, result_str, sizeof(str_char) - 1);
}
