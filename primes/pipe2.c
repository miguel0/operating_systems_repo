#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int p = 0;
  int num = 0;

  scanf("%d\n",&p);
  fprintf(stderr,"%d\n",p);
  num = p;

  while(1){
    scanf("%d\n",&num);
    if(num == -1){
      fprintf(stdout,"%d\n",-1);
      break;
    }
    if(num % p != 0){
      fprintf(stdout,"%d\n",num);
    }
  }
}