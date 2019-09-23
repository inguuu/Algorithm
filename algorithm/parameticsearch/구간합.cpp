#include <stdio.h>

long long int s[10001];
long long int e[10001];
long long int input;
int n=0;

long long int getP(long long int x){
  long long int result=0;
  for(int i=0;i<n;i++){
    if(x>e[i]) result+=e[i]-s[i]+1;
    else{
      if(x<=s[i]) continue;
      else{
        result+=x-s[i];
      }
    }
  }
  return result;
}

int main() {

  long long start =1;
  long long end= 10000000000000 ;
  
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lld %lld",&s[i],&e[i]);
  }
  scanf("%lld",&input);
  while(1){
    
    if(start+1==end) break;
    long long int mid = (start+end)/2;
    long long int m= getP(mid);//mid의 위치
    if(m>input) end= mid;
    else start =mid;
    
    
  }
  printf("%lld",start);
  return 0;
}