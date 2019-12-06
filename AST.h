#pragma once
#include "LinkedList.h"
typedef enum op {ASGN, ADD, SUB, MUL, DIV, PLU, MIN, 
AND, OR, SME, LRE, EQU, NEQ, LE, GR, NGT, IN, UNDEF};
typedef enum stmt_type {PRO, LIST, IF, WHILE};

struct if_node;
struct stmt_node;
struct while_node;
struct index;
struct index_list;
struct array_entry;
struct scope;
struct scope_list;
struct method;
struct class_s;

typedef enum label_purpose
{
	TRUE_P = 0,
	FALSE_P = 1,
	WHILE_P = 2,
	ENDIF_P = 3,
	ENDWHILE_P = 4
} label_purpose_t;
  

//Type info is the struct for Type and PrimeType. Can also tell if a type is array. 
typedef struct type_info 
{
  int dim_len;
  enum type type;
  char * class_id; //Only useful when type is class.
} type_info_t;

/*Nodes*/
struct exp_node
{
  enum op operation;
  enum symbol_type symbol_type;
  enum type type;
  int dim_len;
  int line_num;
  int is_id;
  int is_leaf;
  int is_array;
  int is_array_entry;
  int is_property;
  int is_method;
  int has_temp_var;
  int is_constructed; //Having "new Object()" where we have to malloc. 
  //Length of each dimension. 0 means 1st dimension ans so on.
  union data
  {
    struct
    {
	struct exp_node * left;
	struct exp_node * right;
    };
    struct
    {
	int dim_len;//Number of dimensions.
	struct index_list * dimensions;	
    };
    struct method * method;
    struct class_s * class_data;
    struct array_entry * array_entry;
    char * var_name;
    void * value;
  } data;
  //Keeping state of current value.
  void * current_value;
  char * associated_class;
  char * temp_var;
  char * assembly_code;
  struct exp_node * next;
};

typedef struct exp_list
{
  struct exp_node * head;
} exp_list_t;

typedef struct exp_node_link
{
  struct exp_node * current;
  struct exp_node_link * next;
} exp_node_link_t;

typedef struct exp_node_list
{
  exp_node_link_t * head;
} exp_node_list_t;

typedef void (*runnable)(void *);

typedef struct stmt_node 
{
  enum stmt_type type;
  union
  {
    runnable invoke;  
    struct if_node * if_node;
    struct while_node * while_node;
    struct stmt_node * list_head;
  };
  void * arg; 
  struct stmt_node * next;
  struct scope_list * child_scopes;
  struct scope * scope;
  int arg_is_expr;
  int line_no;	
} stmt_node_t;



/*Nonterminal types.*/

struct var_decl_t
{
  char * id;
  struct exp_node * value;
  int line_num;
  enum type type;
  struct var_decl_t * next;
};

struct var_decl_list_t 
{
  int len;
  struct var_decl_t * id_list;
  char * class_id;
  type_info_t * type;
};

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


typedef struct method
{
  char * id;
  argument_list_t * arg_list;
  stmt_node_t * statement;
  type_info_t * type;
  struct method * next;
} method_t;

typedef struct method_list
{
  method_t * head;
} method_list_t;

typedef struct class_s
{
  //struct var_decl_list * properties;
  //method_list_t * methods;
  char * id;
  method_t * constructor;
  struct scope * scope;
  struct class_s * next;
} class_t;

typedef struct class_list
{
  class_t * head;
} class_list_t;

typedef struct index
{
  struct exp_node * size;
  struct index * next;
  struct index * prev;
} index_t;

typedef struct index_list
{
  index_t * sentinel;
} index_list_t;

typedef struct array_entry
{
	char * array_name;
	struct index_list * index;
} array_entry_t;

typedef struct if_node
{
  struct exp_node * expression; 
  stmt_node_t * if_list;
  stmt_node_t * else_list;
} if_node_t;

typedef struct while_node
{
  struct exp_node * expression; 
  stmt_node_t * list;
} while_node_t;

typedef struct scope 
{
  LinkedList * name_table;
  struct scope * parent;
  int updated; //This is for the inherit_updates function to trigger only once for the scope.
  struct scope * next; //For using in the scope_list
} scope_t;

typedef struct scope_list
{
  struct scope * head;
} scope_list_t;

typedef struct program
{
  class_t * main_class;
  class_list_t * class_list;
} program_t;

void slist_init(stmt_node_t * list);
void slist_print(stmt_node_t * list);
void slist_add(stmt_node_t * list, stmt_node_t * node);
int slist_remove(stmt_node_t * list, stmt_node_t * node);
void slist_add_next(stmt_node_t * list, stmt_node_t* next_to, stmt_node_t * to_add);

void varlist_print(struct var_decl_list_t * list);

void add_var_decl(struct var_decl_list_t * list, struct var_decl_t * decl);

struct exp_node * create_exp_node(enum op type, struct exp_node * left, struct exp_node * right);
struct exp_node * create_id_leaf_type(char* ID, enum type type);
struct exp_node * create_id_leaf(char* ID);
struct exp_node * create_int_leaf(int *value);
struct exp_node * create_string_leaf(char *string);
struct exp_node * create_bool_leaf(int value);
struct exp_node * create_array_leaf(enum type type, index_list_t * dimensions, void * init_value);
struct exp_node * create_array_entry_leaf(char * array_name, index_list_t * index, void * init_value);

void elist_init(exp_node_list_t * list);
void elist_add(exp_node_list_t * list, exp_node_link_t * node);
void elist_clear(exp_node_list_t * list);
int scope_has(scope_list_t * list, scope_t * scope);
void scope_add(scope_list_t * list, scope_t * scope);
void scope_inherit(scope_t * parent, scope_t * child);
void scope_inherit_updates(scope_t * parent,  scope_t * child);
void index_list_add(index_list_t * list, index_t * index);
int find_index_len(index_list_t * list);
void debug();
