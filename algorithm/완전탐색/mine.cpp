#include <stdio.h>

int main() {

  int dr[8]={-1,-1,-1,0,0,1,1,1};
  int dc[8]={-1,0,1,-1,1,-1,0,1};
  
  int map[101][101];
  
  int n,m,x,y;
  
  scanf("%d",&n);
  scanf("%d",&m);
  
  scanf("%d",&x);
  scanf("%d",&y);
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%d",&map[i][j]);
    }
  }
  

  if(map[x][y]==1){
          printf("game over");
   }else{
    int count=0;
    for(int i=0;i<8;i++){
      int xx = x+dr[i];
      int yy = y+dc[i];
      
      if(map[xx][yy]==1){
        ++count;
      }
    }
    printf("%d",count);
     
   }
    return 0;
        

}