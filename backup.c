#include <stdlib.h>
#include "mystring.h"

// Type "man string" to see what every function expects.

int mystrlen(char * s) {
	int len = 0;
	while (s[len]!= '\0')
	  len++;
	return len;
}

char * mystrcpy(char * dest, char * src) {
        int i = 0;
	while (src[i] != '\0') {
	  dest[i] = src[i];
	  i++;
	}
	dest[i] = '\0';
	return dest;
}

char * mystrcat(char * dest, char * src) {
        int len = 0;
	int j = 0;
	len = mystrlen(dest);
	while (src[j] != '\0') {
	  dest[len] = src[j];
	  len++;
	  j++;
	}
	dest[len] = '\0';
	return dest;
}

int mystrcmp(char * s1, char * s2) {
	int i = 0;
	int bool = 0;
	if (mystrlen(s1) < mystrlen(s2))
	  return -1;
	while (s1[i] != '\0') {
	  if (s1[i] != s2[i]){
	    bool = 1;
	    break;
	  }
	  i++;
	}
	return bool;
}

