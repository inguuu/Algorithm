#include <stdio.h>

int main() {
  
  int map[10][10];

  
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      scanf("%d",&map[i][j]);
   }
  }
  
  int max=0;
  int ni,nj;
  
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      if(map[i][j]>max){
        max=map[i][j];
        ni=i;
        nj=j;
      }
        
   }
  }
  
  printf("%d\n",max);
   printf("%d %d",ni,nj);
  return 0;
}