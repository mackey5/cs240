

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isAlph(char ch) {
  if ('A'<=ch<='Z' || 'a'<=ch<='z')
    return 1;
  else 
    return 0;
}
int ispalendrone(char * string) {
  
  int i = 0;
  int len = strlen(string);
  int j = len - 1;
  int n;
  /*if (len % 2 == 1) {
    n = (len - 1) /2;
  }
  else
    n = len / 2;
  */
  for (i; i < n; i++) {
    while (!(isAlph(string[i]))) 
      i++;
    while (!(isAlph(string[j])))
      j--;
    if (j - i == 2) {
      break;
    }
    if (string[i] == string[j]) {
      
    }
    else {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char **argv) {
  
  char *p = argv[1];

  if (ispalendrone(p)) {
    printf("Is palendrone");
  }
  else
    printf("Is not a palendrone");
}
