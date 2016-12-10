

#include <stdlib.h>
#include <stdio.h>

typeef struct SLEntry {
  int value;
  struct SLEntry * next;
}SLEntry;

struct SLList {
  SLEntry * head;
}

int * list_to_array(SLList, int * n) {
  //Find # of elements in the list
  //
  int i = 0;
  SLENtry * node = list->head;
   while (node != NULL) {
     i++;
     node = node->next;
   }
   //Store length of the array in *n
   //
   *n = i;
   //Create array to store i elements

   int * array = (int *)malloc(i*sizeof(int));
   
   node = list->head;
   i = 0;
   while (node != NULL) {
     array[i] = node->value;
     i++;
     node = node->next;
   }
   return array;
 }

//Using realloc
int *list_to_array(SLList, int * n) {
  int max = 10;
  int current = 0;
  int * array = (int *) malloc(max * sizeof(int));
  //Check to make sure the array was created
  assert(array != NULL);

  SLEntry *node = list->head;

  while (node != NULL) {
    if (i == max) {
      //Array is full
      max = max + max;
      int * array = (int *) realloc(array, max * sizeof(int));
      assert(array != NULL);
    }
    //Memory is good
    array[i] = node->value;
    i++;
    node = node->next;
  }

  *n = i;

  return array;
}





