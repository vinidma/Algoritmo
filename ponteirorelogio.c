#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    struct hora{
      int sn;
      int horario;

      union{
          int hora12;
          int hora24;
      };
    }h;

    printf("\nOl�, tudo bem? digite o hor�rio:\n");
    scanf("%d", &h.horario);

    if(h.horario > 12){
        h.hora12 = h.horario;
        printf("\nO hor�rio � %dpm\n", h.hora12 - 12);
    }else{
          printf("\nHummm... O hor�rio � na parte da noite? (1 - Sim 2 - N�o)\n");
          scanf("%d", &h.sn);

          if(h.sn == 1){
              h.hora24 = h.horario;
              printf("\nO hor�rio � %dh\n", h.hora24 + 12);
          }else{
              printf("\nO hor�rio � %dh\n", h.horario);
          }
    }


    return 0;
}
