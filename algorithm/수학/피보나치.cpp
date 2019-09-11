#include <stdio.h>

int main() {

 int a[45];
 a[0]=0;
 a[1]=1;
 int n;
 
  scanf("%d",&n);
  
  for(int i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
    
  }
  
  printf("%d\n",a[n]);

  return 0;
}