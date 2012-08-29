%{
enum token { K_CONST=1, K_VAR, K_PROCEDURE, K_CALL, K_BEGIN, K_END, K_IF, K_THEN, K_WHILE, K_DO, K_ODD,
	COMMA, SEMICOLON, EX_MARK, QUE_MARK, BEQ, SEQ, ASSIGN, EQ, PLUS, MINUS, MUL, DIV, LT, GT, HASH, DOT, L_BRACE, R_BRACE,
	IDENTIFIER, NUMBER,
	ERROR, WHT};
%}
%%
const		return K_CONST;
var			return K_VAR;
procedure	return K_PROCEDURE;
call		return K_CALL;
begin		return K_BEGIN;
end			return K_END;
if			return K_IF;
then		return K_THEN;
while		return K_WHILE;
do			return K_DO;
odd			return K_ODD;

,			return COMMA;
;			return SEMICOLON;
!			return EX_MARK;
\?			return QUE_MARK;
\>=			return BEQ;
\<=			return SEQ;
:=			return ASSIGN;
=			return EQ;
\+			return PLUS;
\-			return MINUS;
\*			return MUL;
\/			return DIV;
\<			return LT;
\>			return GT;
#			return HASH;
\(			return L_BRACE;
\)			return R_BRACE;
\.			return DOT;
[a-zA-Z_]+[0-9a-zA-Z_]* return IDENTIFIER;
[0-9]+(.[0-9]+)?	return NUMBER;
((\\r?\\n))+|(\\t)+|(" ")+|""		return WHT;
.			return ERROR;
%%

