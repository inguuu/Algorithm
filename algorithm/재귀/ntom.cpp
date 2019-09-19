#include <stdio.h>

int NM(int n,int m){
  if(n==m){
    return n;
  }else{
    
    return m+NM(n,m-1);
    
  }
  
}

int main() {

  int n,m; 
  scanf("%d %d",&n,&m);
  
  printf("%d",NM(n,m));

  return 0;
}