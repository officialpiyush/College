%{
  #include <stdio.h>

  int yyerror(char* error) {
    fprintf(stderr, "Error: %s\n", error);
    return 0;
  }
%}

%token INTEGER
%token PLUS
%token TIMES
%token LPAREN
%token RPAREN

%%
expr : INTEGER | expr PLUS expr | expr TIMES expr | LPAREN expr RPAREN;
%%

int main(int argc, char** argv) {
  yylex();
  return 0;
}
