%{
    #include<stdio.h>
    int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
ArithmeticExpression: E {
printf("\nResult=%d\n", $$);
return 0;
};

E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| NUMBER {$$=$1;}
;
%%


void main() {
    printf("\nEnter Arithmetic Expression:\n");
    yyparse();

    if(flag==0)
        printf("\nValid Arithmetic Expression\n");
}
void yyerror() {
    printf("\nInvalid Arithmetic Expression\n");
    flag=1;
}
