/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING_LITERAL = 258,
    INTEGER_LITERAL = 259,
    ID = 260,
    D_AMPERSAND = 261,
    D_LINES = 262,
    SMALL_EQUAL = 263,
    LARGE_EQUAL = 264,
    D_EQUAL = 265,
    EXC_EQUAL = 266,
    PLUS = 267,
    MINUS = 268,
    STAR = 269,
    SLASH = 270,
    K_CLASS = 271,
    K_INT = 272,
    K_STRING = 273,
    K_BOOLEAN = 274,
    K_IF = 275,
    K_WHILE = 276,
    K_RETURN = 277,
    K_NEW = 278,
    K_THIS = 279,
    K_TRUE = 280,
    K_FALSE = 281,
    K_PRINTLN = 282,
    K_PRINT = 283,
    K_ELSE = 284,
    K_EXTENDS = 285,
    K_PUBLIC = 286,
    K_LENGTH = 287,
    K_STATIC = 288,
    K_VOID = 289,
    K_MAIN = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_PAR = 293,
    RIGHT_PAR = 294,
    LEFT_BRACKET = 295,
    RIGHT_BRACKET = 296,
    EQUAL = 297,
    SEMICOLON = 298,
    COMMA = 299,
    EXC = 300,
    DOT = 301,
    LESS = 302,
    GREATER = 303,
    K_PARSEINT = 304
  };
#endif
/* Tokens.  */
#define STRING_LITERAL 258
#define INTEGER_LITERAL 259
#define ID 260
#define D_AMPERSAND 261
#define D_LINES 262
#define SMALL_EQUAL 263
#define LARGE_EQUAL 264
#define D_EQUAL 265
#define EXC_EQUAL 266
#define PLUS 267
#define MINUS 268
#define STAR 269
#define SLASH 270
#define K_CLASS 271
#define K_INT 272
#define K_STRING 273
#define K_BOOLEAN 274
#define K_IF 275
#define K_WHILE 276
#define K_RETURN 277
#define K_NEW 278
#define K_THIS 279
#define K_TRUE 280
#define K_FALSE 281
#define K_PRINTLN 282
#define K_PRINT 283
#define K_ELSE 284
#define K_EXTENDS 285
#define K_PUBLIC 286
#define K_LENGTH 287
#define K_STATIC 288
#define K_VOID 289
#define K_MAIN 290
#define LEFT_BRACE 291
#define RIGHT_BRACE 292
#define LEFT_PAR 293
#define RIGHT_PAR 294
#define LEFT_BRACKET 295
#define RIGHT_BRACKET 296
#define EQUAL 297
#define SEMICOLON 298
#define COMMA 299
#define EXC 300
#define DOT 301
#define LESS 302
#define GREATER 303
#define K_PARSEINT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "parser.y" /* yacc.c:1909  */

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

#line 170 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
