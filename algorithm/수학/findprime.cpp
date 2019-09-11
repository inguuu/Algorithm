#include <stdio.h>

int main() {

  int n;
  scanf("%d",&n);
  
  int num;
  int count=0;
  for(int i=0;i<n;i++){
    scanf("%d",&num);
    int val=1;
    if(num==1){

      continue;
    }
    for(int j=2;j<num;j++){
      if(num%j==0){
        val=0;
        break;
      }
    }
    
    if(val==1){
       ++count;
    }
   
  }
   
   printf("%d",count);
  return 0;
}