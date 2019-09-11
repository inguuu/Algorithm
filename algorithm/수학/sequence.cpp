#include <stdio.h>

int main() {
  int a[1002];
  int s[1002][1002]={0,};
   a[0]=0;
  int n;
  scanf("%d",&n);
  
  for(int i=1;i<=2;i++){
    for(int j=1;j<=n;j++){
      scanf("%d",&s[i][j]);
    }
  }
  
  a[1]=(s[1][3]- s[2][3]+s[1][2])/2;
  printf("%d ",a[1]);

  for(int i=2;i<=n;i++){
      a[i]=s[1][i]-a[1];
      printf("%d ",a[i]);
  }
  

 
  return 0;
}