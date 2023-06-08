%{
    #include<stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%
[\n] return 0;
[\t] ;

[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}

. {
    return yytext[0];
};
%%

int yywrap() {
    return 1;
}
