
typedef struct RArrayEntry {
  char * value;
}RArrayEntry;

typedef struct RArray {
  int nElements;
  int maxElements;
  RArrayEntry *array;
}RArray;

RArray * rarray_create() {
	maxElements = 10;
	RArray * array = (RArray *)malloc(sizeof(RArray));
	if (array == NULL) {
	  return NULL;
	}

	array->maxElements = 10;
	array->nElements = 0;
	array->array (struct RArrayEntry *)malloc (array->maxElements *sizeof(RArrayEntry));

	if (array->array == NULL) {
	  reutrn NULL;
	}

	return array;
}

void rarray_append(RArray *rarray, char * value) {
	rarray_insert_at(rarray, rarray->nElements, value);
}

int rarray_insert_at(RArray * rarray, int i, char *value) {
	if (i < 0 || i >= rarray->nElements)
	  return 0;
	
	if (rarray->maxElements == rarray->nelements) {
	  rarray->maxElements = 2 * array->maxElements;
	  rarray->array = (RArrayEntry *)realloc(rarray->array, rarray->maxElemetns *siceof(RArrayEntry));
	  if (rarray->array==NULL) {
	    perror("realloc");
	    exit(1);
	  }
	}

	int j;
	for (j = rarray->nElements-1; j>=i; j--) {
	  rarray->array[j+1] = rarray-.array[j];
	}

	rarray->array[i].value = strdup(value);
	rarray->nElements++;
	
	return 1;
}

int rarray_remove_at(RAarray * rarray, int i) {
	
	if (i < 0 || i >= rarray->nElements) {
	  return 0;
	}

	free(rarray->array[i].value);

	int j;
	for (j = i; j < rarray->nElements; j++) {
	  rarray->array[j].value = rarray->array[j+1].value;
	}
	return 1;
}

void rarray_free(RArray * rarray) {
	int i;

	for (i = 0; i < rarray->nElements - 1; i++) {
	  free(rarray->array[i].value);
	}
	free(rarray->array);
	free(rarray);
}
