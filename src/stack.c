#include "stack.h"

#include "calc.h"

// Функция для инициализации стека
void initializeStack(Stack *stack) {
  stack->top = -1;  // Инициализируем стек, указывая на то, что он пуст
}

// Функция для проверки, пуст ли стек
int isEmpty(Stack *stack) {
  return (stack->top == -1);  // Если top = -1, стек пуст
}

// Функция для проверки, полон ли стек
int isFull(Stack *stack) {
  return (stack->top == MAX_SIZE - 1);  // Если top = MAX_SIZE - 1, стек полон
}

// Функция для добавления элемента в стек (помещение на вершину стека)
void push(Stack *stack, double value) {
  if (isFull(stack)) {
    printf("Стек переполнен\n");
    return;
  }
  stack->items[++stack->top] = value;  // Увеличиваем top и добавляем элемент
  printf("%f добавлен в стек\n", value);
}

// Функция для удаления элемента из стека (выталкивание элемента с вершины
// стека)
double pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Стек пуст\n");
    return -1;
  }
  printf("%f удален из стека\n", stack->items[stack->top]);
  return stack->items[stack->top--];  // Возвращаем значение и уменьшаем top
}

// Функция для получения элемента на вершине стека без его удаления
double peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Стек пуст\n");
    return -1;
  }
  return stack->items[stack->top];
}

// void displayStack(Stack *stack) {
//   if (isEmpty(stack)) {
//     printf("Стек пуст\n");
//     return;
//   }
//   printf("Элементы стека: ");
//   int current = 0;
//   while (current <= stack->top) {
//     printf("%f ", stack->items[current]);
//     current++;
//   }
//   printf("\n");
// }
//-------------------------------^функции
//стека--------------------------------------

// Пример использования стека
// int main() {

// char input_str[MAX_SIZE] =
//     "15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))";
// char output[MAX_SIZE];
// rpn(input_str,output);
// //----------------------calc-----------------------
// double result = calc(output);
// printf("%f",result);
// push(&RPN, 10);
// push(&RPN, 20);
// push(&RPN, 30);

// push(&calc, 100);
// push(&calc, 200);
// push(&calc, 300); // Добавление элементов в каждый из стеков

// printf("Элемент на вершине стека 1: %d\n", peek(&RPN));
// printf("Элемент на вершине стека 2: %d\n", peek(&calc));  // Получение
// displayStack(&calc);
// элементов на вершинах каждого стека

// pop(&RPN);
// pop(&calc); // Удаление элементов из обоих стеков

// printf("Элемент на вершине стека 1 после удаления: %d\n", peek(&RPN));
// printf("Элемент на вершине стека 2 после удаления: %d\n", peek(&calc)); //
// Получение элементов на вершинах каждого стека после удаления

// return 0;
//}
