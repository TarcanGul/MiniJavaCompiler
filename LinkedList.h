#pragma once
// Data structs for a list of ints

typedef enum type {INT, STR, BOOL, CLASS, UNKNOWN};
typedef enum symbol_type {VAR, METHOD, PROPERTY, ARG};


//Type info is the struct for Type and PrimeType. Can also tell if a type is array. 
typedef struct type_info 
{
  int dim_len;
  enum type type;
  char * class_id; //Only useful when type is class.
} type_info_t;


typedef struct argument
{
  char * id;
  type_info_t * type;
  struct argument * next;
} argument_t;

typedef struct argument_list
{
  argument_t * head;
} argument_list_t;

struct ListNode {
	char* value;
	void * real_value;
        void * dim_capacity_list;
	enum type type;
	int dim_len;
	char * class_id;
	struct ListNode * next;
	enum symbol_type symbol_type;
	argument_list_t * arg_list; //For methods.
	int offset;
	int reg_number; //For arguments.
};

typedef struct ListNode ListNode;

struct LinkedList {
	ListNode * head;
};

typedef struct LinkedList LinkedList;

void llist_init(LinkedList * list);
void llist_print(LinkedList * list);
void llist_add_node(LinkedList * list, ListNode * node);
void llist_add(LinkedList * list, char* value, enum type type, void * real_value);
void * llist_find(LinkedList * list, char* value);
ListNode * llist_find_node(LinkedList * list, char* value);
/*Add value to a already added entry.*/
void llist_addValue(LinkedList *list, char* value, void * real_value);
int llist_exists(LinkedList * list, char* value);
int llist_remove(LinkedList * list, char* value);
int llist_get_ith(LinkedList * list, int ith, char **value);
int llist_remove_ith(LinkedList * list, int ith);
int llist_number_elements(LinkedList * list);
int llist_save(LinkedList * list, char * file_name);
int llist_read(LinkedList * list, char * file_name);
void llist_sort(LinkedList * list, int ascending);
void llist_clear(LinkedList *list);

int llist_remove_first(LinkedList * list, char ** value);
int llist_remove_last(LinkedList * list, char ** value);
void llist_insert_first(LinkedList * list, char* value);
void llist_insert_last(LinkedList * list, char* value);
