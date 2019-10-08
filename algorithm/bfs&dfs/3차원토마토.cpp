#include <stdio.h>
#include <queue>

using namespace std;

int n,m,h;

int map[101][101][101];
int visited[101][101][101]={0,};
int dr[6]={1,-1,0,0,0,0};
int dc[6]={0,0,-1,1,0,0};
int dh[6]={0,0,0,0,1,-1};

struct p{
  int x;
  int y;
  int z;
  int c;
};

queue<p> q;
  int count =0;
void BFS(){
  

  while(!q.empty()){
  
    int nx=q.front().x;
    int ny=q.front().y;
    int nz=q.front().z;
    int nc=q.front().c;
    visited[nx][ny][nz]=1;
    count=nc;
    q.pop();
    
    for(int i=0;i<6;i++){
      int xx = nx+dr[i];
      int yy = ny+dc[i];
      int zz = nz+dh[i];
      
      if(xx<0||yy<0||zz<0||xx>=n||yy>=m||zz>=h) continue;
  
      
      if(visited[xx][yy][zz]==0&&map[xx][yy][zz]!=-1){
        visited[xx][yy][zz]=1;
        map[xx][yy][zz]=1;
       
        q.push({xx,yy,zz,nc+1});
      }
    }
    
  }
  
  
}

int Full(){
  
   for(int k=0;k<h;k++){
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
      if(map[i][j][k]==0){
        return 0;
      }
    }
   }
 }
 return 1;
  
}
int main() {
  scanf("%d %d %d",&m,&n,&h);
 for(int k=0;k<h;k++){
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
     scanf("%d",&map[i][j][k]);
    }
   }
   
 }
  if(Full()==1){
    printf("0");
    return 0;
  } 
  
  for(int k=0;k<h;k++){
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
      if(map[i][j][k]==1){
        q.push({i,j,k,0});
      }
    }
   }
 }
 
 BFS();
 
 
 if(Full()==1) printf("%d",count);
 else printf("-1");

  return 0;
}