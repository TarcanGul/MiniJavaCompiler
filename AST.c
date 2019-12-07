#include "AST.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
/*Helper methods*/
void debug(){/*This empty method is useful in pinpoint gdb when to stop.*/}

void add_var_decl(struct var_decl_list_t * list, struct var_decl_t * decl)
{
  assert(decl != NULL);
  if(list->id_list == NULL)
  {
	list->id_list = decl;
  }
  else
  {
  	struct var_decl_t * it = list->id_list;
	while(it->next)
	{
		it = it->next;
	}
	it->next = decl;
  }
  list->len++;
}

int find_index_len(index_list_t * list)
{
  int result = 0;
  index_t * it = list->sentinel->next;
  while(it != list->sentinel)
  {
    result++;
    it = it->next;
  }
  return result;
}


char* extract_string(char* str)
{
	int len = strlen(str);
	char * result = (char *) malloc((len-1) * sizeof(char));
	strncpy(result, &str[1], len-2);
	result[len-2] = 0;
	return result;
}

/*Expression node methods*/
struct exp_node * create_exp_node(enum op operation, struct exp_node * left, struct exp_node * right)
{
  struct exp_node * new_node = (struct exp_node *) malloc(sizeof(struct exp_node));
  //Trying to set type
  new_node->operation = operation;
  new_node->data.left = left;
  new_node->data.right = right;
  new_node->is_leaf = 0;
  new_node->has_temp_var = 0;
  new_node->is_method = 0;
  return new_node;
}


struct exp_node * create_id_leaf(char * ID)
{
  struct exp_node * newNode = (struct exp_node *) malloc(sizeof(struct exp_node));
  newNode->is_id = 1;
  newNode->is_leaf = 1;
  newNode->is_array = 0;
  newNode->operation = UNDEF;
  newNode->has_temp_var = 0;
  newNode->data.var_name = ID;
  return newNode;
}

/*struct exp_node * create_id_array_type(char * ID, enum type type)
{
  struct exp_node * newNode = (struct exp_node *) malloc(sizeof(struct exp_node));
  newNode->is_id = 1;
  newNode->is_leaf = 1;
  newNode->operation = UNDEF;
  newNode->data.var_name = ID;
  newNode->type = type;
  return newNode;
}*/


struct exp_node * create_string_leaf(char* string)
{
  struct exp_node * new_node = (struct exp_node *) malloc(sizeof(struct exp_node));
  new_node->data.value = (void *) string;
  new_node->type = STR;
  new_node->operation = UNDEF;
  new_node->is_leaf = 1;
  new_node->is_id = 0;
  new_node->is_array = 0;
  new_node->has_temp_var = 0;
  new_node->current_value = (void * ) string;
  return new_node; 
}

struct exp_node * create_int_leaf(int * value)
{
  struct exp_node * newNode = (struct exp_node *) malloc(sizeof(struct exp_node));
  newNode->data.value = (void *) value;
  newNode->type = INT;
  newNode->operation = UNDEF;
  newNode->is_id = 0;
  newNode->is_leaf = 1;
  newNode->is_array = 0;
  newNode->has_temp_var = 0;
  newNode->current_value = (void *) value;
  return newNode;
}

struct exp_node * create_bool_leaf(int value)
{
  struct exp_node * newNode = (struct exp_node *) malloc(sizeof(struct exp_node));
  int * val_in_mem = (int *) malloc(sizeof(int));
  *val_in_mem = value;
  newNode->data.value = (void *) val_in_mem;
  newNode->type = BOOL;
  newNode->operation = UNDEF;
  newNode->is_id = 0;
  newNode->is_leaf = 1;
  newNode->is_array = 0;
  newNode->has_temp_var = 0;
  newNode->current_value = (void *) val_in_mem;
  return newNode;
}

struct exp_node * create_array_leaf(enum type type, index_list_t * dimensions, void * init_value)
{
  struct exp_node * node = (struct exp_node *) malloc(sizeof(struct exp_node));
  node->operation = UNDEF;
  node->is_array = 1;
  node->is_id = 0;
  node->is_leaf = 1;
  node->type = type;
  node->data.dimensions = dimensions;
  node->data.dim_len = find_index_len(dimensions);
  node->type = type;
  node->has_temp_var = 0;
  void * main_pointer;
  void * last_value;
  index_t * it = dimensions->sentinel->prev;
  int total_alloc_size = 1;
  node->current_value = NULL;
  return node;
}


struct exp_node * create_array_entry_leaf(char * array_name, index_list_t * index, void * init_value)
{
  struct exp_node * node = (struct exp_node *) malloc(sizeof(struct exp_node));
  array_entry_t * array_entry = (array_entry_t *) malloc(sizeof(array_entry_t));
  node->operation = UNDEF;
  array_entry->array_name = array_name;
  array_entry->index = index;
  node->is_leaf = 1;
  node->is_array = 0;
  node->is_array_entry = 1;
  node->is_id = 0;
  node->data.array_entry = array_entry;
  node->has_temp_var = 0;
  return node;
}

