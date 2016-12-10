

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  

  char * h = "llo";
  char * a = "Hello";

  //char * ans = contains(a, h);

  printf("%s", mycontains(a,h));

}

  char * mycontains(char * hay, char *needle) {
    
    int i = 0;
    int j = 0;

    char *p = hay;
    char *q = needle;
    char *last = (char *) malloc(sizeof(char *));

    while (p[i] != '\0') {
      last = p;
      while (*p == *q) {
        if (*(q+1) = '\0') {
	  return last;
	}
	p++;
	q++;
	}
      p = last;
      p++;
      q = needle;
    }
    return NULL;
}	  
