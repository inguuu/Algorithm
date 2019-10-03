#include <stdio.h>
#include <algorithm>
using namespace std;
int map[100][100]={0,};
int result[100]={0,};
int idx =0;
int cnt=0;
int n;
void DFS(int x,int y){
  int dr[4]={0,0,-1,1};
  int dc[4]={1,-1,0,0};
  
  map[x][y]=0;
  ++cnt;
  
  
  for(int i=0;i<4;i++){
    int xx=x+dr[i];
     int yy=y+dc[i];

     if(xx>=0&&yy>=0&&xx<n&&yy<n&&map[xx][yy]==1){
       DFS(xx,yy);
     }
  }
}
int main() {

  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf(" %1d",&map[i][j]);
    }
  }
   
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      
      
    if(map[i][j]==1){
      
      cnt=0;
      DFS(i,j);
      result[idx]=cnt;
      ++idx;
    }
      
    }
  }
  

sort(result,result+idx);
printf("%d\n",idx);
  
  for(int i=0;i<idx;i++){
   
    printf("%d\n",result[i]);
  }
   
 
   
   
  return 0;
}