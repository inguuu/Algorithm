#include <stdio.h>

int main() {
  int b[100];
  int a[100];
   b[0]=0;
   b[1]=1;
  
  int n;
  scanf("%d",&n);
  
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]);
    a[i]=i*b[i]-(i-1)*b[i-1];
    printf("%d ",a[i]);
  }
  
  

  return 0;
}