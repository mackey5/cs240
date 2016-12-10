

#include <stdlib.h>
#include <stdio.h>
//#include <stack.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
  
  int i = 0;
  
  //char **nums = (char**) malloc(sizeof(strlen(str));
  char*str = argv[i];
  char*last = str;
  char **nums = (char **)malloc(sizeof(strlen(str)));

  while (*str != '\0') {
    if (*str == ' ') {
      *str = '\0';
      nums[i] = last;
      i++;
      str++;
      while (*str==' ')
        str++;
      last = str;
    }
    str++;
  }
  nums[i] = last;
  i++;

  double*stack = (double *)malloc(i*sizeof(double));

  int j = 0;
  for (j; j < i; j++) {
    if ((strcmp(nums[j], "+") == 0)) {
      stack--;
      *stack = *stack + *(stack+1);
    }
    else if ((strcmp(nums[j], "-")) == 0) {
      stack--;
      *stack = *stack - *(stack+1);
    }
    else if ((strcmp(nums[j], "/")) == 0) {
      stack--;
      *stack = *stack / *(stack + 1);
    }
    else if ((strcmp(nums[j], "*")) == 0) {
      stack--;
      *stack = *stack * *(stack +1);
    }
    else {
      stack++;
      *stack = atof(nums[j]);
    }
   }
}
