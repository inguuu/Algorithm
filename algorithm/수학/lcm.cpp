#include <stdio.h>

int main() {

 long long int a,b;
 
 scanf("%lld",&a);
 scanf("%lld",&b);
 

  long long int cd[10000];
  long long int ef[10000];
  long long int i=1;
  long long int j=2;
  long long int k=0;
   

  
  while(1){
    
    if(a%j==0){
      cd[k]=j;
      a=a/j;
      ++k;
    }else{
      ++j;
    }
    
    if(a==1){
      break;
    }
  
  }
  
     j=2;
    k=0;
  while(1){
    
    if(b%j==0){
     
      ef[k]=j;
      b=b/j;
      ++k;
    }else{
      ++j;
    }
    
    if(b==1){
      break;
    }
  
  }

   
   int countx =0;
    int county =0;
   for(int x=0;x<10000;x++){
     if(cd[x]>0){
       ++countx;
     }
       if(ef[x]>0){
       ++county;
     }
   }

   
   for(int x=0;x<countx;x++){
     int p=0;
     for(int y=0;y<county;y++){
       if(cd[x]==ef[y]&&p==0){
         ef[y]=0;
         p=1;
       }
     }
   }
   
   long long int answer=1;
   for(int x=0;x<countx;x++){

     if(cd[x]>0){
     answer=answer*cd[x];
     }
   }
   for(int x=0;x<county;x++){
     if(ef[x]>0){
       answer=answer*ef[x];
     }
     
   }
   
   printf("%lld",answer);


}