#include <stdio.h>


int r,c;
char map[21][21]={0,};
char rem[30]={0,};
int ridx=0;
int visited[21][21]={0,};
int max1=0;

int checkD(char alpha){
  for(int i=0;i<ridx;i++){
    if(alpha==rem[i])return 1;
  }
  return 0;
}
void DFS(int x,int y, int count){
  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0};
  int end=0;
  
  for(int i=0;i<4;i++){
   int  xx=x+dr[i];
    int yy=y+dc[i];
    if(xx<0||yy<0||xx>=r||yy>=c)continue;
    if(visited[xx][yy]==0&&checkD(map[xx][yy])==0){
      
      ++end;
      rem[ridx]=map[xx][yy];
      ++ridx;
      visited[xx][yy]=1;
      DFS(xx,yy,count+1);
       visited[xx][yy]=0;
      rem[ridx-1]=' ';
      --ridx;
    }
  }
  if(end==0){
  
    if(max1<count)max1=count;
  }
    
  

}

int main() {

 scanf("%d %d",&r,&c);
 for(int i=0;i<r;i++){
   for(int j=0;j<c;j++){
     scanf(" %c",&map[i][j]);
   }
 }
 rem[0]=map[0][0];
 ridx=1;
 visited[0][0]=1;
 DFS(0,0,1);
printf("%d",max1);
  return 0;
}