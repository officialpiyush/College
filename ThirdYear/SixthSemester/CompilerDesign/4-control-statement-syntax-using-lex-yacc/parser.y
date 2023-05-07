%{
  #include <stdio.h>
%}

%token IF ELSE
%token INTEGER
%token LPAREN RPAREN
%token LCURLY RCURLY
%token SMALLER_THAN GREATER_THAN

%%
if_else : if_statement ELSE if_statement
        | if_statement ELSE LCURLY RCURLY
        ; 

if_statement : IF compare
             ;

compare : compare_paren LCURLY RCURLY
        ;

compare_paren : LPAREN compare_exp RPAREN
              ;

compare_exp : INTEGER
            | compare_exp SMALLER_THAN compare_exp
            | compare_exp GREATER_THAN compare_exp
            ;
%%

int main(int argc, char** argv) {
  yyparse();
  return 0;
}

void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
}
