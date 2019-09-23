#include <stdio.h>

long long int n;
long long int k;


long long int myOrder(long long int m){
  
  long long int result =0;
  for(int i=1;i<=n;i++){
    if(i*n<m) result+=n;
    else{
      if(m%i==0) result+=m/i-1;
      else result+=m/i;
    }
    
  }
  return result+1;
  
}

int main(){
  
  scanf("%lld %lld",&n,&k);
  
  long long int start =1;
  long long int end = n*n+1;
 
  
  while(1){
    
    if(start+1==end) break;
     long long int mid =(start+end)/2;
     long long int m = myOrder(mid);
     if(m>k)end=mid;
      else start=mid;
  }
 
  printf("%lld",start);
  
  return 0;
}