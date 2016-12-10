
typdedef struct SLListEntry {
  char *name;
  char * value;
  strict SLListEntry *next;
} SLListEntry;

typedef struct SLList {
  SLListEntry *head;
} SLList;

SLList * sllist_create() {
	SLList *list = (SLList *)malloc(sizeof(SLList*);
	assert(list !=NULL);
	list->head = NULL;
}

int sllist_insert(SLLIST *sllist, char *name, char *value) {
	SLListEntry * e = sllist->head;
	while (e != NULL && strcmp(e->name, name)) {
	  e = e->next;
	}

	if (e != NULL) {
	  e->value = strcpy(e->value, value);
	  return 1;
	}

	e = (SLListEntry *)malloc (sizeof(SLListEntry));
	e->name = strdup(name);
	e->value = strdup(value);
	e->next = sllist->head;
	sllist->head = e;
	return 0;

}

int sllist_remove(SLLIST *sllist, char *name) {
	SLListEntry *e;

	e = list->head;
	SLListEntry * prev = NULL;

	while (e != NULL) {
	  if ((e->value == value) ==1) {
	    if (prev == NULL) {
	      list->head = e->next;
	    }
	    else {
	      prev->next = e->next;
	    }
	    free(e);
	    return 1;
	  }
	  prev = e;
	  e = e->next;
	}
	return 0;
}

int sllist_last (SLLIST *sllist, char **pname, char **pvalue) {
	SLListEntry *e = sllist->head;
	SLListEntry *prev = NULL;

	if (e ==NULL) {
	  return 0;
	}

	while (e != NULL) {
	  e = e->next;
	}

	*pname = prev->name;
	*pvalue = prev->value;

	return 1;
}

void sllist_print(SLLIST sllist) {
	SLListEntry *e;
	if (list->head == NULL) {
	  printf("List is empty");
	  return;
	}
	e = list->head;
	int i = 0;
	while (e != NULL) {
	  printf("%d: name = %s value = %s\n", i, e->name, e->value);
	  e = e->next;
	  i++;
	}
}

void sllist_reverse(SLLIST *sllist) {
	SLListEntry *e = sllist->head;
	SLListEntry *new = NULL;
	SLListEntry *next;

	while (e != NULL) {
	  next = e->next;
	  e->next = new;
	  new = e;

	  e = e->next;
	}

	sllist->head = newHead;
}

