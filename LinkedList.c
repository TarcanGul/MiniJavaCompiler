
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {
	
	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");
	char * enumList[3] = {"INT", "STR", "BOOL"};
	e = list->head;
	while (e != NULL) {
		switch(e->type)
		{
			case INT:
			{
				if(e->real_value != NULL) 
					printf("(%s, %d, INT)", e->value, *((int*)e->real_value));
				else
					printf("(%s, NULL, INT)", e->value);
			 	break;
			}
			case STR:
			{ 
				if(e->real_value != NULL)
					printf("(%s, %s, STR)", e->value, *(char*)e->real_value);
				else 
					printf("(%s, NULL, STR)", e->value);
			 	break;
			}
			case BOOL:
			{
				if(e->real_value != NULL)
					printf("(%s, %d, BOOL)", e->value, *(int*)e->real_value); 
				else 
					printf("(%s, NULL, BOOL)", e->value);
				break;
			}
			default: printf("Error, type not recognized.", e->value, e->real_value); break;

		}

		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

void llist_add_node(LinkedList * list, ListNode * n)
{
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}


//
// Appends a new node with this value at the beginning of the list. Use with variables only!
//
void llist_add(LinkedList * list, char* value, enum type type, void *real_value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	n->type = type;
	n->real_value = real_value;
        n->symbol_type = VAR;
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

void llist_addValue(LinkedList * list, char *value, void * real_value)
{
	ListNode * n = list->head;
	while(n != NULL)
	{
	  if(!strcmp(n->value, value))
	  {
	    n->real_value = real_value;
	    return;
	  }
	  n = n->next;
	}
}

void * llist_find(LinkedList * list, char* value)
{
        if(list == NULL) return NULL;
	if(!llist_exists(list, value)) //Not declared.
        {
		return NULL;
        }

	ListNode * n = list->head;
	while(n != NULL)
	{
	  if(!strcmp(n->value, value))
	  {
		if(n->real_value == NULL)
		{
			//Not defined yet.
			return NULL;
		}
		else
		{
			return n->real_value;
		}
	  }
	  n = n->next;
	}
	return NULL; //Element not found
}

ListNode * llist_find_node(LinkedList * list, char* value)
{
	if(!llist_exists(list, value))
	{
		return NULL;
	}
	ListNode * n = list->head;
	while(n != NULL)
	{
	  if(!strcmp(n->value, value))
	  {
		 return n;
	  }
	  n = n->next;
	}
	return NULL; //Element not found
}


//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, char* value) {
	ListNode *i = list->head;
	while(i)
	{
		if(!strcmp(i->value, value))return 1;
		
		i = i->next;
	}
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, char* value) {
	ListNode *prev = NULL;
	ListNode *n = list->head;
	int i = 0;
	while(n)
	{
		if(!strcmp(n->value, value))
		{
			if(i == 0)
			{
				list -> head = list->head->next;
				free(n);
				return 1;
			}	
			else
			{
				prev->next = n->next;
				free(n);
				return 1;		
			}
		}
		prev = n;
		n = n->next;
		i = 1;
	}
	return 0;
}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, char** value) {
	ListNode *n = list -> head;
	int i = 0;
	while(n)
	{
		if(ith != i)
		{
			i++;
			n = n->next;
		}
		else
		{
			*value = n->value;
			return 1;
		}
		
	}
	return 0;
}

//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
	ListNode *prev = NULL;
	ListNode *n = list->head;
	int c = 0;
	while(n)
	{
		if(ith == 0)
		{
			list -> head = list->head->next;
			free(n);
			return 1;
		}	
		else if(ith == c)
		{
			prev->next = n->next;
			free(n);
			return 1;		
		}
			
		prev = n;
		n = n->next;
		c++;
	}
	return 0;
}

int llist_remove_ith_withoutfree(LinkedList * list, int ith) {
	ListNode *prev = NULL;
	ListNode *n = list->head;
	int c = 0;
	while(n)
	{
		if(ith == 0)
		{
			list -> head = list->head->next;
		
			return 1;
		}	
		else if(ith == c)
		{
			prev->next = n->next;
			
			return 1;		
		}
			
		prev = n;
		n = n->next;
		c++;
	}
	return 0;
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	if(!(list->head)){return 0;}
	ListNode *n = list->head;
	
	int c = 0;
	
	while(n)
	{
		c++;
		n = n->next;
	}
	return c;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {

	FILE *fd; 
	if(strcmp(file_name, "/notallowed") == 0){return 0;}
	else{
	
	fd = fopen(file_name, "w");
	ListNode *n = list->head;
	while(n != NULL)
	{
		fprintf(fd, "%s\n",n->value);
	
		n = n->next;
	}	
	fclose(fd);
		
	return 0;
	}

}
void llist_clear(LinkedList *list)
{
	for(int i = 0; i < llist_number_elements(list); i++)
	{
		llist_remove_ith(list, llist_number_elements(list) - i - 1);
	}
	llist_init(list);
	
}

void llist_insert_ith(LinkedList *list, int i, char* value)
{
	
	ListNode *new = (ListNode *) malloc(sizeof(ListNode));
	new->value = value;
	if(i == 0)
	{

		new->next = list->head;
		list->head = new;
	}
	else{
	
	ListNode *prev = NULL;
	ListNode *m = list->head;
	int c = 0;
	while(c < i)
	{
		prev = m;
		m = m->next;
		c++;
	}
	prev->next = new;
	new->next = m;
	}
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//



//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
	int n = llist_number_elements(list);

	if(n == 1 || n == 0){return;}
	ListNode *a = list->head;
	ListNode *prev = NULL;
	ListNode *node;
	ListNode *nex;
	ListNode *b;
	if(ascending)
	{
		for(int i = 0; i < n-1; i++)
		{
			a = list->head;
				
			for(int j = 0; j < n-i-1; j++)
			{
				node = a;
				nex = a->next;

				if(node->value > nex->value){
					b = nex;	
							
					node->next = nex->next;
					nex->next = node;
					if(j == 0)
					{
						list->head = b;
					}
					else
					{
						prev->next = nex;		
					}
					prev = nex;
					
				}
				else
				{
					prev = a;
					a = a->next;
				}
					
			}
		}
	}
	else
	{
		for(int i = 0; i < n-1; i++)
		{
			a = list->head;
				
			for(int j = 0; j < n-i-1; j++)
			{
				node = a;
				nex = a->next;

				if(node->value <  nex->value){
					b = nex;	
							
					node->next = nex->next;
					nex->next = node;
					if(j == 0)
					{
						list->head = b;
					}
					else
					{
						prev->next = nex;		
					}
					prev = nex;
					
				}
				else
				{
					prev = a;
					a = a->next;
				}
					
			}
		}
		
	}
	
}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, char** value) {
	if(list->head){
	ListNode *n = list->head;
	*value = n->value;	
	llist_remove_ith(list, 0);
	return 1;
	}
	else
	{
		return 0;
	}

}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, char** value) {
	if(list->head){
	int i = 0;
	ListNode *p = NULL; //prev
	ListNode *n = list->head;
	while(n != NULL)
	{	
		i++;
		p = n;
		n = n->next;
	}
	*value = p->value;
	llist_remove_ith(list, i-1);
	return 1;
  	}
	else
	{
		return 0;
	}
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, char* value) {
	llist_insert_ith(list, 0, value);
	
	
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, char* value) {
	int n = llist_number_elements(list);
	llist_insert_ith(list, n, value);
}

//
// Clear all elements in the list and free the nodes
//

