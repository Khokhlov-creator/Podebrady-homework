#include <stdio.h>

int main (void){
  
  int c;
  if (scanf_s("%d", &c) != 1) {
    printf("Chyba ve vvodu");
    return 1;
  }

  int prvo[4] = { 2, 3, 5, 7 }, neniDelitel = 1,i;
  for (i = 0; i < 4; i++)
    if (c % prvo[i] == 0) {
      if (neniDelitel) printf("Cislo je delitelne ");
      printf("%d, ", prvo[i]);
      neniDelitel = 0;
    }
  if (neniDelitel) printf("Cislo neni delitelne");
  return 0;
}
