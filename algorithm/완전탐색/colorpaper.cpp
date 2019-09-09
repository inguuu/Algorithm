#include <stdio.h>

int main() {

  int n;
  int map[101][101]={0,};
  int view[101]={0,};
  scanf("%d",&n);
  
  int x1[101];
  int y1[101];
  int i1[101];
  int j1[101];
  
  for(int k=1;k<=n;k++){
    scanf("%d",&x1[k]);
    scanf("%d",&y1[k]);
    scanf("%d",&i1[k]);
    scanf("%d",&j1[k]);
  }
 
 for(int k=1;k<=n;k++){
  for(int i=x1[k];i<x1[k]+i1[k];i++){
    for(int j=y1[k];j<y1[k]+j1[k];j++){
     map[i][j]=k;
    }
  }
 }
 
   for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
     ++view[map[i][j]];
    }
  }
 
   
  for(int i=1;i<=n;i++){
   printf("%d\n",view[i]);
  }
  
 
  return 0;
}