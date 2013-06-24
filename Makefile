compiler: yacc c_lex
	g++ symbol_table.cpp symbol_table_entry.cpp lex.o yacc.cc -o compiler

c_lex: lex
	gcc -c lex.yy.c -o lex.o

yacc: pl0.y
	yacc -d pl0.y -o yacc.cc

lex: pl0.l
	lex pl0.l
