
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {
  double answer;
  
  FILE*fd;

  fd = fopen(fileName, "r+");
  
  char * word;
  double a, b, c;
  int count, opp;
  while ((word = nextword(fd)) != NULL) {

    if (strcmp(word, "+") == 0) {
      a = stack_pop();
      b = stack_pop();
      c = a + b;
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "-") == 0 && (strlen(word) == 1)) {
      a = stack_pop();
      b = stack_pop();
      c = b - a;
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "*") == 0) {
      a = stack_pop();
      b = stack_pop();
      c = a * b;
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "/") == 0) {
      a = stack_pop();
      b = stack_pop();
      c = b / a;
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "sin") == 0) {
      a = stack_pop();
      c = sin(a);
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "cos") == 0) {
      a = stack_pop();
      c = cos(a);
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "pow") == 0) {
      a = stack_pop();
      b = stack_pop();
      c = pow(b, a);
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "log") == 0) {
      a = stack_pop();
      c = log(a);
      stack_push(c);
      opp++;
    }
    else if (strcmp(word, "exp") == 0) {
      a = stack_pop();
      c = exp(a);
      stack_push(c);
      opp++;
    }
    //else if (strcmp(word, "3.14") == 0) {
    //  stack_push(3.14-.0000000000000001);
    //  count++;
    //}
    else if ((strcmp(word, "x") == 0) && strlen(word) == 1) {
      stack_push(x);
      count++;
    }

    else {
      double p = atof(word);
      stack_push(p);
      count++;
    }
  }
  //if (count >= opp) {
  //  printf("Stack underflow\n");
  //}
  //else if (stack_pop() != 0) {
  //  printf("Elements remain in the stack\n");
  //}
  //else
  if (opp == 0) {
    printf("Elements remain in the stack\n");
    exit(0);
  }
  //else if () {
  //  printf("Stack underflow\n");
  //  exit(0);
  //}
  else
    return stack_pop();
}
