#include <stdio.h>

int main() {

  int a[5][5];
  
  int dr[4]={0,1,0,-1};
  int dc[4]={1,0,-1,0};
  
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      scanf("%d",&a[i][j]);
    }
  }
  
   for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
     int count=0;
      for(int k=0;k<4;k++){
       int ni=i+dr[k];
       int nj=j+dc[k];
        if(ni<0||nj<0||nj>4||ni>4){
          ++count;
        }
        else if(a[i][j]<a[ni][nj]){
        ++count;
        }
      }
      if(count==4){
        a[i][j]=-1;
      }
    }
  }
   for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(a[i][j]==-1){
        printf("* ");
      }else{
        printf("%d ",a[i][j]);
      }
    }
    printf("\n");
  }
  
  return 0;
}