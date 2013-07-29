%{
#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

#include "yacc.hpp"

#define DEBUG 1

int line = 1;

void debug_print(char * s);
extern "C" int yywrap() { return 1; }
%}

%%
"CONST"					{ debug_print("CONST"); return K_CONST; }
"VAR"					{ debug_print("VAR"); return K_VAR; }
"PROCEDURE"				{ debug_print("PROCEDURE"); return K_PROCEDURE; }
"CALL"					{ debug_print("CALL"); return K_CALL; }
"BEGIN"					{ debug_print("BEGIN"); return K_BEGIN; }
"END"					{ debug_print("END"); return K_END; }
"IF"					{ debug_print("IF"); return K_IF; }
"THEN"					{ debug_print("THEN"); return K_THEN; }
"WHILE"					{ debug_print("WHILE"); return K_WHILE; }
"DO"					{ debug_print("DO"); return K_DO; }
"ODD"					{ debug_print("ODD"); return K_ODD; }

","						{ debug_print("COMMA"); return COMMA; }
";"						{ debug_print("SEMMICOLON"); return SEMICOLON; }
"!"						{ debug_print("EX_MARK"); return EX_MARK; }
"?"						{ debug_print("QUE_MARK"); return QUE_MARK; }
">="					{ debug_print("BEQ"); return BEQ; }
"<="					{ debug_print("SEQ"); return SEQ; }
":="					{ debug_print("ASSING"); return ASSIGN; }
"="						{ debug_print("EQ"); return EQ; }
"+"						{ debug_print("PLUS"); return PLUS; }
"-"						{ debug_print("MINUS"); return MINUS; }
"*"						{ debug_print("MUL"); return MUL; }
"/"						{ debug_print("DIV"); return DIV; }
"<"						{ debug_print("LT"); return LT; }
">"						{ debug_print("GT"); return GT; }
"#"						{ debug_print("HASH"); return HASH; }
"("						{ debug_print("L_BRACE"); return L_BRACE; }
")"						{ debug_print("R_BRACE"); return R_BRACE; }
"."						{ debug_print("DOT"); return DOT; }
[a-zA-Z_]+[0-9a-zA-Z_]* { debug_print("IDENTIFIER"); strcpy(yylval.string, yytext); return IDENTIFIER; }
[0-9]+(.[0-9]+)?		{ debug_print("NUMBER"); yylval.number = atoi(yytext); return NUMBER; }
[ \t]+					{ ; }
\n						{ line++; }
.						{ debug_print("ERROR"); return ERROR; }
%%

void debug_print(char * s) {
	if(DEBUG)
		printf("%s, Z.:%i \n", s, line);
}

/*
int yywrap() {
	return 1;
}
*/
/*
int main() {
	while(yylex());
}
*/

