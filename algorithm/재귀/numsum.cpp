#include <stdio.h>

int sum(int n){
  
  if(n/10<1){
    return n;
  }else{
    sum(n/10)+n%10;
  }
}

int main() {

  int n;
  scanf("%d",&n);
  
  printf("%d",sum);

  return 0;
}