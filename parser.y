%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "AST.h"
  #include <assert.h>
  #include <string.h>
  #define YYDEBUG 1
  #define MAXSIZE 50
  #define GLOBAL_STACK_SIZE 200


  int g_label_counter[5] = {0};

  extern int yylex();
  extern int yylineno;
  extern FILE* yyin;
  void yyerror(char const* msg);
  void type_error(int line_num);
  void update_scope_hierarchy(stmt_node_t * stmt);
  stmt_node_t * main_stmt_list;

  //Function prototypes for statements.
  void s_print(void * arg);
  void s_println(void * arg);
  void s_decl(void * arg);
  void s_asgn(void * arg);
  void s_invoke(void * arg);
  void s_return(void * arg);

  //Expression prototypes.
  void * s_add(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_sub(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_mul(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_div(struct exp_node * op1, struct exp_node * op2, enum type type);
  void * s_plu(struct exp_node * op, enum type type);
  void * s_min(struct exp_node * op, enum type type);
  void * s_less(struct exp_node * op1, struct exp_node * op2);
  void * s_greater(struct exp_node * op1, struct exp_node * op2);
  void * s_leq(struct exp_node * op1, struct exp_node * op2);
  void * s_seq(struct exp_node * op1, struct exp_node * op2);
  void * s_neq(struct exp_node * op1, struct exp_node * op2);
  void * s_eq(struct exp_node * op1, struct exp_node * op2);
  void * s_and(struct exp_node * op1, struct exp_node * op2);
  void * s_or(struct exp_node * op1, struct exp_node * op2);
  void * s_negate(struct exp_node * op, enum type type);
  void * s_len(struct exp_node * op);
  int find_value_of_index(index_list_t * index_list, index_list_t * capacity_list);

  class_t * get_class_info(char * class_name);
  struct exp_node * stack[GLOBAL_STACK_SIZE];
  int stack_header = -1;
  stmt_node_t * current_stmt_list = NULL;
  int execute(stmt_node_t * stmt);

  int type_violation_found = 0;
  int construct_name_table = 1; //global var for setting name table.

  scope_t * current_scope;
  scope_t * global_scope;
 
  program_t * program;

  FILE * gen_file;

  char ** data_section = NULL;
  char ** text_section = NULL;
  int calc_method_size(stmt_node_t * list);
  void method_first_codegen(stmt_node_t * list);
  char * generate_label(label_purpose_t purpose);
  char * generate_str_literal();
  void declare_label(char * label);
  static int temp_counter = 0;
  static int str_literal_counter = 0;
  static char * main_args_name = NULL;
%}

%union
{
  char *string_val;
  int integer_val;
  index_list_t * dimension_list;
  struct exp_node *  exp_node;
  struct var_decl_list_t * vardecllist;
  struct var_decl_t * var_decl;
  stmt_node_t * stmt_node;
  type_info_t * type;
  argument_t * method_arg;
  argument_list_t * arg_list;
  method_t * method;
  method_list_t * method_list;
  exp_list_t * exp_list;
  class_t * class;
  class_list_t * class_list;
}


%token  STRING_LITERAL
%token INTEGER_LITERAL
%token ID D_AMPERSAND D_LINES SMALL_EQUAL LARGE_EQUAL D_EQUAL EXC_EQUAL PLUS MINUS STAR SLASH K_CLASS K_INT K_STRING K_BOOLEAN K_IF K_WHILE K_RETURN K_NEW K_THIS K_TRUE K_FALSE K_PRINTLN K_PRINT K_ELSE K_EXTENDS K_PUBLIC K_LENGTH
%token K_STATIC K_VOID K_MAIN
%token LEFT_BRACE RIGHT_BRACE
%token LEFT_PAR RIGHT_PAR
%token LEFT_BRACKET RIGHT_BRACKET
%token EQUAL SEMICOLON COMMA EXC DOT
%token LESS GREATER
%token K_PARSEINT
%start program


%left EQUAL EXC LESS GREATER D_AMPERSAND D_LINES SMALL_EQUAL LARGE_EQUAL D_EQUAL EXC_EQUAL
%left PLUS MINUS 
%left STAR SLASH

%type <string_val> STRING_LITERAL ID Opt_Inheritance
%type <integer_val> INTEGER_LITERAL IndexNoExpr
%type <exp_node> Expression LeftValue ExpressionTail MethodCall
%type <vardecllist> VarDecl VarDeclList VarDeclTail
%type <var_decl> VarLongerDecl
%type <stmt_node> Statement StatementList
%type <type> Type PrimeType
%type <dimension_list> Index
%type <method_arg> FormalListTail
%type <arg_list> FormalList FormalListTailList Opt_FormalList
%type <method> MethodDecl MethodDeclWithPublic
%type <method_list> MethodDeclList
%type <exp_list> ExpressionList Opt_ExpressionList ExpressionTailList
%type <class> MainClass ClassDecl
%type <class_list> ClassDeclList

%%
program : MainClass ClassDeclList
{
        program_t * cur_prog = (program_t *) malloc(sizeof(program_t));
	cur_prog->main_class = $1;
	cur_prog->class_list = $2;
	program = cur_prog;
};

Expression : 
	Expression PLUS Expression 
	{
	  	  struct exp_node * add_node = create_exp_node(ADD, $1, $3);
		  add_node->type = $1->type;
		  add_node->line_num = yylineno;
	  	  $$ = add_node;

	}
	| Expression MINUS Expression 
	{
	  	  struct exp_node * sub_node = create_exp_node(SUB, $1, $3);
		  sub_node->type = $1->type;
		  sub_node->line_num = yylineno;
		  $$ = sub_node;

	}
	| Expression D_AMPERSAND Expression
	{

 	 	  struct exp_node * node = create_exp_node(AND, $1, $3);
		  node->type = $1->type;
		  node->line_num = yylineno;
	  	  $$ = node;
	} 
	| Expression D_LINES Expression
	{

 	 	  struct exp_node * node = create_exp_node(OR, $1, $3);
		  node->line_num = yylineno;
		  node->type = $1->type;
	  	  $$ = node;
	}
	| Expression SMALL_EQUAL Expression
	{
 	 	  struct exp_node * node = create_exp_node(SME, $1, $3);
		  node->line_num = yylineno;
		  node->type = $1->type;
	  	  $$ = node;
	} 
	| Expression LARGE_EQUAL Expression
	{

 	 	  struct exp_node * node = create_exp_node(LRE, $1, $3);
		  node->line_num = yylineno;
		  node->type = $1->type;
	  	  $$ = node;
	}
	| Expression D_EQUAL Expression 
	{

 	 	  struct exp_node * node = create_exp_node(EQU, $1, $3);
		  node->type = $1->type;
		  node->line_num = yylineno;
	  	  $$ = node;
	}
	| Expression EXC_EQUAL Expression
	{

 	 	  struct exp_node * node = create_exp_node(NEQ, $1, $3);
		  node->type = $1->type;
		  node->line_num = yylineno;
	  	  $$ = node;
	} 
	| Expression STAR Expression 
	{
		  struct exp_node * mult_node = create_exp_node(MUL, $1, $3);
		  mult_node->type = $1->type;
		  mult_node->line_num = yylineno;
		  $$ = mult_node;

	}
	| Expression SLASH Expression 
	{	
	  	  struct exp_node * div_node = create_exp_node(DIV, $1, $3);
		  div_node->line_num = yylineno;
	          div_node->type = $1->type;
	          $$ = div_node;

	}
	| Expression LESS Expression 
	{
		  struct exp_node * node = create_exp_node(LE, $1, $3);
		  node->type = BOOL;
		  node->line_num = yylineno;
		  $$ = node;
	}
	| Expression GREATER Expression
	{
		  struct exp_node * node = create_exp_node(GR, $1, $3);
		  node->type = BOOL;
		  node->line_num = yylineno;
		  $$ = node;
	} 
	| EXC Expression 
	{
		  struct exp_node * node = create_exp_node(NGT, $2, NULL);
		  node->type = BOOL;
		  node->line_num = yylineno;
		  $$ = node;
	}
	| PLUS Expression
	{
		  struct exp_node * node = create_exp_node(PLU, $2, NULL);
		  node->type = $2->type;
		  node->line_num = yylineno;
		  $$ = node;
	} 
	| MINUS Expression 
	{
		  struct exp_node * node = create_exp_node(MIN, $2, NULL);
		  node->type = $2->type;
		  node->line_num = yylineno;
		  $$ = node;
	}
	| K_TRUE 
	{	
		struct exp_node * leaf = create_bool_leaf(1);
		leaf->line_num = yylineno;
		$$ = leaf;
	}
	| K_FALSE 
	{	
		struct exp_node * leaf = create_bool_leaf(0);
		leaf->line_num = yylineno;
		$$ = leaf;
	}
	| MethodCall
	{	
		$$ = $1;
	}
	| LeftValue
	{
		$$ = $1;
	}
	| LeftValue DOT K_LENGTH
	{
		/*if(!$1->is_array)
		{ 
			ERROR; 
		}
		else
		{*/
		/* TODO: Edit here to have a exp node with int type.
		    struct exp_node * node = create_exp_node(GR, $1, $3);
		    node->type = $1->type;
		    $$ = node;
		  */
		//}
	}	
	| K_NEW ID LEFT_PAR RIGHT_PAR
	{
		//The constructor should be called, so this a method.
		struct exp_node * node = (struct exp_node *) malloc(sizeof(struct exp_node));
		node->type = CLASS;
		node->associated_class = $2;
		node->is_constructed = 1; //Has new operator.
		node->is_array = 0;
		node->is_array_entry = 0;
		node->is_id = 0;
		node->is_leaf = 1;
		node->is_method = 0;
		node->is_property = 0; 
		node->line_num = yylineno;
		$$ = node;
				
	}
	| K_NEW Type Index
	| LEFT_PAR Expression RIGHT_PAR
	{
		$$ = $2;
	} 
	| STRING_LITERAL
	{
		char * str = $1;
		int len = strlen(str);
		char * result = (char *) malloc((len-1) * sizeof(char));
		strncpy(result, &str[1], len-2);
		result[len-2] = 0;
	   
	  struct exp_node * leaf = create_string_leaf(result);
	  leaf->line_num = yylineno;
	  $$ = leaf;		
	}
	| INTEGER_LITERAL 
	{
	  int * result = (int *) malloc(sizeof(int));
	  *result = $1;	
	  struct exp_node * leaf = create_int_leaf(result);
	  leaf->line_num = yylineno;
	  $$ = leaf;
	}
	| K_PARSEINT LEFT_PAR Expression RIGHT_PAR
	{
/*		switch($3.type)
		{
			case INT: 
				$$.value = $3.value;
				$$.type =  INT;
				break;
			case STR:
				$$.value = atoi(extractString($3.text));
				$$.type = INT;
				break;
		}*/
	}

	;

MainClass : K_CLASS ID LEFT_BRACE K_PUBLIC K_STATIC K_VOID K_MAIN LEFT_PAR K_STRING LEFT_BRACKET RIGHT_BRACKET ID RIGHT_PAR LEFT_BRACE StatementList RIGHT_BRACE RIGHT_BRACE
	    {
		class_t * cl = (class_t *) malloc(sizeof(class_t));
		scope_t * class_scope = (scope_t *) malloc(sizeof(scope_t));
		class_scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
		class_scope->parent = NULL;
		scope_t * main_scope = (scope_t *) malloc(sizeof(scope_t));	
  		LinkedList * main_name_table = (LinkedList *) malloc(sizeof(LinkedList));
		llist_init(main_name_table);
		main_scope->name_table = main_name_table;
		main_scope->parent = class_scope;
		method_t * main_method = (method_t *) malloc(sizeof(method_t));
		main_method->statement = $15; 
		main_method->statement->scope = main_scope;
		main_args_name = $12;
		add_var_to_table(main_scope->name_table, main_args_name, STR, NULL);
		update_scope_hierarchy(main_method->statement);
		//method_list_t * method_list = (method_list_t *) malloc(sizeof(method_list_t));
		add_var_to_table(class_scope->name_table, "main", UNDEF, main_method); 
		//method_list->head = main_method;
		cl->scope = class_scope;
		$$ = cl;
	    }
	    ;


ClassDeclList : 
	ClassDeclList ClassDecl
	{
		if($1 == NULL)
		{
			class_list_t * list = (class_list_t *) malloc(sizeof(class_list_t));
			list->head = $2;
			$$ = list;
		}
		else
		{
			class_t * it = $1->head;
			while(it->next){ it = it->next; }
                 	it->next = $2;
		 	$$ = $1;
		}
	}
	| /*empty*/
	{
		$$ = NULL;
	};

ClassDecl : K_CLASS ID Opt_Inheritance LEFT_BRACE VarDeclList MethodDeclList RIGHT_BRACE
{
	//No inheritance.
	if($3 == NULL)
	{
		class_t * cl = (class_t *) malloc(sizeof(class_t));
		scope_t * cl_scope = (scope_t *) malloc(sizeof(scope_t));	
  		LinkedList * name_table = (LinkedList *) malloc(sizeof(LinkedList));
  		llist_init(name_table);
		cl_scope->parent = NULL;
		cl_scope->name_table = name_table;
		if($5 != NULL)
		{
			struct var_decl_t * it_var = $5->id_list;
			while(it_var)
			{
				ListNode * node = (ListNode *) malloc(sizeof(ListNode));
				node->value = it_var->id;
				//Determine value before adding to symbol table.
				//traverse(it_var->value);
				node->type = it_var->type;
				node->class_id = $5->class_id;
				node->symbol_type = PROPERTY;
				add_node_to_table(cl_scope->name_table, node);
				it_var = it_var->next;
			}

		}

		//Add every method to the name table of the class.
		if($6 != NULL)
		{
			method_t * it = $6->head;
			while(it)
			{
				ListNode * node = (ListNode *) malloc(sizeof(ListNode));
				node->value = it->id;
				node->real_value = it;
				node->symbol_type = METHOD;
				node->type = it->type->type;
				node->class_id = it->type->class_id;
				node->arg_list = it->arg_list;
				if(it->arg_list != NULL)
				{
					argument_t * arg_it = it->arg_list->head;
					while(arg_it)
					{
						ListNode * arg_node = (ListNode *) malloc(sizeof(ListNode));
						arg_node->value = arg_it->id;
						arg_node->real_value = NULL;
						arg_node->type = arg_it->type->type;	
						arg_node->symbol_type = ARG;
						add_node_to_table(it->statement->scope->name_table, arg_node);
						arg_it = arg_it->next;
					}

				}
				add_node_to_table(cl_scope->name_table, node);
				//Update parent scope.
				it->statement->scope->parent = cl_scope;
				it = it->next;
			}

		}


		//cl->methods = $6;
		//cl->properties = $5;
		cl->scope = cl_scope;
		cl->id = $2;
		$$ = cl;
	}
	else
	{
		printf("Inheritance: to be implemented");
	}
};

VarDeclList : 
	VarDeclList VarDecl
	{
		if($1 == NULL)
		{
			struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t));
			list->type = (type_info_t *) malloc(sizeof(type_info_t));
			list->type = $2->type;
			list->id_list = $2->id_list;
			$$ = list;
		}
		else
		{
			struct var_decl_t * it = $1->id_list;
			while(it->next)
			{
				it = it->next;
			}
			it->next = $2->id_list;
			$$ = $1;
		}
	}
	| { $$ = NULL; } ;

