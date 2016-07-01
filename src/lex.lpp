%{
#include <stdio.h>
#include "parser.hpp"

int yyline = 0;

%}
%option noyywrap

%%
[ \t]+ ;
\n {yyline+= 1;}
else {return ELSE;}
if {return IF;}
int {/*printf("int\n");*/return INT;}
return {return RETURN;}
void {return VOID;}
while {return WHILE;}


[0-9]+ {yylval.ival = atoi(yytext);return NUM;}
[a-zA-Z][a-zA-Z0-9]* {/*printf("id: %s\n",yytext);*/yylval.sval = strdup(yytext); return ID;}

. {/*printf("literal: %d/%c\n",yytext[0],yytext[0]);*/return yytext[0];}
%%
