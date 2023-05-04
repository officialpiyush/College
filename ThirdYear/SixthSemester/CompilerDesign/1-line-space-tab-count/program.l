%{
  int num_lines = 0;
  int num_tabs = 0;
  int num_spaces = 0;
  int num_words = 0;
  int num_chars = 0;
%}

%%
\n { num_lines++; }
\t { num_tabs++; }
[ ] { num_spaces++; }
[a-zA-Z]+ { 
    num_words++;
    num_chars += strlen(yytext);
  }
. { num_chars++; }
%%

int main(int argc, char** argv) {
  yylex();

  printf("Lines: %d\n", num_lines);
  printf("Tabs: %d\n", num_tabs);
  printf("Spaces: %d\n", num_spaces);
  printf("Words: %d\n", num_words);
  printf("Characters: %d\n", num_chars);
  return 0;
}