MethodDeclList :
	MethodDeclList MethodDecl
	{
		if($1 == NULL)
		{
		  method_list_t * list = (method_list_t *) malloc(sizeof(method_list_t));
		  list->head = $2;
		  $$ = list;
		}
		else
		{
		  method_t * it = $1->head;
		  while(it->next){ it = it->next; }
                  it->next = $2;
		  $$ = $1;
		}
	}
	| MethodDeclList MethodDeclWithPublic
	{
		if($1 == NULL)
		{
		  method_list_t * list = (method_list_t *) malloc(sizeof(method_list_t));
		  list->head = $2;
		  $$ = list;
		}
		else
		{
		  method_list_t * ac_list = $1;
		  method_t * it = ac_list->head; 
		  while(it->next){ it = it->next; }
                  it->next = $2;
		  $$ = $1;
		}

	}
	| {$$ = NULL;}/*empty*/;

MethodDecl: Type ID LEFT_PAR Opt_FormalList RIGHT_PAR LEFT_BRACE StatementList RIGHT_BRACE
{
  method_t * method = (method_t*) malloc(sizeof(method_t));	
  scope_t * method_scope = (scope_t *) malloc(sizeof(scope_t));	
  method_scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
  method->type = $1;
  method->id = $2;
  method->arg_list = $4;
  method->statement = $7;
  method->statement->scope = method_scope;
  update_scope_hierarchy($7);
  $$ = method;
};

MethodDeclWithPublic : K_PUBLIC Type ID LEFT_PAR Opt_FormalList RIGHT_PAR LEFT_BRACE StatementList RIGHT_BRACE
{
  method_t * method = (method_t*) malloc(sizeof(method_t));
  scope_t * method_scope = (scope_t *) malloc(sizeof(scope_t));	
  method_scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
  method->type = $2;
  method->id = $3;
  method->arg_list = $5;
  method->statement = $8;
  method->statement->scope = method_scope;
  update_scope_hierarchy($8);
  $$ = method;
};

Opt_Inheritance : 
	K_EXTENDS ID
	{
		$$ = $2;
	}
	| /*empty*/ 
	{
		$$ = NULL;
	} ;

VarDecl : Type ID VarDeclTail SEMICOLON 
	  {
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = $1;
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = $2;
		assert($2 != NULL);
		var_decl->value = NULL;
		var_decl->line_num = yylineno;
		var_decl->type = $1->type;
		list->id_list = var_decl;
		if($3 != NULL)
		{
		  var_decl->next = $3->id_list;
		}
		$$ = list;
	  }
	| ID ID VarDeclTail SEMICOLON 
	  {
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = malloc(sizeof(type_info_t));
		list->type->type = CLASS;
		list->type->class_id = $1;
		list->type->dim_len = 0;
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = $2;
		var_decl->value = NULL;
		var_decl->line_num = yylineno;
		list->id_list = var_decl;
		if($3 != NULL)
		{
		  var_decl->next = $3->id_list;
		}
		$$ = list;

          }
        | Type ID EQUAL Expression VarDeclTail SEMICOLON 
	  {
		//if($1->type != $4->type) ERROR;
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = $1;
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = $2;
		assert($2 != NULL);

		var_decl->line_num = yylineno;
		
		var_decl->value = $4;
		var_decl->type = $1->type;
		list->id_list = var_decl;
		if($5 != NULL)
		{
		  var_decl->next = $5->id_list;
		}

		$$ = list;
		

	  }
	| ID ID EQUAL Expression VarDeclTail SEMICOLON 
	  {
	        struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t)); 
		list->type = malloc(sizeof(type_info_t));
		list->type->type = CLASS;
		list->type->class_id = $1;
		list->type->dim_len = 0;
		struct var_decl_t * var_decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
		var_decl->id = $2;
		var_decl->value = $4;
		var_decl->line_num = yylineno;
		list->id_list = var_decl;
		if($5 != NULL)
		{
		  var_decl->next = $5->id_list;
		}
		$$ = list;
 
	  }
	;



VarLongerDecl : COMMA ID EQUAL Expression 
		{ 
			struct var_decl_t * decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
			decl->id = $2;
			decl->value = $4;
			decl->line_num = yylineno;
			$$ = decl; 
		}
	      | COMMA ID 
		{ 
			struct var_decl_t * decl = (struct var_decl_t *) malloc(sizeof(struct var_decl_t));
			decl->id = $2;
			decl->line_num = yylineno;
			decl->value = NULL;
			$$ = decl;
		}
	      ;

VarDeclTail : 
	VarDeclTail VarLongerDecl
	{
		if($1 == NULL)
		{
			struct var_decl_list_t * list = (struct var_decl_list_t *) malloc(sizeof(struct var_decl_list_t));
			list->id_list = $2;
			$$ = list;	
		}
		else
		{
			struct var_decl_t * decl = $1->id_list;
			while(decl->next){decl = decl->next;}
			decl->next = $2;
		}
	}
	| /*empty*/
	{
		$$ = NULL;
	};
	



Opt_ExpressionList : 
	ExpressionList {$$ = $1;} 
	| /*empty*/
	{ $$ = NULL; }
	;
	
ExpressionList : Expression ExpressionTailList
{
	if($2 != NULL)
	{
		$1->next = $2->head;
	}

	exp_list_t * list = (exp_list_t *) malloc(sizeof(exp_list_t));
	list->head = $1;
	$$ = list;
	
};

ExpressionTailList : 
	ExpressionTailList ExpressionTail
	{
		if($1 == NULL)
		{
			exp_list_t * list = (exp_list_t *) malloc(sizeof(exp_list_t));
			list->head = $2;
			$$ = list;
		}
		else
		{
			struct exp_node * it = $1->head;
			while(it->next)
			{
				it=it->next;
			}
			it->next = $2;
			$$ = $1;
		}
	}
	| /*empty*/ {$$ = NULL;};

ExpressionTail : COMMA Expression
{
	$$ = $2;
};

Opt_FormalList : FormalList {$$ = $1;} | /*empty*/ {$$ = NULL;};

FormalList  : Type ID FormalListTailList
{


	argument_t * arg = (argument_t *) malloc(sizeof(argument_t));
	arg->type = $1;
	arg->id = $2;

	if($3 != NULL)
	{
		argument_t * it = $3->head;
		while(it->next) it = it->next;
		it->next = arg;
		$$ = $3;
	}
	else
	{
		argument_list_t * list = (argument_list_t *) malloc(sizeof(argument_list_t));
		list->head = arg;
		$$ = list;

	}



};

FormalListTail : COMMA Type ID
{
	argument_t * arg = (argument_t *) malloc(sizeof(argument_t));
	arg->type = $2;
	arg->id = $3;
	$$ = arg;	 
};

FormalListTailList : 
	FormalListTailList FormalListTail
	{
		if($1 == NULL)
		{
			argument_list_t * list = (argument_list_t *) malloc(sizeof(argument_list_t));
			list->head = $2;
			$$ = list; 
		}
		else
		{
			//argument_t * it = $1->head;
			$2->next = $1->head;
			$1->head = $2;
			/*while(it->next)
			{
				it = it->next;
			}
			it->next = $2;*/
			$$ = $1;
		}
	}
	| /*empty*/ {$$ = NULL;}; 

Type : PrimeType {$$ = $1;}
	| Type IndexNoExpr 
	{
		type_info_t * type = $1;
		assert($1 != NULL);
		$1->dim_len++;
		$$ = $1;
	}
	| ID IndexNoExpr
	{
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = CLASS;
		type->class_id = $1;
		type->dim_len = $2;
		$$ = type;
	}
	; 

PrimeType :  
	K_INT 
	{
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = INT;
		type->dim_len = 0;
		type->class_id = NULL;
		$$ = type;
	}
	| K_STRING 
	{
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = STR;
		type->class_id = NULL;
		type->dim_len = 0;
		$$ = type;
	} 
	| K_BOOLEAN 
	{
		type_info_t * type = (type_info_t *) malloc(sizeof(type_info_t));
		type->type = BOOL;
		type->class_id = NULL;
		type->dim_len = 0;
		$$ = type;
	};

