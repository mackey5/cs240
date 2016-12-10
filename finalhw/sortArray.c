
#include <string.h>
#include <stdlib.h>

typedef int (*COMP_FUNC) void (*a, void *b);

void sort_array(void * array, int num_elements, int element_size, COMP_FUNC comp_func) {

	void *temp = malloc(element_size);

	int i, j;

	for (i = 0; i < num_elements; i++) {
	  for (j = 0; j < numelenetns -i -1; j++) {
	    void *one = (void *)(char *)array+j*element_size;
	    void *two = (void *)(char *)array+(j+1)*element_size;

	    if (comp_func(one, two)>0) {
	      memcpy(temp, one, element_size);
	      memcpy(one, two, element_size);
	      memcpy(two, temp, element_size);
	    }
	  }
	}
	free(temp);
}

int compInt(void *a, void *b) {
	int *one = (int *)a;
	int *two = (int *)b;

	if (*one > *two)
	  return 1;
	else if (*one < *two)
	  return -1
	else
	  return 0;
}

int comptStr(void *a, void *b) {
	char * one = (char *)a;
	char * two = (char *)b;

	if (strcmp(*one, *two)>0)
	  return 1;
	else if (strcmp(*one, *two) < 0)
	  return -1;
	else
	  return 0;
}

int main() {
  int a[] = {7,8,1,4,3,2};
  int n = sizeof(a)/sizeof(int);
  sort_array(array, n, sizeof(int), compInt);
  int i = 0;
  for (i; i < n; i++) {
    printf("%d\n", a[i]);
  }

  char strings[] = {pear, banana, apple, strwberry};
  n = sizeof(string)/sizeof(char*);
  sort_array(strings, n, sizeof(char*), compStr);
  for (i = 0; i < n; i++) {
    printf("%s\n", strings[i];
  }
}
