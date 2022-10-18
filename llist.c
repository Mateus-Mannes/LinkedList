#include <stdio.h>
#include <stdlib.h>

// better explanation at https://www.youtube.com/watch?v=zQI3FyWm144&t=1402s

// structure of the node

typedef struct listNode {
    int value;
    struct listNode * next;
} node;

// creates a list with one node
node * create(int value);

// returns true or false, if an element is in the list
int find(node * head, int value);

// insert a new element in the begining of the list and returns a new pointer for the list
node * insert(node * head, int value);

// print all elements
void print(node * head);

// free the memory of the list
void destroy(node * head);

// deletes a specific value from the list
node * delete(node * head, int value);

// just an example:
int main()
{
    node * head = create(5);
    head = insert(head, 7);
    head = insert(head, 89);
    head = insert(head, 34);
    head = insert(head, 6);
    print(head);
    head = delete(head, 34);
    print(head);
    destroy(head);
    return 0;
}

// implementations:

node * create(int value) {
    node * newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void print(node * head) {
    node * ptr = head;
    do {
      printf("%d ", ptr->value);
      ptr = ptr->next;
    } while (ptr != NULL);
    printf("\n");
    return;
}

int find(node * head, int value) {
  node * ptr = head;
  do {
      if(ptr->value == value){
          return 1;
      }
      ptr = ptr->next;
  } while (ptr != NULL);
  return 0;
};

node * insert(node * head, int value) {
    node * newHead = (node *) malloc(sizeof(node));
    newHead->value = value;
    newHead->next = head;
    return newHead;
}

void destroy(node * head) {
    if(head->next != NULL){
        destroy(head->next);
    }
    free(head);
}

node * delete(node * head, int value) {
    node * ptr = head;
    node * prevNode = NULL;
    node * newHead = head;
    do {
        int deletion = 0;    
      if(ptr->value == value){
          deletion = 1;
          node * toDelete = ptr;
          ptr = ptr->next;
          free(toDelete);
          if(prevNode == NULL){
              newHead = ptr;
          }else{
              prevNode->next = ptr;
          }
      }
      if(!deletion){
          prevNode = ptr;
          ptr = ptr->next;
      }
    } while (ptr != NULL);
  return newHead;
}
