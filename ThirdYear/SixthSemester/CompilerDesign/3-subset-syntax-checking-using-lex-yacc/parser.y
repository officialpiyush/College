%{
  #include <stdio.h>
%}

%token INTEGER
%token PLUS
%token TIMES
%token LPAREN
%token RPAREN

%%
expr : INTEGER 
     | expr PLUS expr 
     | expr TIMES expr 
     | LPAREN expr RPAREN
     ;
%%

int main(int argc, char** argv) {
  yyparse();
  return 0;
}

void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
}
