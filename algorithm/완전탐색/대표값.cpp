#include <stdio.h>

int main() {

  int sum=0;
  int num[10];
  int count[1001]={0, };


   for(int i=0;i<10;i++){
     scanf("%d",&num[i]);
     sum+=num[i];
     ++count[num[i]];
   }
   
   int max=0;
   int idx;
   for(int i=10;i<1001;i=i+10){
    
     if(max<count[i]){
       max=count[i];
       idx=i;
     }
   }
   
   printf("%d\n",sum/10);
   printf("%d",idx);
  return 0;
}