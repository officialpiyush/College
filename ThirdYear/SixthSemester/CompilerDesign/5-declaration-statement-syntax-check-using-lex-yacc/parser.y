%{
#include <stdio.h>
#include <stdlib.h>
%}

%start S
%token id INT INUM

%%
S : S DL { printf("Declaration accepted\n"); }
| DL { printf("Declaration accepted\n"); }
;

DL : INTV ';'
;

INTV : INT IV
;

IV : I
| IV ',' id
| IV ',' id '=' INUM
| id '=' INUM
;

I : id
;
%%

int main() {
    printf("Enter Valid Declaration\n");
    yyparse();
    return 0;
}

int yyerror(char *msg) {
    printf("Invalid Statement\n");
    printf("%s\n", msg);
    exit(1);
}
