#include <stdio.h>
#include <queue>

using namespace std;


int sx,sy,sd,ex,ey,ed;
int map[101][101];
int visited[101][101][5]={0,};
int resultcount;
int resultmin=999999;
int n,m;
int dr[5]={0,0,0,1,-1};
int dc[5]={0,1,-1,0,0};

struct p{
  int x;
  int y;
  int d;
  int c;
};
queue <p> q;

void BFS(){
  q.push({sx,sy,sd,0});
  visited[sx][sy][sd]=1;
  while(!q.empty()){
    int nx=q.front().x;
    int ny=q.front().y;
    int nd=q.front().d;
    int nc=q.front().c;
    q.pop();
    
    //printf("%d %d %d %d\n",nx,ny,nd,nc);
   if(nx==ex&&ny==ey&&nd==ed){
     
     printf("%d",nc);
     return;
    }
  //5가지 케이스 중 2가지 케이스 방향 바꾸기
  if(nd==1||nd==2){
     if(visited[nx][ny][3]==0){
        q.push({nx,ny,3,nc+1});
        visited[nx][ny][3]=1;
     }
      if(visited[nx][ny][4]==0){
      q.push({nx,ny,4,nc+1});
        visited[nx][ny][4]=1;
     }
  }
  if(nd==3||nd==4){
     if(visited[nx][ny][1]==0){
        q.push({nx,ny,1,nc+1});
        visited[nx][ny][1]=1;
     }
      if(visited[nx][ny][2]==0){
      q.push({nx,ny,2,nc+1});
        visited[nx][ny][2]=1;
     }
  }
  // 1, 2, 3칸 가기
  for(int i=1;i<=3;i++){
    
    int xx= nx+dr[nd]*i;
    int yy= ny+dc[nd]*i;

    if(xx<1||yy<1||xx>n||yy>m)continue;
    if(map[xx][yy]==1) break;
    if(visited[xx][yy][nd]==0){
         visited[xx][yy][nd]=1;
         q.push({xx,yy,nd,nc+1});
    }
  }
  }
}

int main() {

  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
     scanf("%d",&map[i][j]); 
    }
  }
  
  scanf("%d %d %d %d %d %d",&sx,&sy,&sd,&ex,&ey,&ed);
  BFS();

  return 0;
}