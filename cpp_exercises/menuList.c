#include <stdio.h>
#include <stdlib.h>

struct node {
  int x;
  struct node *previous;
  struct node *next;
};

struct node listNew() {
	struct node *root = 0;
	root = (struct node *) malloc(sizeof(struct node));
	root->next = 0;
	root->previous = 0;
	return root;
}

bool listAdd(stuct node *list, int x) {
	if ()

}

int main(void) {
	struct node *root = 0;
	root = (struct node *) malloc(sizeof(struct node)); 
	root->x = 5;
	return 0;
}