Statement : 
	VarDecl
	{
		exp_node_list_t * asgn_list = (exp_node_list_t*) malloc(sizeof(exp_node_list_t));
		elist_init(asgn_list);
		struct var_decl_t * var_it = $1->id_list;
		type_info_t * var_type = $1->type;
		while(var_it)
		{
		  struct exp_node * asgn_node = NULL; 

		  if(var_it->value != NULL)
		  {	
			  asgn_node = create_exp_node(ASGN, create_id_leaf(var_it->id), var_it->value);
		  }
		  else
	 	  {
			  asgn_node = create_exp_node(ASGN, create_id_leaf(var_it->id), NULL);
		  } 
		  asgn_node -> type = var_type->type;
		  asgn_node->line_num = var_it->line_num;
		  //Adding type of the variable in the id leaf if exists. 
		  if(asgn_node->data.left != NULL && asgn_node->data.left->is_id)
		  {
			asgn_node->data.left->type = var_type->type;
			asgn_node->data.left->line_num = var_it->line_num;
			if(var_type->type == CLASS)
			{
				asgn_node->data.left->associated_class = var_type->class_id;
			}

		  }
		  exp_node_link_t * link = (exp_node_link_t *) malloc(sizeof(exp_node_link_t));
		  link->current = asgn_node;
	 	  elist_add(asgn_list, link);
		  var_it = var_it->next;
		}
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->invoke = s_decl;
		stmt->arg = (void *) asgn_list;
		stmt->line_no = yylineno;
                stmt->arg_is_expr = 0;
		stmt->scope = NULL;
		$$ = stmt; 
	} 
	| LEFT_BRACE StatementList RIGHT_BRACE
	{
		scope_t * scope = (scope_t *) malloc(sizeof(scope_t));
		scope->name_table = (LinkedList *) malloc(sizeof(LinkedList));
		scope->updated = 0;
		stmt_node_t * ref = NULL;

		$2->scope = scope;
		scope->parent = global_scope;
		ref = $2;
		ref->line_no = yylineno;
		update_scope_hierarchy($2);
		$$ = ref;
	}
	| LEFT_BRACE RIGHT_BRACE
	{
		$$ = NULL;
	}
	| K_IF LEFT_PAR Expression RIGHT_PAR Statement  K_ELSE Statement
	{
		if_node_t * node = (if_node_t *) malloc(sizeof(if_node_t));
		node->expression = $3;
		if($5 != NULL && $5->type == PRO)
		{
			stmt_node_t * list = (stmt_node_t *) malloc(sizeof(stmt_node_t));
			list->type = LIST;
			list->list_head = $5;
			node->if_list = list;
		}
		else
		{
			node->if_list = $5;
		}
		if($7 != NULL && $7->type == PRO)
		{
			stmt_node_t * list = (stmt_node_t *) malloc(sizeof(stmt_node_t));
			list->type = LIST;
			list->list_head = $7;
			node->else_list = list;
		}
		else
		{
			node->else_list = $7;
		}

		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = IF;
		stmt->if_node = node;
		stmt->arg = NULL;
		stmt->arg_is_expr = 0;
		stmt->line_no = yylineno;
		$$ = stmt;
	}
	| K_WHILE LEFT_PAR Expression RIGHT_PAR Statement 
	{
		while_node_t * node = (while_node_t *) malloc(sizeof(while_node_t));
		node->expression = $3;
		if($5 != NULL && $5->type == PRO)
		{
			stmt_node_t * list = (stmt_node_t *) malloc(sizeof(stmt_node_t));
			list->type = LIST;
			list->list_head = $5;
			node->list = list;
		}
		else
		{
			node->list = $5;
		}
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = WHILE;
		stmt->while_node = node;
		stmt->arg = NULL;
		stmt->line_no = yylineno;
		stmt->arg_is_expr = 0;
		$$ = stmt;
	}
	| K_PRINTLN LEFT_PAR Expression RIGHT_PAR SEMICOLON  
	  {
		stmt_node_t * stmt = (stmt_node_t * )malloc(sizeof(stmt_node_t));
		stmt->invoke = s_println;
		stmt->arg = $3;
		stmt->arg_is_expr = 1;
		stmt->type = PRO;
		stmt->line_no = yylineno;

		$$ = stmt;		
	  }
	| K_PRINT LEFT_PAR Expression RIGHT_PAR SEMICOLON 
	  {

		stmt_node_t * stmt = (stmt_node_t * )malloc(sizeof(stmt_node_t));
		stmt->invoke = s_print;
		stmt->arg = $3;
		stmt->arg_is_expr = 1;
		stmt->type = PRO;
		stmt->line_no = yylineno;
		$$ = stmt;		
		
	  }
	| LeftValue EQUAL Expression SEMICOLON 
	  {

		stmt_node_t * stmt = (stmt_node_t * )malloc(sizeof(stmt_node_t));
		stmt->invoke = s_asgn;
		struct exp_node * asgn_node = create_exp_node(ASGN, $1, $3);
		asgn_node->type = $1->type;
		asgn_node->line_num = yylineno;
		stmt->arg = asgn_node;
		stmt->arg_is_expr = 1;
		stmt->type = PRO;
		stmt->line_no = yylineno;
		$$ = stmt;		
	  }
	| K_RETURN Expression SEMICOLON
	{
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = PRO;
		stmt->arg_is_expr = 1;
		stmt->line_no = yylineno;
		stmt->invoke = s_return;
		stmt->arg = $2; //Setting the method as the argument.
		$$ = stmt;

	}
	| MethodCall SEMICOLON
	{
		stmt_node_t * stmt = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		stmt->type = PRO;
		stmt->arg_is_expr = 1;
		stmt->line_no = yylineno;
		stmt->invoke = s_invoke;
		stmt->arg = $1; //Setting the method as the argument.
		$$ = stmt;
	}
	;

StatementList : 
	StatementList Statement 
	{
		assert($1->type == LIST);
	        slist_add($1, $2);
		$$ = $1;
	}
	| Statement
	  {
		$$ = (stmt_node_t *) malloc(sizeof(stmt_node_t));
		$$->type = LIST;
		assert($1->type == LIST || $1->type == PRO || $1->type == IF || $1->type == WHILE);
		slist_add($$, $1);
 	  };

MethodCall : LeftValue LEFT_PAR Opt_ExpressionList RIGHT_PAR
{
		struct exp_node * leaf = (struct exp_node *) malloc(sizeof(struct exp_node));
                leaf->is_method = 1;

		//assert(leaf->associated_class != NULL);
		//leaf->data.method = (method_t *) malloc(sizeof(method_t));
		//leaf->data.method->id = $1->data.var_name;
		//leaf->data.left = $1; Gerek yok.
		leaf->data.left = $1;
		if($3 != NULL)
			leaf->data.right = $3->head;
		leaf->operation = UNDEF;
  		leaf->is_leaf = 0;
  		leaf->is_id = 1;
  		leaf->is_array = 0;
		leaf->is_property = 1;
		leaf->line_num = yylineno;
		$$ = leaf;

};

Index : 
	LEFT_BRACKET Expression RIGHT_BRACKET
	{
		index_t * dimension = (index_t *) malloc(sizeof(index_t));
		dimension->size = $2;
		index_list_t * list = (index_list_t *) malloc(sizeof(index_list_t));
		list->sentinel = NULL;
		index_list_add(list, dimension);
		$$ = list;
	}
	| Index LEFT_BRACKET Expression RIGHT_BRACKET
	{
		index_t * dimension = (index_t *) malloc(sizeof(index_t));
		dimension->size = $3;
		assert($1->sentinel != NULL);
		index_list_add($1, dimension);
		$$ = $1;
	};

/*Counting dimension.*/
IndexNoExpr : 
	Index LEFT_BRACKET RIGHT_BRACKET
	{
		$$ = $1 + 1;
	}
	| LEFT_BRACKET RIGHT_BRACKET
	{
		$$ = 1;
	};

LeftValue :
	ID 
	{
		char * var = $1;
		//Find the id leaf and update parent right.
		//FIND A WAY TO UPDATE THE TYPE HERE IF THE VAR EXISTS.

		struct exp_node * leaf = create_id_leaf(var);
		leaf->line_num = yylineno;
		$$ = leaf;

	}  
	| ID Index
	{
		char * array_name = $1;
                index_list_t * index_list = $2;
		struct exp_node * leaf = create_array_entry_leaf(array_name, index_list, NULL);
		leaf->line_num = yylineno;
		$$ = leaf;		
	}
	| LeftValue DOT ID
	{
		//Look from name table.
		//Property reading or method reading.
		struct exp_node * right = create_id_leaf($3);
		right->is_property = 1;
		right->is_id = 1;
		struct exp_node * node = create_exp_node(IN, $1, right);
		//Only compatible with class names
		node->line_num = yylineno;
		$$ = node;
		
	}
	| K_NEW ID LEFT_PAR RIGHT_PAR DOT ID
	| K_NEW PrimeType Index
	{
		index_list_t * dim_list = $3;
		struct exp_node * node = create_array_leaf($2->type, $3, NULL);	
		node->line_num = yylineno;
		$$ = node;	
	}
	| K_THIS DOT ID
	;

%%


void yyerror(char const* msg)
{
  if(msg != NULL)
  {
	fprintf(stderr, "%s in line %d\n", msg, yylineno);
  }
  else
  {
        fprintf(stderr, "Syntax error in %d\n", yylineno);
  }
  if(!type_violation_found)
  {
    type_violation_found = 1;
  }
}

void type_error(int line_num)
{
  //No type error for project 3.
  /*fprintf(stderr, "Type violation at line %d\n", line_num);
  if(!type_violation_found)
  {
    type_violation_found = 1;
  }*/
}

void update_scope_hierarchy(stmt_node_t * stmt)
{

		if(stmt->type == LIST)
		{
		  stmt_node_t * it = stmt->list_head;
		  while(it)
		  {
		        if(it->type == LIST)
			{
				it->scope->parent = stmt->scope;

			}
			else if(it->type == IF)
			{
				it->if_node->if_list->scope->parent = stmt->scope;
				it->if_node->else_list->scope->parent = stmt->scope;
			}
			else if(it->type == WHILE)
			{
				it->while_node->list->scope->parent = stmt->scope;
			}
			it = it->next;
		  }	
		}	
}

int get_capacity(index_list_t * capacity)
{
  int result = 1;
  index_t * it = capacity->sentinel->next;
  while(it != capacity->sentinel)
  {
    traverse(it->size);
    result = result * (*(int *)it->size->current_value);
  }
}

int calculate_right_capacity(index_list_t * capacity, int dim_index)
{
  index_t * it = capacity->sentinel->next;
  for(int i = 0; i< dim_index; i++)
  {
    it = it->next;
  }
  it = it->next;
  if(it == capacity->sentinel) return 1;
  int result = 1;
  while(it != capacity->sentinel)
  { 
    traverse(it->size);
    result = result * (*(int *)it->size->current_value);
    it = it->next;
  }
  return result;
}

/*Helper methods.*/
//Returns the real location of the dimension.
int find_value_of_index(index_list_t * index_list, index_list_t * capacity_list)
{
  //Start iterating from last.
  index_t * it = index_list -> sentinel -> next;
  int result = 0;
  int dim_index = 0;
  while(it != index_list->sentinel)
  {
    if(it->size->type != INT)
    {
	return -1;
    }
    traverse(it->size); //Updating value of size.
    if(it->size->current_value == NULL)
    {
	return -1;
    }
    result = result + (*(int *)it->size->current_value * calculate_right_capacity(capacity_list, dim_index)); 

    it = it->next;
    dim_index++;
  }
  return result;
}

/*Add new var to given name table,*/
int add_var_to_table(LinkedList * table, char * var, enum type type,  void * value)
{
	if(llist_exists(table, var))
	{
		/*int len = 26 + strlen(var);
		char error[len + 1];
		sprintf(error, "Symbol \"%s\" already declared", var);
		error[len] = 0;
		yyerror(error);	
		return 1;*/
		if(construct_name_table) return 1;
		else update_var(table, var, value); 
	} 
	else
	{
		llist_add(table, var, type, value); 
		return 0;
	}
}

