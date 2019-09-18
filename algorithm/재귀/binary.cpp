#include <stdio.h>

int power(int n, int m){//n^m을 반환하는 함수
  
  if(m==0){
    return 1;
  }else{
    return n*power(n,m-1);
  }
}

int main() {

  int n;
  int m;
  
  scanf("%d %d",&n,&m);
  
  int result =power(n,m);
  printf("%d",result);
  
  return 0;
}