

%x q1 q2 q3
%%

encender    {
                printf("%s: q0 --> q1\n", yytext);
                BEGIN q1;
            }
<q1>acelerar|frenar     {
                printf("%s: q1 --> q1\n", yytext);
                BEGIN q1;
           }
<q1>apagar  {
                printf("%s: q1 --> q3\n", yytext);
                BEGIN q3;
                return 0;
            }
<q1>embragar {
                printf("%s: q1 --> q2\n", yytext);
                BEGIN q2;
            }
<q1>.*  {printf("Comando no valido\n");}
<q2>frenar  {
                printf("%s: q2 --> q2\n", yytext);
                BEGIN q2;
            }
<q2>cambiar  {
                printf("%s: q2 --> q1\n", yytext);
                BEGIN q1;
            }
<q2>.*  {printf("Comando no valido\n");}
.*  {printf("Comando no valido\n");}




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