int add_node_to_table(LinkedList * table, ListNode * node)
{
	if(llist_exists(table, node->value))
	{
		/*int len = 26 + strlen(var);
		char error[len + 1];
		sprintf(error, "Symbol \"%s\" already declared", var);
		error[len] = 0;
		yyerror(error);	
		return 1;*/
		if(construct_name_table) return 1;
		else update_var(table, node->value, node->real_value); 
	} 
	else
	{
		llist_add_node(table, node); 
		return 0;
	}

}

/*Updates var value if exists.*/
int update_var(LinkedList * list, char * var, void * value)
{ 
	if(!llist_exists(current_scope->name_table, var))
	{
		  //23 is the length of the remainder of the message 
		  /*int len = 23 + strlen(var);
		  char errorMessage[len];
		  sprintf(errorMessage, "Cannot find symbol \"%s\"", var);
		  errorMessage[len - 1] = 0;
		  yyerror(errorMessage);*/
		  //type_error();
		  return 1;	
	}
	llist_addValue(current_scope->name_table, var, value); 
	return 0;	
}

index_list_t * dup_sub_index_list(index_list_t * list, int sub)
{
  index_t * it = list->sentinel;
  for(int i =0; i < sub; i++)
  {
    it=it->next;
  }
  it = it->next; //Shifting right for calculating right capacity. 
  index_list_t * right_capacity = (index_list_t *) malloc(sizeof(index_list_t));
  right_capacity->sentinel=NULL;
  while(it != NULL && it->size != NULL)
  {
    index_list_add(right_capacity, it);
    it = it->next;
  }
  return right_capacity;
}

struct exp_node * lookup_array(array_entry_t * entry)
{
     ListNode * array_node = llist_find_node(current_scope->name_table, entry->array_name);
     assert(entry != NULL);
     if(array_node == NULL)
     {
	return NULL;
     }
     int real_index = find_value_of_index(entry->index, array_node->dim_capacity_list);
     if(real_index < 0)
     {
	return NULL;
     }
     void * array = array_node->real_value;

     int c_len = find_index_len(array_node->dim_capacity_list);
     int i_len = find_index_len(entry->index);
     assert(c_len >= i_len);
     struct exp_node * result = (struct exp_node *) malloc(sizeof(struct exp_node));
     result->is_array_entry = 0;
     result->is_id = 0;
     result->is_leaf = 1;
     result->operation = UNDEF;
     array_entry_t * array_entry = (array_entry_t *) malloc(sizeof(array_entry_t));
     switch(array_node->type)
     {
	case BOOL:
	{
		//If true, it is just a value.
		if(c_len == i_len)
		{
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  result->is_array = 0;
		}
		else
		{
                  int dif = c_len - i_len;
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  index_list_t * sub_list = dup_sub_index_list(array_node->dim_capacity_list, dif);
		  result->data.dimensions = sub_list;
		  result->is_array = 1;	
		}
		result->type = BOOL;
		return result;

	}
	case INT: 
	{ 
		//If true, it is just a value.
		if(c_len == i_len)
		{
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  result->is_array = 0;
		}
		else
		{
                  int dif = c_len - i_len;
		  int * int_array = (int *) array;
		  result->current_value =(void *) &int_array[real_index];
		  index_list_t * sub_list = dup_sub_index_list(array_node->dim_capacity_list, dif);
		  result->data.dimensions = sub_list;
		  result->is_array = 1;	
		}
		result->type = INT;
		return result;
	}
	case STR:
	{ 
		//If true, it is just a value.
		if(c_len == i_len)
		{
		  char** str_array = (char **) array;
		  result->current_value =(void *) &str_array[real_index];
		  result->is_array = 0;
		}
		else
		{
                  int dif = c_len - i_len;
		  char ** str_array = (char**) array;
		  result->current_value =(void *) &str_array[real_index];
		  index_list_t * sub_list = dup_sub_index_list(array_node->dim_capacity_list, dif);
		  result->data.dimensions = sub_list;
		  result->is_array = 1;	
		}
		result->type = STR;
		return result;
	}
	default: return NULL;
     }	
}


class_t * get_class_info(char * id)
{
  class_t * it = program->class_list->head;
  while(it)
  {
    if(!strcmp(it->id, id))
    {
	return it;
    }
    it = it->next;
  }
  return NULL;
}

//Wrapper code.
int setup_execute(stmt_node_t * current, int is_main)
{
	if(is_main)
	{
		add_to(text_section, "push {fp}\n");
	}
	else
	{
		add_to(text_section, "push {fp, lr}\n");
	}

	add_to(text_section, "mov fp, sp\n");

	int current_method_size = calc_method_size(current);
	char alloc_method[40];
	sprintf(alloc_method, "sub sp, sp, #%d\n", current_method_size);
	add_to(text_section, alloc_method);
	method_first_codegen(current);
	
	execute(current);

	add_to(text_section, "mov sp, fp\n");
	if(is_main)
	{
		add_to(text_section, "pop {fp}\n");
	}
	else
	{
		add_to(text_section, "pop {fp, pc}\n");
	}



}

/* Execute statements. This is where the code generated for statements. */
int execute(stmt_node_t * list)
{
  if(list == NULL) return 0;
  int stop = 0;
  assert(list->type == LIST || list->type == PRO);
  stmt_node_t * current; 
  scope_t * prev_scope = NULL;
  if(list->type == LIST)
  {
          current = list->list_head;
	  if(list->scope != current_scope)
	  {
	      if(list->scope->parent == current_scope)
	      {
		  scope_inherit_updates(current_scope, list->scope);
		  prev_scope = current_scope;
		  current_scope = list->scope;	
	      }
	      else //Method or class scope.
	      {
		prev_scope = current_scope;
		current_scope = list->scope;
	      }

	      if(current_scope->parent != NULL)
	      {
		  scope_inherit_updates(current_scope->parent, current_scope);
	      }
	  }

  }
  else
  {
    current = list;
  }

 
  assert(current_scope != NULL);


  while(current && !stop)
  {
    switch(current->type)
    {
	case PRO: 
	{
	    if(current->invoke != NULL)
	    {
	      if(current->arg_is_expr)
	      {
		expr_codegen((struct exp_node *) current->arg);
	      }
	      if(current->invoke != s_invoke)
	          current->invoke(current->arg);
	      if(current->invoke == s_return) stop = 1;
	    }
	    break;
	}
	case LIST: 
	{
	    setup_execute(current, 1);
	    break;
	}
	case IF:
	{
	    if_node_t * node = current->if_node;
	    assert(node != NULL);
	    traverse(node->expression);
	    if(node->expression->type != BOOL)
	    {
		break;
            }
	    struct exp_node * exp = node->expression;
	    expr_codegen(exp);
            //r0 should have the right value.
	    char * if_l = generate_label(TRUE_P);
	    char * else_l = generate_label(FALSE_P);
	    char * endif_l = generate_label(ENDIF_P);

	    add_to(text_section, "cmp r0, #0\n");
	    char false_br[80];
	    sprintf(false_br, "beq %s\n", else_l);
	    add_to(text_section, false_br);
	    declare_label(if_l);
	    setup_execute(node->if_list, 1);
            char true_jump[80];
	    sprintf(true_jump, "b %s\n", endif_l);
	    add_to(text_section, true_jump);
	    declare_label(else_l);
	    setup_execute(node->else_list, 1);
	    declare_label(endif_l);
	    break;
	}
	case WHILE: 
	{
		while_node_t * node = current->while_node;
		assert(node !=NULL);
		traverse(node->expression);
	    	if(node->expression->type != BOOL)
	    	{
			break;
            	}
	    	struct exp_node * exp = node->expression;
		expr_codegen(exp);
		char * while_l = generate_label(WHILE_P);
		char * endwhile_l = generate_label(ENDWHILE_P);

	    	add_to(text_section, "cmp r0, #0\n");
		char init_jump[80];
		sprintf(init_jump, "beq %s\n", endwhile_l);
		add_to(text_section, init_jump);
  	    	add_to(text_section, "push {fp}\n");
  	    	add_to(text_section, "mov fp, sp\n");

		int current_method_size = calc_method_size(node->list);
		char alloc_method[40];
		sprintf(alloc_method, "sub sp, sp, #%d\n", current_method_size);
		add_to(text_section, alloc_method);
		method_first_codegen(node->list);
		declare_label(while_l);
		execute(node->list);
		current_scope = node->list->scope;
		expr_codegen(exp);
		current_scope = current_scope->parent; //Backtrack. The reason we changed the scope is that traverse exp will now look at the right symbol table.
		char jump_back[80];
	    	add_to(text_section, "cmp r0, #0\n");
		sprintf(jump_back, "bne %s\n", while_l);
		add_to(text_section, jump_back);
  	    	add_to(text_section, "mov sp, fp\n");
  	    	add_to(text_section, "pop {fp}\n");
		declare_label(endwhile_l);	
		/*while(*(int *) exp->current_value)
		{
			execute(node->list);
			current_scope = node->list->scope;
			assert(current_scope != NULL);
			traverse(exp);
			current_scope = current_scope->parent; //Backtrack. The reason we changed the scope is that traverse exp will now look at the right symbol table.
		}*/
		break;
	}
	default: /*type_error();*/ break;
		
    }

    current = current->next;
  }
  /*if(current_scope->parent != NULL)
  {
	current_scope = current_scope->parent;
  } 
  else
  {
  	current_scope = global_scope; 
  }*/
  if(prev_scope != NULL)
  {
    current_scope = prev_scope;
  }


}

