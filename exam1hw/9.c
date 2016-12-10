

//#include <sllist.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct SLList {
  char * name;
  struct SLList *next;
}

struct SLList *head = NULL;

void addToList(char *name) {
  SLList *e = head;

  if (e == NULL) {
    SLList *head = (SLList *) malloc(sizeof(SLList));
    head->next = NULL;
    head->name = name;
  }
  else {
    SLList *new = (SLLIst *) malloc(sizeof(SLLIst));
    new->name = name;
    new->next = head;
    head = new;
  }
}

void printList() {
  SLList *e = head;

  while (e != NULL) {
    printf("%s", e->name);
    e = e->next;
  }
  printf("\n");
}

void addToEnd(char * name) {
  SLLIst *e = head;
  SLList *last = head;
  while (e->next != NULL) {
    last = e;
    e = e->next;
  }
  
  SLList *new = (SLList *) malloc(sizeof(SLList));
  new->name = name;
  new->next = NULL;
  if (last == NULL) {
    head=new;
  }
  else {
    last->next = new;
  }

}

int remove (char *name) {
	if (head == NULL) {
	  return NULL;
	}

	SLList *e = head;
	SLList *last = head;
	
	while (e != NULL) {
	  if ((strcmp(name, e->name)) == 0) {
	    
}

char *removeFirst() {
	if(head == NULL) {
	  return NULL;
	}
	char *string = head->name;
	head = e->next;
	return string;

}

char *removeLast() {
	if (head == NULL) {
	  return NULL;
	}
	SLList *e = head;
	SLList *last = head;
	while (elem->next != NULL) {
	  last = e;
	  e = e->next;
	}
	last->next = NULL;
	return e->name;
}

int main() {
  //Test
  //
  addToList("abc");
  addToList("xyz");
  addtoEnd("hello");
  addToEnd("qqq");
  printlist();

}
