#include "calc.h"

#include <math.h>

#include "stack.h"

int priority(char c) {
  // if (c == '(' return 0;
  if (c == '(') return 0;
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/' || c == '%') return 2;
  if (c == 'S' || c == 'C' || c == 'T' || c == 'O' || c == 'A' || c == 'N' ||
      c == 'Q' || c == 'L' || c == 'G')
    return 3;
  if (c == '^') return 4;
  return -1;
}

void rpn(char *input_str, char *output) {
  Stack RPN;

  initializeStack(&RPN);

  char infx[MAX_SIZE];
  int out_indx = 0;
  int inp_indx = 0;

  for (int j = 0; input_str[j] != '\0'; j++) {
    if (strncmp(&input_str[j], "sin", 3) == 0) {
      infx[inp_indx] = 'S';
      j += 2;
      inp_indx++;
    } else if (input_str[j] == '-' && isdigit(input_str[j + 1]) &&
               (!isdigit(input_str[j - 1]) && input_str[j - 1] != ')')) {
      infx[inp_indx] = '~';
      inp_indx++;
    } else if (strncmp(&input_str[j], "cos", 3) == 0) {
      infx[inp_indx] = 'C';
      j += 2;
      inp_indx++;
    } else if (strncmp(&input_str[j], "tan", 3) == 0) {
      infx[inp_indx] = 'T';
      j += 2;
      inp_indx++;
    } else if (strncmp(&input_str[j], "acos", 4) == 0) {
      infx[inp_indx] = 'O';
      j += 3;
      inp_indx++;
    } else if (strncmp(&input_str[j], "asin", 4) == 0) {
      infx[inp_indx] = 'A';
      j += 3;
      inp_indx++;
    } else if (strncmp(&input_str[j], "atan", 4) == 0) {
      infx[inp_indx] = 'N';
      j += 3;
      inp_indx++;
    } else if (strncmp(&input_str[j], "sqrt", 4) == 0) {
      infx[inp_indx] = 'Q';
      j += 3;
      inp_indx++;
    } else if (strncmp(&input_str[j], "ln", 2) == 0) {
      infx[inp_indx] = 'L';
      j += 1;
      inp_indx++;
    } else if (strncmp(&input_str[j], "log", 3) == 0) {
      infx[inp_indx] = 'G';
      j += 2;
      inp_indx++;
    } else {
      infx[inp_indx] = input_str[j];
      inp_indx++;
    }
  }


  //--------------------RPN------------------------

  for (int i = 0; infx[i] != '\0'; i++) {
    if (infx[i] == '~') {
      output[out_indx] = '-';
      i++;

      out_indx++;
    }
    if (infx[i] == '.' || (infx[i] >= '0' && infx[i] <= '9') ||
        (infx[i] >= 'a' && infx[i] <= 'z')) {
      output[out_indx] = infx[i];

      out_indx++;
    }
    if (infx[i] == '(') {
      push(&RPN, infx[i]);
    }

    if (infx[i] == ')') {
      while (!isEmpty(&RPN) && peek(&RPN) != '(') {
        output[out_indx] = ' ';
        out_indx++;
        output[out_indx] = pop(&RPN);

        out_indx++;
        output[out_indx] = ' ';
        out_indx++;
      }
      pop(&RPN);
    }

    if (infx[i] == '+' || infx[i] == '-' || infx[i] == '*' || infx[i] == '/' ||
        infx[i] == '^' || infx[i] == '%' || infx[i] == 'S' || infx[i] == 'C' ||
        infx[i] == 'T' || infx[i] == 'O' || infx[i] == 'A' || infx[i] == 'N' ||
        infx[i] == 'Q' || infx[i] == 'L' || infx[i] == 'G') {
      output[out_indx] = ' ';
      out_indx++;
      if (isEmpty(&RPN)) {
        push(&RPN, infx[i]);
      } else {
        if (priority(infx[i]) <= priority(peek(&RPN))) {
          while (priority(infx[i]) <= priority(peek(&RPN))) {
            output[out_indx] = pop(&RPN);

            out_indx++;
            output[out_indx] = ' ';
            out_indx++;
          }
          push(&RPN, infx[i]);

        } else {
          push(&RPN, infx[i]);
        }
      }
    }
    if (infx[i + 1] == '\0') {
      while (!isEmpty(&RPN)) {
        output[out_indx] = ' ';
        out_indx++;
        output[out_indx] = pop(&RPN);

        out_indx++;
      }
    }



  }

}

double calc(char *out) {
  Stack calc;
  initializeStack(&calc);
  double a = 0;
  double b = 0;
  char *token = strtok(out, " ");
  while (token != NULL) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      double num = atof(token);  // Преобразуем строку в число
      push(&calc, num);
    } else {

      double res = 0;
      switch (token[0]) {
        case '+':
          a = pop(&calc);
          b = pop(&calc);
          res = b + a;
          push(&calc, res);
          break;
        case '-':
          a = pop(&calc);
          b = pop(&calc);
          res = b - a;
          push(&calc, res);
          break;
        case '*':
          a = pop(&calc);
          b = pop(&calc);
          res = b * a;
          push(&calc, res);
          break;
        case '/':
          a = pop(&calc);
          b = pop(&calc);
          res = b / a;
          push(&calc, res);
          break;
        case '^':
          a = pop(&calc);
          b = pop(&calc);
          res = pow(b, a);
          push(&calc, res);
          break;
        case '%':
          a = pop(&calc);
          b = pop(&calc);
          push(&calc, fmod(b, a));
          break;
        case 'S':
          a = pop(&calc);
          res = sin(a);
          push(&calc, res);
          break;
        case 'C':
          a = pop(&calc);
          res = cos(a);
          push(&calc, res);
          break;
        case 'T':
          a = pop(&calc);
          res = tan(a);
          push(&calc, res);
          break;
        case 'O':
          a = pop(&calc);
          res = acos(a);
          push(&calc, res);
          break;
        case 'A':
          a = pop(&calc);
          res = asin(a);
          push(&calc, res);
          break;
        case 'N':
          a = pop(&calc);
          res = atan(a);
          push(&calc, res);
          break;
        case 'Q':
          a = pop(&calc);
          res = sqrt(a);
          push(&calc, res);
          break;
        case 'L':
          a = pop(&calc);
          res = log(a);
          push(&calc, res);
          break;
        case 'G':
          a = pop(&calc);
          res = log10(a);
          push(&calc, res);
          break;
        default:
          break;
      }
    }

    token = strtok(NULL, " ");  // Получаем следующий токен
  }
  return peek(&calc);
}
