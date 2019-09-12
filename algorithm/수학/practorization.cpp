#include <stdio.h>

int main() {

  int n;
  scanf("%d",&n);
  
  if(n==1){
    return 0;
  }
  
  for(int i=2;n>1;){
    if(n%i==0){
      printf("%d\n",i);
      n=n/i;
    }else{
      ++i;
    }
  }
  

  return 0;
}