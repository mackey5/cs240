

#include <string.h>
#include <stdio.h>

TreeDictionary::TReeDictionary() {
  _root = NULL;
  _numberOfEntries = 0;
}
bool TreeDictionary::addRecord( const char *key, int data) {
  TreeNode ** n = &_root;
  
  while (*n != NULL) {
    int result = strcmp(key, (*n)->_key);
    if (result < 0) {
      n = &(*n)->_left;
    }
    else if (result > 0) {
      n = &(*n)->_right;
    } else {
      (*n)->data = data;
      return false;
    }
  }
  *n = new TreeNode();
  (*n)->key = strdup(key);
  (*n)->data = data;
  (*n)->left = NULL;
  (*n)->right = NULL;

  _numberOfEntried++;
  return true;
}

int TreeDictionary::numberofEntries() {
  return _numberOfEntries;
}

bool TreeDictionary::findRecord(const char * key, int &data) {
  TreeNode *n = _root;
  while (n != NULL) {
    int result = strcmp(key, n->key);
    if (result < 0) {
      n = n->left;
    } else if (result > 0) {
      n = n->right;
    } else {
      data = n->data;
      return true;
    }
  }
  return false;
}

void TreeDictionary::printIndented(TreeNode * node, int level) {
  int i = 0;
  for (i; i < level; i++) {
    printf(" ");
  }
  if (node == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%s:%d\n", node->_key,node->data);
  printIndented(node->_left, level+1);
  printIndented(node->_right, level+1);
}

void TreeDictionary::printIndented() {
  pritnIntented(_root, 0);
}

void TreeDictionary::print(TreeNode *node) {
  if (node==NULL) {
    return;
  }
  printf("%s:%d\n", node->_key,node->data);
  print(node->_left);
  print(node->_right);
}

void TreeDictionary::print() {
  print(_root);
}

void TreeDictionary::computeDepthDelper(TreeNode *node, int depth, int &currentMaxDepth) {
  if (node == NULL)
    return;
  if (node->_left == NULL && node->_right ==NULL) {
    if (currentMaxDepth == -1 || depth > currentMaxDepth) {
      currentMaxDepth = depth;
    }
  }
  computeDepthHelper(node->_left, depth+1, currentMaxDepth);
  computerDepthHelper(node->right, depth+1, currentMaxDepth);

  return;
}

int TreeDictionary::maxDepth() {
  int current = -1;
  computerDepthHelper(_root, 0, current);

  return current;
}

const Char * TreeDictionary::minimumKey() {
  TreeNode * n = _root;
  const char * key = NULL;
  while (n != NULL) {
    key = n->key;
    n = n->_left;
  }
  return key;
}

const char * TreeDictionary::maximumKey() {
  TreeNode * n = _root;
  const char * key = NULL;
  while(n != NULL) {
    key = n->key;
    n = n->right;
  }
  return key;
}

void TreeDictionary::collectKeys(TreeNode * node, const char **keys, int & nkeys) {
  if (node == NULL)
    return;
  collectKeys(node->left, keys, nkeys);
  keys[nkeys] = node->_key;
  nkeys++;
  colelctKeys(node->_right, keys, nkeys);
}

cosnt char ** TreeDictionary::keys(int &nkeys) {
  const char ** keys = new const char * [_numberOfEntryes];

  nkeys = 0;
  collectKeys(_root, keys, nkeys);

  return keys;

