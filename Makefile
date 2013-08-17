compiler: yacc lex
	g++ -g yacc.cpp lex.cpp symbol_table/src/* ast/src/* memory_management/src/* -o compiler -Wno-write-strings

lex: yacc pl0.l
	lex -o lex.cpp pl0.l

yacc: pl0.y
	yacc -d -o yacc.cpp pl0.y
