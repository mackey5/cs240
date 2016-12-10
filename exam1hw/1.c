

#include <stdlib.h>
#include <stdio.h>

int main() {
  char cont = 'y';
  printf("Program Fibonaccii\n");
  while (cont == 'y') {
    printf("Input k? ");
    int num;

    scanf("%d", &num);
    int fib;
    int i = 0;
    int first = 0, second = 1;
    if (num == 0) {
      fib = 0;
    }
    else if(num == 1) {
      fib = 1;
    }
    else {
      for (i; i < num - 1; i++) {
        fib = first + second;
        first = second;
        second = fib;
      }
    }

    printf("The %dth Fibonacci number is %d\n",num, fib);
    
    printf("Do you want to continue y/n? ");
    scanf("%s", &cont);
    }
}
