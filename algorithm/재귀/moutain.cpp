#include <stdio.h>

void mon(int n){
  if(n>1){
    mon(n-1);
    printf("%d",n);
    mon(n-1);
  }else{
    printf("1");
  }
}
int main() {
int n;
scanf("%d",&n);
  mon(n);

  return 0;
}