#include <stdio.h>
#include <stdlib.h>

typedef int KEY_TYPE;

typedef struct Node {
  KEY_TYPE key;
  struct Node *lchild;
  struct Node *rchild;
} Node;

Node *create(void);
void insert(Node *root, KEY_TYPE key);
void search(Node *tree, KEY_TYPE key);
void delete(Node *tree, KEY_TYPE key);
void in_order(Node *tree);

Node *make_node(KEY_TYPE key);

Node *create(void)
{
  Node *tree = NULL;

  KEY_TYPE key;
  char ch;

  scanf("%1d", &key);
  while (key != 0) {
    insert(tree, key);
    scanf("%1d", &key);
  }

  return tree;
}


void insert(Node *root, KEY_TYPE key)
{
  if (root == NULL) {
    root = make_node(key);
    return;
  }

  if (key < root->key) {
    if (root->lchild == NULL) {
      Node *lchild = make_node(key);
      root->lchild = lchild;
    } else {
      insert(root->lchild, key);
    }
  } else if (key > root->key) {
    if (root->rchild == NULL) {
      Node *rchild = make_node(key);
      root->rchild = rchild;
    } else {
      insert(root->rchild, key);
    }
  } else {
    printf("Repeat number\n");
  }
}

void search(Node *tree, KEY_TYPE key)
{

}

void delete(Node *tree, KEY_TYPE key)
{

}

void in_order(Node *tree)
{
  if (tree != NULL) {
    in_order(tree->lchild);
    printf("%d", tree->key);
    in_order(tree->rchild);
  }
}

int
main(void)
{
  Node *tree = create();
  printf("created tree\n");
  in_order(tree);
  return 0;
}

Node *make_node(KEY_TYPE key)
{
  printf("make node %d\n", key);
  Node *node = (Node *) malloc(sizeof(Node));
  node->key = key;
  node->lchild = node->rchild = NULL;
  return node;
}
