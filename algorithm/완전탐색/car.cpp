#include <stdio.h>

int main() {

  int d;
  int c[5];
  
  scanf("%d",&d);
  
  for(int i=0;i<5;i++){
    scanf("%d",&c[i]);
  }
  
  int count =0;
  
  for(int i=0;i<5;i++){
    if(d==c[i]){
      ++count;
    }
  }
   printf("%d",count);
  return 0;
}