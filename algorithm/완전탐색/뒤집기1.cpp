#include <stdio.h>

int main() {

  int a[100][100];
  
  int n,m;
  
  scanf("%d",&n);
  scanf("%d",&m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  
   for(int i=0;i<n;i++){
    for(int j=m-1;j>=0;j--){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}