/* Traverse expr tree. Every traversal updates the reference of the object.*/
int traverse(struct exp_node * root)
{
  if(root != NULL)
  {
    /*if(root->is_property)
    {
	class_t * info = get_class_info(root->associated_class);
	if(info == NULL)
	{	
		type_error(root->line_num);
		return 1;
	}
	
	ListNode * node = llist_find_node(info->scope->name_table, root->data.var_name);
	if(node == NULL)
	{
		type_error(root->line_num);
		return 1;
	}
	if(node->symbol_type == PROPERTY)
	{
		if(root->is_method)
		{
			type_error(root->line_num);
			return 1;
		}
		void * property_value = llist_find(info->scope->name_table, node->value);
		if(property_value == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		root->current_value = property_value;
		return 0;
		
	}
	else if(node->symbol_type == METHOD)
	{
		if(!root->is_method)
		{
			type_error(root->line_num);
			return 1;
		}

		method_t * method = (method_t *) node->real_value;
		stmt_node_t * routine = method->statement;
		if(routine == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		//Call method.

		//Implement arguments here. TODO 
		if(construct_name_table)
		{
			traverse_for_errors(routine);
		}
		else
		{	
			execute(routine);
		}
		if(routine->type != UNDEF)
		{
			//When return is used.
			//root->current_value = stack_pop();
		}
	}

    }*/
    if(root->is_id)
    {
	     //ListNode * node =  llist_find_node(current_scope->name_table, root->data.var_name);
	     //root->current_value = node->real_value;
	     //root->type = node->type;

	     return 0;
    }
    else if(!root->is_leaf && !root->is_array_entry)
    {
	    struct exp_node * left = root->data.left;
	    struct exp_node * right = root->data.right;
	    //Traverse will return error.
	    //We put this here for cases where the array entry is being assigned.
	    if(root->type != ASGN || !left->is_array_entry)
	    {
	    	if(traverse(left)) return 1;
	    }

	    if(traverse(right)) return 1;
	    if(left == NULL && right == NULL) 
	    {
		type_error(root->line_num);
		return 1;
	    }
	    if(construct_name_table)
	    {
		//TODO: Error check.
		if(left == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		//Left can be null when op is ASGN.
		else if(root->operation != IN && root->operation != ASGN && left->type != CLASS && left->current_value == NULL)
		{
			type_error(root->line_num);
			return 1;

		}
		if(root->operation != MIN && root->operation != PLU && right == NULL)
		{
			type_error(root->line_num);
			return 1;	
		}
		else if(root->operation != IN && right != NULL && right->type != CLASS && right->current_value == NULL)
		{
			type_error(root->line_num);
			return 1;

		}
		if(root->operation != IN && left != NULL && right !=NULL && !left->is_array_entry && left->type != right->type)
		{
		 	type_error(root->line_num);
			return 1;
		} 
		
	    }
	    root->type = left->type;
	    switch(root->operation)
	    {
		
		case ADD:  
			root->current_value = s_add(left, right, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case SUB:  
			root->current_value = s_sub(left, right, root->type); 
			if(root->current_value == NULL) return 1; //Type error. 
			break;
		case MUL:  
			root->current_value = s_mul(left, right, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case DIV:  
			root->current_value = s_div(left, right, root->type); 
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case NGT:
			root->current_value = s_negate(left, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			root->is_leaf = 1;
			break; 
		case PLU:
			root->current_value = s_plu(left, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;
		case MIN:
			root->current_value = s_min(left, root->type);
			if(root->current_value == NULL) return 1; //Type error.
			break;  
		case AND:
			root->current_value = s_and(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case OR:
			root->current_value = s_or(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case SME:
			root->current_value = s_seq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case LRE:
			root->current_value = s_leq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case EQU:
			root->current_value = s_eq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case NEQ:
			root->current_value = s_neq(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case LE:
			root->current_value = s_less(left, right);
			if(root->current_value == NULL) return 1; //Type error.
			root->type = BOOL; 
			break;
		case GR:
			root->current_value = s_greater(left, right);
			if(root->current_value == NULL) return 1; //Type error. 
			root->type = BOOL; 
			break;
		case IN: 
		{
			if(left->is_array && right->data.var_name == "length")
			{
			}
			else
			{
				s_find_property(root);
				//if(root->current_value == NULL) return 1; //Type error. 
				root->type = right->type;
				break;
			}
		}
		case ASGN: return 1;
                case UNDEF: return 1;
	
		default: /*type_error();*/ break;	
	    }

    }
    else if(root->is_array_entry)
    {
		/*array_entry_t * array_entry = root->data.array_entry;
		struct exp_node * result = lookup_array(array_entry);	
	        if(result == NULL)
		{
			type_error(root->line_num);
			return 1;
		}	
		if(!result->is_array)
		{
		  if(traverse(result))
		  {
			return 1;
		  }
		}
		root->current_value = result -> current_value;
		root->is_array = result->is_array;
		root->type = result->type;*/
    }
  }
}


/*Library methods*/
void s_print(void * arg)
{
	struct exp_node * node = (struct exp_node *) arg;
        assert(node != NULL);
	assert(node != ASGN);

	void * value;
	enum type type;
	ListNode * list_node;
	if(node->is_id)
	{
		//list_node = llist_find_node(current_scope->name_table, node->data.var_name);
		//type = list_node->type;
		//value = list_node->real_value;
//		type = node->type;
//		value = node->current_value;
	}
	else if(node->is_array)
	{
		type_error(node->line_num);
		return;
	}
	else
	{
		value = node->current_value;
		type = node->type;
	}
	
	switch(type)
	{

		case INT : 
		{
			//Move value from ro to r1.
			add_to(text_section, "mov r1, r0\n");
			add_to(text_section, "ldr r0, =print_int_format\n");
			add_to(text_section, "bl printf\n");		
			break;
		} 
		case STR :
		{
			add_to(text_section, "mov r1, r0\n"); 
			add_to(text_section, "ldr r0, =print_str_format\n");
			add_to(text_section, "bl printf\n");
			break;
		}
		case BOOL :
		{
			char * true_l = generate_label(TRUE_P);
			char * false_l = generate_label(FALSE_P);
			char * endif_l = generate_label(ENDIF_P);
		
			add_to(text_section, "cmp r0, #1\n");
			char branch[50];
			sprintf(branch, "bne %s\n", false_l);
			add_to(text_section, branch);
			declare_label(true_l);
			add_to(text_section, "ldr r0, =print_str_format\n");
			add_to(text_section, "ldr r1, =bool_true\n");
			add_to(text_section, "bl printf\n");
			char branch2[50];
			sprintf(branch2, "b %s\n", endif_l);
			add_to(text_section, branch2);
			declare_label(false_l);
			add_to(text_section, "ldr r0, =print_str_format\n");
			add_to(text_section, "ldr r1, =bool_false\n");
			add_to(text_section, "bl printf\n");
			declare_label(endif_l);
			break;
		}	
		default: assert(0); break; 
	}	
}

void s_println(void * arg)
{
	struct exp_node * node = (struct exp_node *) arg;
	void * value;
	assert(node != NULL);
	enum type type;
	ListNode * list_node;
	if(node->is_id)
	{
		//Do address computation.
		ListNode * list_node = llist_find_node(current_scope->name_table, node->data.var_name);
		//type = node->type;
		//value = node->current_value;
	}
	else if(node->is_array)
	{
		type_error(node->line_num);
		return;
	}
	else
	{
		value = node->current_value;
	}
	//assert(value != NULL);
	switch(node->type)
	{

		case INT : 
		{
			//Move value from ro to r1.
			add_to(text_section, "mov r1, r0\n");
			add_to(text_section, "ldr r0, =println_int_format\n");
			add_to(text_section, "bl printf\n");		
			break;
		} ;
		case STR :
		{
			add_to(text_section, "mov r1, r0\n"); 
			add_to(text_section, "ldr r0, =println_str_format\n");
			char print_arg[40];
			add_to(text_section, "bl printf\n");
			break;
		}
		case BOOL :
		{
			char * true_l = generate_label(TRUE_P);
			char * false_l = generate_label(FALSE_P);
			char * endif_l = generate_label(ENDIF_P);
		
			add_to(text_section, "cmp r0, #1\n");
			char branch[50];
			sprintf(branch, "bne %s\n", false_l);
			add_to(text_section, branch);
			declare_label(true_l);
			add_to(text_section, "ldr r0, =println_str_format\n");
			add_to(text_section, "ldr r1, =bool_true\n");
			add_to(text_section, "bl printf\n");
			char branch2[50];
			sprintf(branch2, "b %s\n", endif_l);
			add_to(text_section, branch2);
			declare_label(false_l);
			add_to(text_section, "ldr r0, =println_str_format\n");
			add_to(text_section, "ldr r1, =bool_false\n");
			add_to(text_section, "bl printf\n");
			declare_label(endif_l);
			break;
		}	
		default: assert(0); break; 
	}	
}

//Root has operation IN. Left side is the associated class and right side is the id that has the method or property name.
int s_find_property(struct exp_node * root)
{
	struct exp_node * op1 = root->data.left;
	struct exp_node * op2 = root->data.right;
	//Find var from current scope.
	ListNode * prop_node = llist_find_node(current_scope->name_table, op1->data.var_name);
	assert(prop_node->type == CLASS);
	assert(prop_node->class_id != NULL);
	//Somehow left should have class name.
	class_t * info = get_class_info(prop_node->class_id);
  	assert(info != NULL);
	ListNode * node = llist_find_node(info->scope->name_table, op2->data.var_name);
	assert(node != NULL);
	if(node->symbol_type == PROPERTY)
	{
		struct exp_node * property_value = (struct exp_node *) llist_find(info->scope->name_table, node->value);
		if(property_value == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		root->current_value = property_value->current_value;
		return 0;	
	}
	else if(node->symbol_type == METHOD)
	{

		method_t * method = (method_t *) node->real_value;
		stmt_node_t * routine = method->statement;
		if(routine == NULL)
		{
			type_error(root->line_num);
			return 1;
		}
		//Call method.

		//Implement arguments here. TODO 
		if(construct_name_table)
		{
			traverse_for_errors(routine);
		}
		else
		{	
			execute(routine);
		}
		if(routine->type != UNDEF)
		{
			//When return is used.
			//root->current_value = stack_pop();
		}
		return 0;
	}
	
}

void * s_add(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);

  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value + (*(int *)op2->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }	
    case STR: 
    {
	char * operand1 = (char*)op1->current_value;
	char * operand2 = (char*)op2->current_value;
	int len1 = strlen(operand1);
	int len2 = strlen(operand2);
	char * result = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	strncpy(result, operand1, len1);
	strncpy(&result[len1], operand2, len2);
	result[len1+len2] = 0;
	return result;	
	
    }
    default: type_error(op1->line_num); return NULL;
  }
}

void * s_sub(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);


  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value - (*(int *)op2->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }
}

void * s_mul(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value * (*(int *)op2->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }
}


void * s_div(struct exp_node * op1, struct exp_node * op2, enum type type)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  switch(type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value / *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }
}

// !(bool) operation
void * s_negate(struct exp_node * op, enum type type)
{
  assert(op != NULL);
  switch(type)
  {
    case BOOL:
    {
	int result = *(int *) op->current_value == 0 ? 1 : 0;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op->line_num); return NULL;
  }

}

void * s_plu(struct exp_node * op, enum type type)
{
  assert(op != NULL);
  switch(type)
  {
    case INT: 
    {
	int result = (*(int *) op->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op->line_num); return NULL;
  }
}

void * s_min(struct exp_node * op, enum type type)
{
  assert(op != NULL);
  if(op->type != type)
  switch(type)
  {
    case INT: 
    {
	int result = -1 * (*(int *) op->current_value);
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op->line_num); return NULL;
  }
}

void * s_and(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  switch(type)
  {
    case BOOL:
    {
	int result = *(int *) op1->current_value && *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_or(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
 enum type type = op1->type;
  switch(type)
  {
    case BOOL:
    {
	int result = *(int *) op1->current_value || *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}


void * s_eq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;

  switch(type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value == *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }

    case BOOL:
    {
	int result = *(int *) op1->current_value == *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_neq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
 enum type type = op1->type;
  switch(type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value != *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    case BOOL:
    {
	int result = *(int *) op1->current_value != *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_seq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value <= *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_leq(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value >= *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default:   type_error(op1->line_num); return NULL;
  }

}

void * s_less(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  enum type type = op1->type;
  if(construct_name_table) return NULL;
  switch(type)
  {
    case INT:
    {
	int result = *(int *) op1->current_value < *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }

}

void * s_greater(struct exp_node * op1, struct exp_node * op2)
{
  assert(op1 != NULL);
  assert(op2 != NULL);
  switch(op1->type)
  {
    case INT: 
    {
	int result = *(int *) op1->current_value > *(int *) op2->current_value;
        int * res_point = (int *) malloc(sizeof(int));
	*res_point = result; 
	return res_point;
    }
    default: type_error(op1->line_num); return NULL;
  }

}

void allocate_array(struct exp_node * node)
{
  assert(node->is_array);
  index_list_t * dimensions = node->data.dimensions;
  index_t * it = dimensions->sentinel->prev; 
  int total_alloc_size = 1;
  while(it != dimensions->sentinel)
  {
	//If size type is not int, should be error.
	assert(it->size->type == INT);
	traverse(it->size);

        total_alloc_size = total_alloc_size * (* (int *) it->size->current_value);
	it = it->prev;
  }
  switch(node->type)
  {
	case BOOL:
	case INT: 
  	{	//node->current_value = malloc(total_alloc_size * sizeof(int));
		char command[80];
		sprintf(command, "ldr r0, =#%d\n", total_alloc_size * sizeof(int));
		add_to(text_section, command);
		add_to(text_section, "bl malloc\n");

		break;
	}
	case STR:
	{
		char command[80];
		sprintf(command, "ldr r0, =#%d\n", total_alloc_size * sizeof(char *));
		add_to(text_section, command);
		add_to(text_section, "bl malloc\n");
		break;
	}
	default: yyerror("Unhandled array type."); break;

  }
}



void s_asgn(void * abstract_arg)
{
  struct exp_node * arg = (struct exp_node *) abstract_arg;
  struct exp_node * left_value = arg->data.left;
  struct exp_node * right_value = arg->data.right;
  assert(right_value != NULL);
  //assert(left_value->is_id || left_value->is_array_entry);
  if(right_value->is_array)
  {
     allocate_array(right_value);
  }

  if(left_value->is_array_entry)
  {
     ListNode * array_name_entry = llist_find_node(current_scope->name_table, left_value->data.array_entry->array_name);
     assert(array_name_entry != NULL);
     char command[80];
     char *name_array = array_name_entry->value; //Contains the array name.
     sprintf(command, "ldr r4, =%s\n", name_array);
	//We have to find the location of the array entry.
     add_to(text_section, command);
     add_to(text_section, "ldr r4, [r4]\n");
     expr_codegen(left_value->data.array_entry->index->sentinel->next->size); //This outputs content to r0. We are getting the first index here.

     void * array = array_name_entry->real_value;

     switch(array_name_entry->type)
     {
	case BOOL:
	case INT: 
	{ 
		char put_offset[80];
		sprintf(put_offset, "ldr r2, =#%d\n", sizeof(int));
		add_to(text_section, put_offset);
		break;
	}
	case STR:
	{ 
		char put_offset[80];
		sprintf(put_offset, "ldr r2, =#%d\n", sizeof(char *));
		add_to(text_section, put_offset);
		break;

		break;
	}
	default: yyerror("Unknown array type"); return;
     }
        char calc_offset[80];
		//Moving the offset to r1. 
	sprintf(calc_offset, "mul r1, r0, r2\n");
	add_to(text_section, calc_offset);
	add_to(text_section, "add r0, r4, r1\n");
	add_to(text_section, "mov r1, r0\n");
	//r0 have real location. Now we will get the value of the right.
	expr_codegen(right_value);
	add_to(text_section, "str r0, [r1]\n"); //Stores there. 
  }
  else
  {
    //update_var(current_scope->name_table, left_value->data.var_name, right_value->current_value);

    expr_codegen(right_value);
    if(left_value -> operation == IN) //It is a property or method.
    {
	add_to(text_section, "mov r2, r0\n"); //Moving result value to r1 because it will get overwritten otherwise.
	prop_codegen(left_value); //Uses r0 and r1.
        add_to(text_section, "str r2, [r0]\n");
	return;
    }

    ListNode * var_node = llist_find_node(current_scope->name_table, left_value->data.var_name);
    //TODO: Expand to other types.
    switch(var_node->type)
    {
	case BOOL:
	case INT:
	{
    		char load[50];
		//Expression result should be in r0.
		if(right_value->is_array)
		{
			char command[80];
			sprintf(command, "ldr r4, =%s\n", var_node->value);
			add_to(text_section, command);
			add_to("str r0, [r4]\n");
		}
		else
		{
    			sprintf(load, "mov r4, r0\n");
    			add_to(text_section, load);
		}
		break;

	}
	case STR:
	{
		add_to(text_section, "mov r4, r0\n");
		break;
	}
	case CLASS:
	{
		//expr_codegen should handle this. r0 has class address. 
		add_to(text_section, "mov r4, r0\n");
		break;
	}
    }

    
    char store[50];
    sprintf(store, "str r4, [fp, #%d]\n", -1 * var_node->offset);
    add_to(text_section, store);
  }
}

char * find_prop_name(struct exp_node * node)
{
  if(node == NULL) return NULL;
  if(node->operation != IN)
  {
	return node->data.var_name;
  }
  struct exp_node * it = node;
  while(it->operation == IN && it->data.left)
  {
	it = it->data.left;
  }
  return it->data.var_name;
}

//After code generated, the address will be in r0.
void prop_codegen(struct exp_node * node)
{
  char * var_name = node->data.left->data.var_name;
  char * prop_name = find_prop_name(node->data.right);
  ListNode * class_var_node = llist_find_node(current_scope->name_table, var_name);
  class_t * info = get_class_info(class_var_node->class_id);

  ListNode * var_node = llist_find_node(info->scope->name_table, prop_name);
  if(var_node->symbol_type == PROPERTY)
  {
	  char read_var[80];
	  sprintf(read_var, "ldr r4, =%s\n", var_name);
	  add_to(text_section, read_var);
	  add_to(text_section, "ldr r4, [r4]\n"); //Getting base address.
	  int prop_offset = var_node->offset;
	  char add_offset[80];
	  sprintf(add_offset, "ldr r1, =#%d\n", prop_offset);
	  //Now the address is in r0.
	  add_to(text_section, add_offset);
	  add_to(text_section, "add r0, r4, r1\n");

	  //Update node
	  node->type = var_node->type; //If type is not class.

  }
  else if(var_node->symbol_type == METHOD)
  {
	int len = 3 + strlen(class_var_node->class_id) + strlen(var_node->value);
	char method_label[len];
	sprintf(method_label, "_%s_%s", class_var_node->class_id, var_node->value);
	method_label[len-1] = 0;
	
	char branch_to[10 + len];
	sprintf(branch_to, "bl %s\n", method_label);
	add_to(text_section, branch_to);
	//If return value, write to r0. 
  }

}



void s_decl(void * abstract_arg)
{
  exp_node_list_t * arg = (exp_node_list_t *) abstract_arg;
  //Arg left cannot be null because it is the variable.
  assert(arg != NULL);
  assert(arg->head != NULL);
  exp_node_link_t * current_link = arg->head;
  while(current_link)
  {
    struct exp_node * current_node = current_link -> current;
    //traverse(current_node);
    struct exp_node * id_leaf = current_node->data.left;
    struct exp_node * assign = current_node->data.right;
    if(assign == NULL)
    {
      add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, NULL);
      if(!construct_name_table)
      {
      	char var_decl[20 + strlen(id_leaf->data.var_name)];
      	sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
      	add_to(data_section, var_decl);
      }

    }
    else
    {

      if(assign->is_array)
      {
	if(construct_name_table)
	{
		add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, NULL); //The value is null because we don't know the pointer until runtime.
	}	
	else
	{
		char var_decl[20 + strlen(id_leaf->data.var_name)];
		sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
		add_to(data_section, var_decl);

		allocate_array(assign);

		char command[80];
		//Load array address.
		sprintf(command, "ldr r4, =%s\n", id_leaf->data.var_name);
		add_to(text_section, command);
		add_to(text_section, "str r0, [r4]\n");

		ListNode * just_added_array = llist_find_node(current_scope->name_table, id_leaf->data.var_name);
		just_added_array->dim_capacity_list = assign -> data.dimensions;
	}		
	
      }
      else
      {
        if(assign->type == CLASS && id_leaf->type == CLASS)
	{
		if(construct_name_table)
		{
			ListNode * node = (ListNode *) malloc(sizeof(ListNode));
			node->value = id_leaf->data.var_name;
			node->type = CLASS;
			node->class_id = assign->associated_class;
			id_leaf->associated_class = assign->associated_class;
			node->real_value = assign->current_value; //Can be null.
			add_node_to_table(current_scope->name_table, node);	
		}
		else
		{
			char var_decl[20 + strlen(id_leaf->data.var_name)];
			sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
			add_to(data_section, var_decl);

			ListNode * node = llist_find_node(current_scope->name_table, id_leaf->data.var_name);
			char get_var[80];
			sprintf(get_var, "ldr r4, =%s\n", node->value);	
			add_to(text_section, get_var);
			
			class_t * curr_class = get_class_info(node->class_id);
			int obj_size = calc_class_size(curr_class);
				
			char put_size[80];
			sprintf(put_size, "ldr r0, =#%d\n", obj_size);
			add_to(text_section, put_size);
			add_to(text_section, "bl malloc\n");
			add_to(text_section, "str r0, [r4]\n"); //Putting obj into its base address.	
		}

	}
	else
	{
		if(assign->current_value == NULL)
		{
			add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, NULL);


		}
		else
		{
			add_var_to_table(current_scope->name_table, id_leaf->data.var_name, id_leaf->type, assign->current_value);
		}


		if(!construct_name_table)
		{
			ListNode * node = (ListNode *) llist_find_node(current_scope->name_table, id_leaf->data.var_name);
			if(assign->current_value == NULL)
			{
				expr_codegen(assign); //Calculate right side.  Result in r0. 
			}
			switch(id_leaf->type)
			{
				//TODO: Add others.
				case BOOL:
				case INT:
				{
					if(assign->current_value != NULL)
					{
						char var_decl[20 + strlen(id_leaf->data.var_name)];
						sprintf(var_decl, "%s: .word %d\n", id_leaf->data.var_name, * (int *) assign->current_value);
						add_to(data_section, var_decl);
					}
					else
					{
						char var_decl[20 + strlen(id_leaf->data.var_name)];
						sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
						add_to(data_section, var_decl);
						char store[80];
						sprintf(store, "str r0, [fp, #%d]\n", -1 * node->offset);
						add_to(text_section, store);
					}
					
					break;
				}
				case STR:
				{
					char * value = (char *) assign->current_value;
					char var_decl[20 + strlen(id_leaf->data.var_name)];
					sprintf(var_decl, "%s: .word 0\n", id_leaf->data.var_name);
					add_to(data_section, var_decl);
					//Malloc space for string.
					int len = strlen(value) + 1;
					char malloc_space[80];
					sprintf(malloc_space, "mov r0, #%d\n", len);
					add_to(text_section, malloc_space);
					add_to(text_section, "bl malloc\n");
					char address[20 + strlen(id_leaf->data.var_name)];
					sprintf(address, "ldr r4, =%s\n", id_leaf->data.var_name);
					add_to(text_section, address);
					//Store pointer to memory pointed by r4.
					add_to(text_section, "str r0, [r4]\n");
					
					//Setting the string
					for(int i = 0; i < len - 1; i++)
					{
					  char get_char[50];
					  sprintf(get_char, "mov r1, #%d\n", (int) value[i]);

					
					  char put_char[50];
					  sprintf(put_char, "strb r1, [r4, #%d]\n", i); //Store char in position i.
			
					  add_to(text_section, get_char);	
					  add_to(text_section, address);
					  add_to(text_section, "ldr r4, [r4]\n");
					  add_to(text_section, put_char);
					}
				        //Null terminate.
					char null_ter[50];
				        sprintf(null_ter, "strb r1, [r4, #%d]\n", len - 1);

				        add_to(text_section, "mov r1, #0\n");
					add_to(text_section, null_ter);
					add_to(text_section, address);
					add_to(text_section, "ldr r4, [r4]\n");
					char update_stack[60];
					sprintf(update_stack, "str r4, [fp, #%d]\n", -1 * node->offset);
					add_to(text_section, update_stack);
					break;
				}		
			}

		}

	}

      }


    }

    current_link = current_link -> next;
  }

}

/*Empty method, declares stmt type.*/
void s_invoke(void * abstract_arg)
{
 /* struct exp_node * node = (struct exp_node *) abstract_arg;
  assert(node->is_method);
  char * method_name = node->data.var_name;
  char * class_name = node->associated_class;
  class_t * info = get_class_info(class_name);
  ListNode * method_node = llist_find_node(info->scope->name_table, method_name);
  assert(method_node != NULL);
  method_t * method_info = (method_t *) method_node->real_value;
  assert(method_info != NULL);
  execute(method_info->statement);*/
}

void s_return(void * abs_arg){} //Is not needed.

//Fake executes to see if there is any error.
int traverse_for_errors(stmt_node_t * list)
{
  if(list == NULL) return 0;
  assert(list->type == LIST || list->type == PRO);
  stmt_node_t * current;
  scope_t * prev_scope = NULL;
  if(list->type == LIST)
  {
          current = list->list_head;
	  if(list->scope != current_scope)
	  {
	      if(list->scope->parent == current_scope)
	      {
		  scope_inherit(current_scope, list->scope);
		  prev_scope = current_scope;
		  current_scope = list->scope;	
	      }
	      else //Method or class scope.
	      {
		prev_scope = current_scope;
		current_scope = list->scope;
		if(current_scope->parent != NULL)
		{
		  scope_inherit(current_scope->parent, current_scope);
		}
	      }
	  }
  }
  else
  {
    current = list;
  }

  assert(current_scope != NULL);
  while(current)
  {
    switch(current->type)
    {
	case PRO: 
	{  
	    if(current->invoke != NULL)
	    {
	        if(current->arg_is_expr)
	        {
		  int status = traverse((struct exp_node *) current->arg);
	          if(status != 0) break;
	        }
		int status = check_stmt_errors(current);
	        if(status != 0) break;
		if(current->invoke == s_asgn || current->invoke == s_decl)
		{
	          current->invoke(current->arg);	      
		}
	    }
	    break;
	}
	case LIST: 
	{
	    traverse_for_errors(current);
	    break;
	}
	case IF:
	{
	    if_node_t * node = current->if_node;
	    assert(node != NULL);
	    traverse(node->expression);
	    if(node->expression->type != BOOL)
	    {
		type_error(current->line_no);
		break;
            }
	    struct exp_node * exp = node->expression;
	    if(exp->current_value == NULL)
	    {
		type_error(exp->line_num);
		break;
	    }
	    traverse_for_errors(node->if_list);
	    traverse_for_errors(node->else_list);
	    break;
	}
	case WHILE: 
	{
		while_node_t * node = current->while_node;
		assert(node !=NULL);
		traverse(node->expression);
	    	if(node->expression->type != BOOL)
	    	{
			type_error(node->expression->line_num);
			break;
            	}
	   	traverse_for_errors(node->list);
	}
	default: /*type_error();*/ break;
		
    }
    current = current->next;
  }
  
if(prev_scope != NULL)
  {
    current_scope = prev_scope;
  }

}
//return 0 if not errors, return 1 if error.
int check_stmt_errors(stmt_node_t * stmt)
{
  if(stmt->invoke == s_decl)
  {
	  exp_node_list_t * arg = (exp_node_list_t *) stmt->arg;
	  //Arg left cannot be null because it is the variable.
	  exp_node_link_t * current_link = arg->head;
	  while(current_link)
	  {
	    struct exp_node * current_node = current_link -> current;
	    if(current_node->data.right != NULL)
	    {
	      if(current_node->data.left->type != current_node->data.right->type)
	      {
		  type_error(current_node->line_num);
		  return 1;
	      }
	    }

	    traverse(current_node->data.right);
	    current_link = current_link->next;
	  }

  }
  else if(stmt->invoke == s_asgn)
  {
  	struct exp_node * arg = (struct exp_node *) stmt->arg;
  	struct exp_node * left_value = arg->data.left;
  	struct exp_node * right_value = arg->data.right;
	/*if(left_value->type != right_value->type) Assign node olusurken check ediliyor olmasi lazim.
	{
	    type_error();
	    return;
	}*/
	//You might want to use type info for catching this.
	  /*if(right->is_array && $1->dim_len != $4->data.dim_len)
	  {
	    type_error();
	    return;

	  }*/
  	if(left_value->is_array_entry)
  	{
     		ListNode * array_name_entry = llist_find_node(current_scope->name_table, left_value->data.array_entry->array_name);
    		assert(array_name_entry != NULL);
    		void * array = array_name_entry->real_value;
     		if(right_value->type != array_name_entry->type)
     		{
        		type_error(stmt->line_no);
        		return 1;
     		}

     		int real_index = find_value_of_index(left_value->data.array_entry->index, array_name_entry->dim_capacity_list);
   		if(real_index < 0)
		{
			type_error(stmt->line_no);
			return;
		} 
	}
  }
  else if(stmt->invoke == s_print)
  {	
	struct exp_node * node = (struct exp_node *) stmt->arg;
	if(node->is_array)
	{
		type_error(stmt->line_no);
		return 1;
	}
  }
  else if(stmt->invoke == s_println)
  {
	struct exp_node * node = (struct exp_node *) stmt->arg;
	if(node->is_array)
	{
		type_error(stmt->line_no);
		return 1;
	}
  } 
  else if(stmt->invoke == s_invoke || stmt->invoke == s_return){}
  else
  {
	printf("methof not found\n");
	return 1;
  }
  return 0;
}

void stack_push(struct exp_node * node)
{
  assert(stack_header < GLOBAL_STACK_SIZE);
  stack[stack_header + 1] = node;
  stack_header++;
}

struct exp_node * stack_pop()
{
  //stack is empty.
  if(stack_header == -1)
  {
    return NULL;
  }
  struct exp_node * result = stack[stack_header];
  stack_header--;
  return result;
}

//Add to data section in assembly.
//Section can be data_section or text_section.
void add_to(char ** section, char * str)
{
  if(* section == NULL)
  {
	int len = strlen(str);
	* section = (char *) malloc((len + 1) * sizeof(char));
	strncpy(* section, str, len);
	(*section)[len] = 0;
  }
  else
  {
	int add_len = strlen(str);
	int cur_len = strlen(* section);
	* section = (char *) realloc(* section, (add_len + cur_len + 1) * sizeof(char));
	strncpy(&(* section)[cur_len], str, add_len);
	(* section)[cur_len + add_len] = 0;
  }
}


void init_data_section()
{
	add_to(data_section, "println_int_format: .asciz \"%%d\\n\"\n");
	add_to(data_section, "print_int_format: .asciz \"%%d\"\n");
	add_to(data_section, "println_str_format: .asciz \"%%s\\n\"\n");
	add_to(data_section, "print_str_format: .asciz \"%%s\"\n");
	add_to(data_section, "bool_true: .asciz \"true\"\n");
	add_to(data_section, "bool_false: .asciz \"false\"\n");
}

char * create_temp()
{
   char num_string[30];
   sprintf(num_string, "%d", temp_counter);
   int len = strlen(num_string);
   char * var_name = (char *) malloc((len + 3) * sizeof(len));
   sprintf(var_name, "_t%s", num_string);
   char data_decl[50];
   sprintf(data_decl, "%s: .word 0\n", var_name);
   add_to(data_section, data_decl);
   temp_counter++;
   return var_name;
}

//The value of the symbol will be stored in r0.
//NOTE: Value stored in stack.
void symbol_codegen(ListNode * id_node)
{
  assert(id_node);
  char assembly_load[50];
  int offset = id_node->offset;
  sprintf(assembly_load, "ldr r0, [fp, #%d]\n", -1 * offset);
  add_to(text_section, assembly_load);
}

void expr_codegen(struct exp_node * node)
{
  if(node == NULL) return;

  if(node->is_method)
  {
	//Left is calling property and right is arg_list.
	struct exp_node * left = node->data.left; //Holds the in node. Has the method name
	struct exp_node * arg_list_head = node->data.right;
	char * method_name = find_prop_name(left->data.right);
	char * obj_name = find_prop_name(left);
	if(arg_list_head != NULL) //Catching arguments.
	{
		//In expression node, we have the given arguments.
		struct exp_node * arg_it = arg_list_head;
		ListNode * method_node = NULL;
		if(obj_name == NULL)//Method is called inside the class. In that case current scope should have it.
		{
			method_node = llist_find_node(current_scope->name_table, method_name);
		}
		else
		{
			ListNode * instance_node = llist_find_node(current_scope->name_table, obj_name);
			class_t * class_info = get_class_info(instance_node->class_id);
			method_node = llist_find_node(class_info->scope->name_table, method_name);
		}
		assert(method_node != NULL);
	        argument_t * formal_it = method_node->arg_list->head;	
		char * registers[] = {"r5", "r6", "r7", "r8"};
		int i = 0;
		while(formal_it)
		{
			//arg_it will have current value
			char wr_to_reg[80];
			expr_codegen(arg_it);
			sprintf(wr_to_reg, "mov %s, r0\n", registers[i++]);
			add_to(text_section, wr_to_reg);
			arg_it = arg_it->next;
			formal_it = formal_it->next; 
		}
		for(int j = i - 1; i >= 0; i--)
		{
			//Writing to registers.
			char wr_to_reg[80];
			sprintf(wr_to_reg, "mov r%d, r%d\n", i, i+5);
			add_to(text_section, wr_to_reg);
		}
	}
	prop_codegen(left);
	//Result should be in r0.
  }
  else if(node->operation == IN) //We have to catch properties first. 
  {
	
	//Put address to r0.
        prop_codegen(node);
	add_to(text_section, "ldr r0, [r0]\n");
	return;
  }
  else if(node->is_leaf)
  {
  	if(node->is_id)
  	{
		ListNode * entry = llist_find_node(current_scope->name_table, node->data.var_name);
		symbol_codegen(entry);
		node->type = entry->type;
  	}
	else if(node->is_array_entry)
	{
		array_entry_t * entry = node->data.array_entry;
		ListNode * array_entry = llist_find_node(current_scope->name_table, entry->array_name);
		char read_array[80];
		sprintf(read_array, "ldr r4, =%s\n", entry->array_name);
		add_to(text_section, read_array);
		add_to(text_section, "ldr r4, [r4]\n");
		expr_codegen(entry->index->sentinel->next->size);
		//We have array index at r0. Calculate offset.
		int size_type = 0;
		switch(array_entry->type)
		{
			case BOOL : 
			case INT : size_type = sizeof(int); break;
			case STR : size_type = sizeof(char *); break;
			default: assert(0); break;
		}
		node->type = array_entry->type; //Updating type info here for future uses.
		char put_offset[80];	
		sprintf(put_offset, "ldr r1, =#%d\n", size_type);
		add_to(text_section, put_offset);
		add_to(text_section, "mul r1, r1, r0\n");
		//Go to exact array position.
		add_to(text_section, "add r0, r4, r1\n");
		//Read from array and write to result.
		add_to(text_section, "ldr r0, [r0]\n"); 
	}
	else
	{
		switch(node->type)
		{
		  case BOOL:
		  case INT:
		  {
		    int value = * (int * ) node->data.value; 
		    //Split up 32 bit number to be 2 16 bit numbers.
		    char split_right[50];
		    sprintf(split_right, "ldr r0, =#%d\n", value);
		    add_to(text_section, split_right);
		    break;
		  }
		  case STR:
		  {
		    char * value = (char *) node->data.value;
		    char * str_literal = generate_str_literal();
		    node->has_temp_var = 1;
		    node->temp_var = str_literal;
		    char lit_decl[80]; 
		    sprintf(lit_decl, "%s: .asciz \"%s\"\n", str_literal, value);
		    add_to(data_section, lit_decl);
		    char load_ins[80];
		    sprintf(load_ins, "ldr r0, =%s\n", str_literal);
		    add_to(text_section, load_ins);
		    //add_to(text_section, "ldr r0, [r0]\n");
		    break;
	 	  }
		  case CLASS:
		  {
			if(node->is_constructed)
			{	
				class_t * curr_class = get_class_info(node->associated_class);
				int obj_size = calc_class_size(curr_class);
					
				char put_size[80];
				sprintf(put_size, "ldr r0, =#%d\n", obj_size);
				add_to(text_section, put_size);
				add_to(text_section, "bl malloc\n");
				//r0 has class address location
			}	
			//else might be method call. id is already handled in first if. 		
		  }
		}
	}

  }
  else
  {
	struct exp_node * left = node->data.left;
	struct exp_node * right = node->data.right;
	//r0 has the final value of the expression.
	//In assign, we don't care the value of the var in left hand side.
	if(node->operation != ASGN)
	{
	  expr_codegen(left);
	  if(!left->has_temp_var)
	  {
	     add_to(text_section, "mov r1, r0\n");
          }
	  else
	  {
	     char * var = left->temp_var;
	     char stmt[50];
	     sprintf(stmt, "ldr r4, =%s\n", var);
	     add_to(text_section, stmt);
	     if(left != NULL && left->type != STR ) add_to(text_section, "ldr r1, [r4]\n");
 	     else add_to(text_section, "mov r1, r4\n");
	  }

	} 
	if(right != NULL)
	{
		expr_codegen(right);
		if(right->has_temp_var)
		{
		     char * var = right->temp_var;
		     char stmt[50];
		     sprintf(stmt, "ldr r4, =%s\n", var);
		     add_to(text_section, stmt);
		     if(right->type != STR) add_to(text_section, "ldr r0, [r4]\n");
		     else add_to(text_section, "mov r0, r4\n");
		}
	}

	char operation[50];
	char store_temp[50];
	char * var = create_temp();
	enum type type = left->type;
        //r0 have right operand, r1 have left operand.
	switch(node->operation)
	{
		
		case ADD:
		{
			switch(type)
			{
				case INT: add_to(text_section,"add r0, r0, r1\n"); break;
				case STR:
				{
					//Allocate new space for the dest using malloc.
					char * concat_string = generate_str_literal();
					char data_decl[80];
					sprintf(data_decl, "%s: .word 0\n", concat_string);
					add_to(data_section, data_decl);
					//r0 and r1 has the pointers. Move them.
					//r4, r5 => left, right operand.
					//r6, r7 => lengths of strings.
					//r4, r5 will have pc relative addresses.
					add_to(text_section, "mov r4, r1\n");
					add_to(text_section, "mov r5, r0\n");
					add_to(text_section, "mov r0, r4\n");
					add_to(text_section, "bl strlen\n");
					add_to(text_section, "mov r6, r0\n");

					add_to(text_section, "mov r0, r5\n");
					add_to(text_section, "bl strlen\n");
					add_to(text_section, "mov r7, r0\n");
					add_to(text_section, "add r0, r6, r7\n");
					add_to(text_section, "add r0, r0, #1\n");
					add_to(text_section, "bl malloc\n");
					char addr_load[80];
					sprintf(addr_load, "ldr r3, =%s\n", concat_string);
					add_to(text_section, addr_load);
					add_to(text_section, "str r0, [r3]\n");
					//strcpy yap. r0=>dest (malloc pointer) r1=>source (first operand)
					add_to(text_section, "mov r1, r4\n");
					add_to(text_section, "bl strcpy\n");
					add_to(text_section, "mov r1, r5\n");
					add_to(text_section, "bl strcat\n");
					
					break;
				}
			}

			break;

		} 

		case SUB:  
			add_to(text_section,"sub r0, r1, r0\n");
			break;
		case MUL:  
			add_to(text_section,"mul r0, r0, r1\n");
			break;
		case DIV:  
			break;
		case NGT:
			add_to(text_section,"eor r0, r0, #1\n");
			break; 
		case PLU:
			break;
		case MIN:
			add_to(text_section,"neg r0, r0\n");
			break;  
		case AND:
			add_to(text_section,"and r0, r0, r1\n");
			node->type = BOOL;
			break;
		case OR:
			add_to(text_section,"orr r0, r0, r1\n");
			node->type = BOOL;
			break;
		case SME:
		case LRE:
		case EQU:
		case NEQ:
		case LE:
		case GR:
			logic_op_codegen(node->operation);
			node->type = BOOL; 
			break;
		case IN: 
		{
			assert(0);
		}
		case ASGN: return 0;
                case UNDEF: return 1;
	
		default: /*type_error();*/ break;	
	}

	node->type = left->type; //Update type.
	sprintf(store_temp, "ldr r4, =%s\n", var);
	add_to(text_section, store_temp);
	char store[50];
	sprintf(store, "str r0, [r4]\n", var);

	node->has_temp_var = 1;
	node->temp_var = var;
	add_to(text_section, store);
  }
}

//Calculates how much memory we need for the method local variables. Also updates the offset for each variable.
int calc_method_size(stmt_node_t * list)
{
  assert(list->type == LIST);
  //Iterate over list's name table. 
  LinkedList * name_table = list->scope->name_table;
  ListNode * it = name_table->head;
  int current_offset = 4; //Start from four offset because at the bottom of the stack we want to have the frame pointer.
  while(it)
  {
    switch(it->type)
    {
	case BOOL:
	case INT:
	{
		current_offset += 4;
		break;
	}
	case STR:
	{
		//TODO: Store string pointer.
	        current_offset += 4;
		break;
	}
	case CLASS:
	{
		//TODO: Allocate for objects
	        current_offset += 4;
		break;
	}
	default: assert(0);
    }
    it->offset = current_offset;
    it = it->next;
  }
  //For every variable, update their offset.
  return current_offset;
}

int calc_class_size(class_t * class)
{
  LinkedList * name_table = class->scope->name_table;
  ListNode * it = name_table->head;
  int current_offset = 4;
  while(it)
  {
    switch(it->type)
    {
	case BOOL:
	case INT:
	case STR:
	        current_offset += 4;
		break;
	case CLASS:
	{
		//Find class node by class name metodu yaz.
		//current_offset += calc_class_size(find)
	}
    }
    it->offset = current_offset;
    it = it->next;
  }
  return current_offset;	
}

//Puts the variables in the respective offsets in the assembly code.
void method_first_codegen(stmt_node_t * list)
{
  assert(list->type == LIST);
  //Iterate over list's name table. 
  LinkedList * name_table = list->scope->name_table;
  ListNode * it = name_table->head;
  int cor_register = 5; //Corresponding arg register which starts from r5. 
  while(it)
  {
    int current_offset = it->offset;
    if(it->symbol_type == PROPERTY || it->symbol_type == METHOD)
    {
	it = it->next; //We don't have to write anything
	continue;	
    }
    char command[50];
    if(it->symbol_type == ARG)
    {
    	sprintf(command, "mov r2, r%d\n", cor_register++); //Hopefully the first argument added the first. 
    	add_to(text_section, command);

    }
    else
    {
    	sprintf(command, "ldr r2, =%s\n", it->value); 
    	add_to(text_section, command);
    	//We are storing the value in stack, thus we have to dereference the address before storing.
    	add_to(text_section, "ldr r2, [r2]\n");

    }


    char command2[50];
    sprintf(command2, "str r2, [fp, #%d]\n", -1 * current_offset); 
    add_to(text_section, command2);
    it = it->next;
  }
}

char * generate_label(label_purpose_t purpose)
{
  //char * to_be_written[50];
  char to_be_written[50];
  switch(purpose)
  {
	case TRUE_P:
	{
		sprintf(to_be_written, "_true%d", g_label_counter[TRUE_P]++);
		break;
	}
	case FALSE_P:
	{
		sprintf(to_be_written, "_false%d", g_label_counter[FALSE_P]++);
		break;
	}
	case WHILE_P:
	{
		sprintf(to_be_written, "_while%d", g_label_counter[WHILE_P]++);
		break;
	}
	case ENDIF_P:
	{
		sprintf(to_be_written, "_endif%d", g_label_counter[ENDIF_P]++);
		break;
	}
	case ENDWHILE_P:
	{
		sprintf(to_be_written, "_endwhile%d", g_label_counter[ENDWHILE_P]++);
		break;
	}

  }
  int len = strlen(to_be_written);
  char * result = malloc((len + 1) * sizeof(char));
  strncpy(result, to_be_written, len);
  result[len] = 0;
  return result;
}

char * generate_str_literal()
{
	char to_be_wr[50];
	sprintf(to_be_wr, "_strlt%d", str_literal_counter++);
  	int len = strlen(to_be_wr);
  	char * result = malloc((len + 1) * sizeof(char));
  	strncpy(result, to_be_wr, len);
  	result[len] = 0;
  	return result;
}

void logic_op_codegen(enum op op)
{
	//Make sure it is logic operations.
	char var_str[80];

	char * endif_label = generate_label(ENDIF_P);
	char * true_label = generate_label(TRUE_P);
	char * false_label = generate_label(FALSE_P);

	switch(op)
	{
		
		case SME:
			sprintf(var_str, "ble %s\n", true_label);
			break;
		case LRE:
			sprintf(var_str, "bge %s\n", true_label);
			break;
		case EQU:
			sprintf(var_str, "beq %s\n", true_label);
			break;
		case NEQ:
			sprintf(var_str, "bne %s\n", true_label);
			break;
		case LE:
			sprintf(var_str, "blt %s\n", true_label);
			break;
		case GR:
			sprintf(var_str, "bgt %s\n", true_label);
			break;
	}

	add_to(text_section,"cmp r1, r0\n");
	add_to(text_section, var_str);
	char label_decl2[50];
	sprintf(label_decl2, "%s:\n", false_label);
	add_to(text_section, label_decl2);
	add_to(text_section, "mov r0, #0\n");
	char jump2[50];
	sprintf(jump2, "b %s\n", endif_label);
	add_to(text_section, jump2);
	char label_decl[50];
	sprintf(label_decl, "%s:\n", true_label);
	add_to(text_section, label_decl);
	add_to(text_section, "mov r0, #1\n");
	char jump[50];
	sprintf(jump, "b %s\n", endif_label);
	add_to(text_section, jump);

	char label_decl3[50];
	sprintf(label_decl3, "%s:\n", endif_label);
	add_to(text_section, label_decl3);
}

void declare_label(char * label)
{
  char decl[80];
  sprintf(decl, "%s:\n", label);
  add_to(text_section, decl);
}

//Writes the methods declared in other classes. 
void other_classes_codegen()
{
	class_list_t * list = program->class_list;
	class_t * class_it = list->head;
	while(class_it)
	{
		LinkedList * name_table = class_it->scope->name_table;
		ListNode * it = name_table->head;
		while(it)
		{
			if(it->symbol_type == METHOD)
			{
				int str_len = 5 + strlen(class_it->id) + strlen(it->value);
				char method_label[str_len];
				sprintf(method_label, "_%s_%s:\n", class_it->id, it->value);
				method_label[str_len - 1] = 0;
				add_to(text_section, method_label);
			  	method_t * method = (method_t *) it->real_value;
				//Arguments?
				construct_name_table = 1;
				traverse_for_errors(method->statement); //Will fill up the name table.
				construct_name_table = 0;
				setup_execute(method->statement, 0); //Real value contains the stmt_node.
			}
			it = it->next;
		}
		class_it = class_it->next;
	}

}

int main(int argc, char** argv)
{
  #ifdef MYDEBUG
	yydebug = 1;
  #endif
  
  yyin = fopen(argv[1], "r");
  yyparse();
  fclose(yyin);
  assert(program != NULL);
  method_t * main_method = llist_find(program->main_class->scope->name_table, "main");
  stmt_node_t * main_stmt_list = main_method->statement;
  current_scope = main_stmt_list->scope;
  traverse_for_errors(main_stmt_list);
  
  construct_name_table = 0; //Stop doing the name tables.
  current_scope = main_stmt_list->scope;

  if(!type_violation_found)
  {
    char * filename = strdup(argv[1]);
    int len = strlen(filename);
    char * file_without_ext = malloc((len-2) * sizeof(char));
    strncpy(file_without_ext, filename, len - 5);
    strncpy(&file_without_ext[len-5], ".s", 2);
    file_without_ext[len-3] = 0;
    gen_file = fopen(file_without_ext, "w+");

     data_section = (char **) malloc(sizeof(char *));
     text_section = (char **) malloc(sizeof(char *));
     * data_section = NULL;
     * text_section = NULL;

     add_to(text_section, ".global main\n");
     add_to(text_section, ".balign 4\n");
     //Main args should be the first var added to the main table.
     //If not, use llist_find
     ListNode * args_node = llist_find_node(main_stmt_list->scope->name_table, main_args_name);
     assert(args_node != NULL);
     char args_decl[80];
     sprintf(args_decl, "%s: .word 0\n", args_node->value);
     add_to(data_section, args_decl);
     add_to(text_section, "main:\n");
     add_to(text_section, "push {lr}\n");
     char args_call[80];
     sprintf(args_call, "ldr r4, =%s\n", args_node->value);
     add_to(text_section, args_call);
     add_to(text_section, "str r1, [r4]\n");

    setup_execute(main_stmt_list, 1);
    add_to(text_section, "b __end__\n");
     //Insert every method decl after creating the main program.
     other_classes_codegen();

    fprintf(gen_file, ".section .data\n");
    init_data_section();
    if(data_section != NULL) fprintf(gen_file, *data_section);
    fprintf(gen_file, ".section .text\n");
    if(text_section != NULL) fprintf(gen_file, *text_section);
    if(data_section != NULL) free(data_section);
    if(text_section != NULL) free(text_section);

    fprintf(gen_file, "__end__:\n");
    fprintf(gen_file, "pop {pc}\n");
  }
  fclose(gen_file);
}
