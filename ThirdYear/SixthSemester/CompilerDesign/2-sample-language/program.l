%option noyywrap

%{
  #include <stdio.h>
%}

%%
[ \t] {  }

[0-9]+ {
  printf("Integer: %s\n", yytext);
}

[a-zA-Z][a-zA-Z0-9]* {
  printf("Identifier: %s\n", yytext);
}

[\+\-\*/] {
  printf("Operator: %s\n", yytext);
}

. {
  printf("Invalid Operator: %s\n", yytext);
}
%%

int main(int argc, char** argv) {
  yylex();
  return 0;
}
