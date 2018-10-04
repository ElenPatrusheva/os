#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int value;
	struct node* next;

}node;
typedef struct list{
	struct node* head;
}list;
/*prints 
 * */
void print_list(list ** mylist){
	node * current = (*mylist)->head;
	while (current != NULL){
		printf("%d ", current->value);
		current = current->next;
	}
	printf ("\n");
}
/*inserts a new node vith defined value after the given node if it exists
 * */
void insert_node(node** old, int new_value){
	if (*old == NULL) {
		printf("Given node can not be null\n");
		return;
	}
	else{
		node * k = NULL;
		k = malloc(sizeof(node));
		k->next = (*old)->next;
		k->value = new_value;
		(*old)->next = k;
	}
}
/*delete a certain node from a certain list if it exists
 * */
void delete_node(list ** l, node ** n){
	if ((*l)->head == NULL){
		printf("The list is already empty\n");
		return;
	}
	if (*n == NULL){
		printf("You can not delete NULL node\n");
		return;
	}
	if ((*l)->head == *n){
		(*l)->head = (*l)->head->next;
		return;
	}
	node * current = (*l)->head;
	while(current->next != NULL && current->next != *n ){
		current = current->next;
	}
	if (current->next == NULL){
			printf ("There is no such node in the list\n");
			return;
	}
	current->next = current->next->next;
}
int main(){
	node * head = NULL;
	head = malloc(sizeof(node));
	head->value = 1;
	head->next = NULL;
	list * mylist = NULL;
	mylist = malloc(sizeof(list));
	mylist->head = head;
	print_list(&mylist);
	insert_node(&head, 2);
	print_list(&mylist);
	insert_node(&(head->next), 3);
	print_list(&mylist);
	insert_node(&head, 4);
	print_list(&mylist);
	insert_node(&(mylist->head->next->next),5);
	print_list(&mylist);
	delete_node(&mylist, &(mylist->head));
	print_list(&mylist);
	delete_node(&mylist, &(mylist->head->next));
	print_list(&mylist);		
	node * not_in_list = malloc(sizeof(node));
	not_in_list->value = 6;
	not_in_list->next = NULL;
	delete_node(&mylist, &not_in_list);
	delete_node(&mylist, &(mylist->head->next));
	print_list(&mylist);
	delete_node(&mylist, &(mylist->head->next));
	print_list(&mylist);
	return 0;
}
