#include <stdio.h>


int main() {

 long long int a; 
  scanf("%lld",&a);

  long long int start =1;
  long long int end =1000000000;
  
  while(1){
    long long int mid=(start+end)/2;
    
    if(start+1==end) break;
    
    if(mid*mid+mid==a){
      start=mid;
      break;
    } 
    else if(mid*mid+mid<a) start =mid;
    else end =mid;
    
  }
  printf("%lld",start);

  return 0;
}