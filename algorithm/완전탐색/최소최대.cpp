#include <stdio.h>

int main() {

  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);
  
  int i=1;
  int small;
  int gcd=1;
  int lcm=1;
  
  if(n<=m){
    small=n;
  }else{
    small=m;
  }
  while(1){
    
    if(m%i==0&&n%i==0){
      gcd=i;
    }
    if(i==small){
      printf("%d\n",gcd);
      break;
    }
    ++i;
  }
  
  i=1;
  while(1){
    if(i%n==0&&i%m==0){
      printf("%d",i);
      break;
    }
    ++i;
  }


  return 0;
}