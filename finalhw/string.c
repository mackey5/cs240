

int strlen(char *str) {
  char * p = str;
  int len = 0;
  while (*p != '\0') {
    len++;
    p++;
  }
  return len;
}


char * strpy(char *dest, char *src) {
  
  while (*src) {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
  return dest;
}

char *strcat(char *dest, char *src) {
	char *p = dest;
	while (*p) {
	  p++;
	}

	char *q = src;
	while (*q) {
	  *p = *q;
	  p++;
	  q++;
	}
	*p = '\0';
	return dest;
}

char * strstr(char *hay, char *needle) {
	while (*hay) {
	  char *p = hay;
	  char *q = needle;

	  while(*p && *q && *p == *q) {
	    p++;
	    q++;
	  }

	  if (*q == '\0')
	    return hay;
	  hay++;
	}

	return NULL;
}
