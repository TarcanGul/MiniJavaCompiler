interpret: y.tab.c lex.yy.c
	gcc -g y.tab.c lex.yy.c LinkedList.c AST.c -o interpret
y.tab.c: parser.y
	yacc -d -g --verbose parser.y
lex.yy.c: parser.l
	lex parser.l

clean:
	rm -f lex.yy.c y.tab.c interpret

debug: y.tab.c lex.yy.c
	gcc -DYYDEBUG=1 -Dparse.trace -DMYDEBUG -g y.tab.c lex.yy.c LinkedList.c -o parser
	 
