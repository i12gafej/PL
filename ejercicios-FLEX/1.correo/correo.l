/*Zona de definiciones*/
%{
    int correos = 0;
%}
letra           [a-zA-Z]
numero          [0-9]
ln              {letra}|{numero}
entidad         {letra}+
ext             {letra}{letra}{letra}?
usuario         {letra}({ln}|(\.)|(-)({ln}))*
correo          {usuario}@{entidad}\.{ext}


/*****Zona de reglas******/
%%
{correo}       {fprintf(yyout, "CORRECTO --> <%s>\n", yytext);correos++;}
.*             {fprintf(yyout, "(X) Correo Erroneo --> <%s>\n", yytext);} 

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
  system("clear");
  yylex();

  fprintf(yyout, "Correos en total: %i\n\n\n", correos);

  return 0;
}