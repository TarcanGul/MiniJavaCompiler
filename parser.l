%option noyywrap
%option yylineno
%{
  #include <stdio.h>
  #include "AST.h"
  #include "y.tab.h"
  #include <assert.h>
  extern int yyparse();
//  extern YYLTYPE yylloc;
//  #define YY_USER_INIT yylloc.first_line=1;

  int isIDChar(char c)
  {
	char notID[] = {'(', ')', '*', '*', '-', '/'};
	int len = 6;
        for(int i = 0; i < len; i++)
	{
		if(c == notID[i])
		{
			return 0;
		}
	}
	return 1;
  }
%}



digit [0-9]
letter [A-Za-z]
symbol [_*/\! \t\n\\(),:]
unallowed_id [{}[]] 

%%

\/\/(.*)"\n" {/*Single line comment, do nothing.*/}

"/*"([^*]|\*[^/])*\*+"/" {/*Multiline comment, do nothing.*/} 

"class" {
	return K_CLASS;
}

"Integer.parseInt" {
	return K_PARSEINT;
}

"int" {
	return K_INT;
}

"String" {
	return K_STRING;
}

"boolean" {
	return K_BOOLEAN;
}

"if" {
	return K_IF;
}

"else" {
	return K_ELSE;
}

"while" {
	return K_WHILE;
}

"return" {
	return K_RETURN;
}

"new" {
	return K_NEW;
}

"this" {
	return K_THIS;
}

"true" {
	return K_TRUE;
}

"false" {
	return K_FALSE;
}

"extends" {
	return K_EXTENDS;
}

"public" {
	return K_PUBLIC;
}

"length" {
	return K_LENGTH;
}

"System.out.println" {
	return K_PRINTLN;
}

"System.out.print" {
	return K_PRINT;
}

"static" {
	return K_STATIC;
}

"void" {
	return K_VOID;
}

"main" {
	return K_MAIN;
}

"&&" {
	return D_AMPERSAND;
}

"||" {
	return D_LINES;
}

"<=" {
	return SMALL_EQUAL;
}

">=" {
	return LARGE_EQUAL;
}

"==" {
	return D_EQUAL;
}

"!=" {
	return EXC_EQUAL;
}

"++" {/*Do nothing.*/}

"+" {
	return PLUS;
}

"--" {/*Do notthing*/}

"-" {
	return MINUS;
}

"*" {
	return STAR;
}

"/" {
	return SLASH;
}

"{" {
	return LEFT_BRACE;
}

"}" {
	return RIGHT_BRACE;
}

"(" {
	return LEFT_PAR;
}

")" {
	return RIGHT_PAR;
}

"[" {
	return LEFT_BRACKET;
}

"]" {
	return RIGHT_BRACKET;
}

"=" {
	return EQUAL;
}

";" {
	return SEMICOLON;
}

"," {
	return COMMA;
}

"!" {
	return EXC;
}

"." {
	return DOT;
}

"<" {
	return LESS;
}

">" {
	return GREATER;
}

({letter}|"_")({letter}|{digit}|"_")* {
	yylval.string_val = strdup(yytext);
	return ID;
}

\"([^"\\]|\\.)*\" {
	yylval.string_val = strdup(yytext);
	return STRING_LITERAL;
}


{digit}+ {
/*We are allowing 0's at start.*/
	yylval.integer_val = atoi(yytext);
        return INTEGER_LITERAL;
}

[ \t\r\n] {/*Do nothing.*/}


%%
