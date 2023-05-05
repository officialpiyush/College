%option noyywrap

%{
  #include "y.tab.h"
%}

digit [0-9]
number {digit}+
ws [ \t]

%%
{number}+ {
  yylval = atoi(yytext);
  return INTEGER;
}

{ws}+ { }

"+" {
  return PLUS;   
}

"*" {
  return TIMES;
}

"(" {
  return LPAREN;
}

")" {
  return RPAREN;
}

. {
  fprintf(stderr, "Invalid Character Found: %s\n", yytext);
}
%%

