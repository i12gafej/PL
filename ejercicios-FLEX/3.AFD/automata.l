

%x q1 q2 q3
%%

encender    {
                fprintf(yyout , "%s: q0 --> q1\n", yytext);
                BEGIN q1;
            }
<q1>acelerar|frenar     {
                fprintf(yyout , "%s: q1 --> q1\n", yytext);
                BEGIN q1;
           }
<q1>apagar  {
                fprintf(yyout , "%s: q1 --> q3\n", yytext);
                BEGIN q3;
                return 0;
            }
<q1>embragar {
                fprintf(yyout , "%s: q1 --> q2\n", yytext);
                BEGIN q2;
            }
<q1>.*      {fprintf(yyout , "Comando no valido en Q1 <%s>\n", yytext);}
<q2>frenar  {
                fprintf(yyout , "%s: q2 --> q2\n", yytext);
                BEGIN q2;
            }
<q2>cambiar  {
                fprintf(yyout , "%s: q2 --> q1\n", yytext);
                BEGIN q1;
            }
<q2>.*  {fprintf(yyout , "Comando no valido en Q2 <%s>\n", yytext);}
.*  {fprintf(yyout , "Comando no valido en Q0 <%s>\n", yytext);}




%%
extern FILE *yyin, *yyout;

int main(int argc, char *argv[])
{
 
    switch(argc)/*Comprobar que el fichero de entrada existe*/
    {
    case 2:  yyin=fopen(argv[1],"r"); 
                break;
    case 3:  yyin=fopen(argv[1],"r"); 
                yyout=fopen(argv[2],"w"); 
    }

    yylex();

  

  return 0;
}