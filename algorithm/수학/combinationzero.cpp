#include <stdio.h>

int main() {

  int n,m;
  
   scanf("%d %d",&n,&m);
   
   int t=0;//2의 개수
   int f=0;//5의 개수
   
   int now;
   for(int i=0;i<m;i++){
    now=n-i;
    while(1){
      if(now%2==0){
        now=now/2;
        ++t;
      }else{
        break;
      }
    }
    
    while(1){
      if(now%5==0){
        now=now/5;
        ++f;
      }else{
        break;
      }
    }
   }
   
   for(int i=m;i>0;i--){
     now=i;
     while(1){
      if(now%2==0){
        now=now/2;
        --t;
      }else{
        break;
      }
    }
    
    while(1){
      if(now%5==0){
        now=now/5;
        --f;
      }else{
        break;
      }
    }


   }
     
     
     if(t==0||f==0){
       printf("0");
       return 0;
     }
     int count;
     if(t<f){
       count=t;
     }else{
       count=f;
     }
     
     printf("%d",count);
  return 0;
 

}