/*Statement list methods*/
//
// Initialize a linked list
//
void slist_init(stmt_node_t * list)
{
	list->type = LIST;
	list->list_head = NULL;
}


//
// Appends a new node with this value at the beginning of the list
//
void slist_add(stmt_node_t * list, stmt_node_t * node) {
	assert(list->type == LIST);
	if(list->list_head == NULL)
	{
		list->list_head = node;
	}
	else
	{
		stmt_node_t * it = list->list_head;
		while(it->next)
		{
		  it = it->next;
		}
		it->next = node;

	}
	// Add to the end of the list
	/*if(list->list_head == NULL)
	{
	  list->list_head = node;
	}
	else
	{
	  node->next = list->list_head;
	  list->list_head = node;
	}*/

}

void slist_add_next(stmt_node_t * list, stmt_node_t* next_to, stmt_node_t * to_add)
{
	assert(list->type == LIST);
	stmt_node_t * it = list->list_head;
	while(it != NULL && it != next_to)
	{
		it = it->next;	
	}
	assert(it != NULL);
	if(next_to->next == NULL)
	{
		next_to->next = to_add;
	}
	else
	{
		stmt_node_t * right = it->next;
		next_to->next = to_add;
		assert(to_add->next == NULL);
		to_add->next == right;
	}
}

/*Expression list methods*/
void elist_init(exp_node_list_t * list)
{
	list->head = NULL;
}

void elist_add(exp_node_list_t * list, exp_node_link_t * node) {
	assert(list != NULL);	
	// Add at the end of the list
	if(list->head == NULL)
	{
	  list->head = node;
	}
	else
	{
	  exp_node_link_t * it = list->head;
	  while(it->next)
	  {
	     it = it->next;
 	  }
	  it->next = node;
	}
}

void elist_clear(exp_node_list_t * list)
{
   exp_node_link_t * it = list->head;
   exp_node_link_t * prev = NULL;
   while(list->head != NULL)
   {
	while(it->next)
	{
		prev = it;
		it=it->next;
	}
	prev->next = NULL;
	free(it);
	it = list->head;
	prev = NULL;
   }
   return;
}

void index_list_add(index_list_t * list, index_t * index)
{
  if(list->sentinel == NULL)
  {
		list->sentinel = (index_t *) malloc(sizeof(index_t));
		list->sentinel->size = NULL;
		list->sentinel->next = index;
		list->sentinel->prev = index;
		index->next = list->sentinel;
		index->prev = list->sentinel;
  }
  else
  {
		index_t * it = list->sentinel->next;
		while(it->next != list->sentinel)
		{
			it = it->next;
		}
		it->next = index;
		index->prev = it;
		index->next = list->sentinel;
		list->sentinel->prev = index;
  }
}

void scope_add(scope_list_t * list, scope_t * scope)
{
  if(list == NULL)
  {
	list = (scope_list_t *) malloc(sizeof(scope_list_t));
	list->head = scope;
  }
  else
  {
	scope_t * it = list->head;
	while(it->next != NULL)
	{
		it = it->next;
	}
	it->next = scope;
  }
}

/**/
void scope_inherit(scope_t * parent, scope_t * child)
{
  if(child != NULL && child->name_table != NULL && child->name_table->head != NULL)//It is already inherited. Skip.
  { return; }
  LinkedList * parent_list = parent->name_table;
  ListNode * it = parent_list->head;
  while(it != NULL)
  {
    ListNode * node = (ListNode *) malloc(sizeof(ListNode));
    node->value = it->value;
    node->real_value = it->real_value;
    node->dim_capacity_list = it->dim_capacity_list;
    node->type = it->type;
    node->next = it->next;
    node->symbol_type = it->symbol_type;
    llist_add_node(child->name_table, node);
    it=it->next;
  }
  child->parent = parent;
}

void scope_inherit_updates(scope_t * parent, scope_t * child)
{
  if(parent == NULL) return;
  if(child->updated) return;
  LinkedList * updated_list = parent->name_table;
  ListNode * it = updated_list->head;
  while(it)
  {
	ListNode * updated_node = llist_find_node(updated_list, it->value);
	llist_addValue(child->name_table, it->value, updated_node->real_value);
        it = it->next;
  }
  child->updated = 1;
}

int scope_has(scope_list_t * list, scope_t * scope)
{
  if(list == NULL) return 0;
  scope_t * it = list->head;
  while(it != NULL)
  {
    if(it == scope)
    {
	return 1;
    }
  }
  return 0;
}
