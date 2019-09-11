#include <stdio.h>

int main() {

  int n;
  
  int t[100000]={0,};
   scanf("%d",&n);

  for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
  }
   
   int a=t[1]-t[0];
   int  b,r;
   int gcd=1;
   for(int i=0;i<n-2;i++){
      b=t[i+2]-t[i+1];
      r=a%b;
     // printf("%d %d %d %d\n",a,b,r,gcd);
      if(r==0){
        gcd=b;
        continue;
      }
     while(1){
       a=b;
      b=r;
      r=a%b;
       if(r==0){
         break;
       }
     }
     a=b;
     gcd=b;
     
  }
  
  int count =0;
  for(int i=0;i<n-1;i++){
    count = count + (t[i+1]-t[i])/gcd-1;
  }
  
  printf("%d",count);
   
   
 
  return 0;
}