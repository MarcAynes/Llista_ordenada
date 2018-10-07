#include<stdio.h>
#include"Llista_PDI"
void main(){
  Llista_PDI llista;
  llista = PDI_crea();
  printf("\ncreada la llista bidirecional\n");
  PDI_escriu(&llista, 5);
  printf("\nafegim a la llista el nuero 5\n");
  PDI_escriu(&llista, 10);
  printf("\nafegim a la llista el nuero 10\n");
  PDI_vesInici(&llista);
  printf("\nllegim els numeros afegits\n");
  printf("%d\n", PDI_llegeix(llista));
  PDI_avanca(&llista);
  printf("%d\n", PDI_llegeix(llista));
  PDI_destrueix(&llista);
  printf("\ndestruim la llista ordenada\n");
}
