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

    printf("\nOlá, tudo bem? digite o horário:\n");
    scanf("%d", &h.horario);

    if(h.horario > 12){
        h.hora12 = h.horario;
        printf("\nO horário é %dpm\n", h.hora12 - 12);
    }else{
          printf("\nHummm... O horário é na parte da noite? (1 - Sim 2 - Não)\n");
          scanf("%d", &h.sn);

          if(h.sn == 1){
              h.hora24 = h.horario;
              printf("\nO horário é %dh\n", h.hora24 + 12);
          }else{
              printf("\nO horário é %dh\n", h.horario);
          }
    }


    return 0;
}
