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

"if" {
  return IF;
}

"else" {
  return ELSE;
}

">" {
  return GREATER_THAN;
}

"<" {
  return SMALLER_THAN;
}

"(" {
  return LPAREN;
}

")" {
  return RPAREN;
}

"{" {
  return LCURLY;
}

"}" {
  return RCURLY;
}

. {
  fprintf(stderr, "Invalid Character Found: %s\n", yytext);
}
%%

