//use pointer to free node one by one 
#include<stdio.h>
#include<stdblib.h>
typedef struct list _item
{
	int data;
	struct list_item *next;
}
void erase_list(list_item *head)//give the function a *head which need to free
{
	list_item *current =head;
	list_item *new ;

	while(list_item *current != NULL)
	{
		new = current->next;
		free(current);
		current = new;
	}
}


