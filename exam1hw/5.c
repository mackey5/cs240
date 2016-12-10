

#include <stdlib.h>
#include <stdio.h>

int main(int argv, char **argc) {
  
  char *string = argc[1];
  int par = 0;
  int brack = 0;
  
  while (*string != '\0') {
    
    if (*string == '(') {
      par++;
    }
    else if (*string == ')') {
      par--;
    }
    else if (*string == '{') {
      brack++;
    }
    else if (*string == '}') {
      brack--;
    }
    string++;
  }

  if (par == 0 && brack == 0) {
    printf("String is balanced");
  }
  else
    printf("String is not balanced");
}
