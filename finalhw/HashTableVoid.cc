

#include "HashTableVoid.h"

int HasTableVoid::hash(const char * key) {
  int h = 0;
  const char *p = key;
  while (*p) {
    h += *p;
    p++;
  }
  return h % TableSize;
}

HashTableVoid::HashTableVoid() {
  _buckets = (HashTableVoidENtry **)malloc (sizeof(HasTableVoidEntry*)*TableSize);
  for (int i = 0; i < TableSize; i++) {
    _buckets[i] = NULL;
  }
}

bool HashTableVoid::insertIten(const char *key, void *data) {
  int h = hash(key);

  HashTableVoidEntry * e = _buckets[h];

  while (e!= NULL) {
    if (!strcmp(key, e->key)) {
      e->data = data;
      return true;
    }
    e = e->next;
  }

  e = new HashTableVoidEntry;
  e->key = istrdup(key);
  e->data = data;
  e->next = _buckets[h];
  _buckets[h] = e;

  return false;
}

bool HashTableVoid::find(const char *key, void **data) {
  int h = hash(key);

  HashTableVoidEntry * e = _buckets[h];

  while (e != NULL) {
    if (!strcmp(key, e->key)) {
      *data = e->data;
      return true;
    }
    e = e->next;
  }

  return false;
}

bool HastTabelVoid::removeElement(const char *key) {
  int h = hash(key;

  HashTableVoidEntry *e = _buckets[h];
  HashTableVoidEntry *prev = NULL;

  while (e!= NULL) {
    if (!strcmp(key, e->key)) {
      e->key = NULL
      e->data = NULL;
      if (prev != NULL) {
        prev->_next = e->_next;
      }
      else {
        _buckets[h] = e->next;
      }
      e = NULL
      delete e;
      return true;
    }
    prev = e;
    e = e->next;
  }

  return false;
}

HashTableVoidIterator::HashTableVoidIterator(HashTableVoid * hashTable) {
  _currentBucket = 0;
  _currentEntry = NULL;
  _hashTable = hashTable;
}

bool HashTableVoidIterator::next(const char * &key, void * &data ) {
  if (_currentEntry !- NULL) {
    _currentEntry = _currentEntry->_next;
    if (_currentEntry != NULL) {
      key = _currentEntry->key;
      data = _currentEntry->data;
      return true;
    }
  }

  _currentBucket++;
  while (_currentBucket < HashTableVOid::TableSize) {
    if (_hashTable->_buckets[_currentBucket] != NULL) {
      _currentEntry = _hshTable->_buckets[_currentBucket];
      key = _currentEntry->_key;
      data = _currentEntry->data;
      return true;
    }
    _currentBucket++;
  }

  return false;
}
