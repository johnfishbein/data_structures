/* jhf5my -- John Fishbein -- Friday 12 April 2019 */
/* linkedlist.c  */

#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node* next;
  int n;
};

struct list {
  struct node * head;
  struct node * tail;
};

int main() {
  int size;
  printf("Enter how many values to input: ");
  scanf("%d", &size);
  int val;
  int i;
  struct list lst;
  struct node * current;
  struct node * previous;
  
  for (i = 1; i <= size; i++){
    printf("Enter value %d: ", i);
    scanf("%d", &val);
    

    current = malloc( sizeof(struct node));
    if (i == 1){
      lst.head = current;
    }else{
      previous->next = current;
    }
    
    current->n = val;
    lst.tail = current;
    previous = current;
    
  }
  
  current = lst.head;
  while (current != NULL){
    printf("%d\n", current->n);
    previous = current;
    current = current->next;
    free(previous);
  }

  
  return 0;
}
