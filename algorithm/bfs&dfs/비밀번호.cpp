#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  
  int k;
  char c[18];
  int num[18];
  int ts;
  scanf("%d",&ts);
  for(int t=1;t<=ts;t++){
   int sum[18]={0,};
  int sum2[18]={0,};
  int sidx=0;
  scanf("%d",&k); 
  scanf("%s",c);
  
  for(int i=0;i<=17;i++){
   
   int mul=2;
    for(int j=i;j<=i+2;j++){
       int num;
       int a=j;
       if(j>17)a=a-18;
      if(48<=c[a]&&c[a]<=57){
       num=c[a]-48;
      }else{
        num=c[a]-55;
      }
      if(mul==2)sum[sidx]+=32*32*num;
      if(mul==1)sum[sidx]+=32*num;
      if(mul==0)sum[sidx]+=num;
      --mul;
    }
    ++sidx;
  }
   
   for(int i=0;i<18;i++){
     sum2[i]=sum[i];
   }
   sort(sum2,sum2+18);
     
     int ans; 
   for(int i=0;i<18;i++){
       if(sum2[k-1]==sum[i]){
         ans=i;
       }
   }
   
   if(ans>9){
     ans=18-ans;
   }
 
  printf("#%d %d %d\n",t,ans,sum2[k-1]);
  }
  
   
   
  

  return 0;
}