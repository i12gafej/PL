%{
#include <stdio.h>
%}
%x Q1 Q2 Q3 Q4
exclamacion "!"
/*Vamos a hacer un automata que lea los comentarios de <! >*/
%%
"<" {
        yymore();
        BEGIN(Q1);
    }
<Q1>" "{exclamacion} {
            printf("exclamación\n");
            yymore();
            BEGIN(Q2);
        }
<Q2>[^>] {
            printf("Texto\n");
            yymore();
        }
<Q2>">" {
            printf("Exitoo\n");
            BEGIN(INITIAL);
        }
%%
