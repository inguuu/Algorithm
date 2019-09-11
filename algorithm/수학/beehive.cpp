#include <stdio.h>

int main() {

  int start =1;
  
  int a=1;
  int b=1;
  int n;
  int count=1;
  scanf("%d",&n);
  while(1){
    
    if(a<=n&&n<=b){
      printf("%d",count);
       return 0;
    }
    a=b;
    b=a+6*count;
    ++count;
    
  }
 
}