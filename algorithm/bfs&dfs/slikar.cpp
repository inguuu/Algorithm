#include <stdio.h>
#include <queue>

using namespace std;
int map[51][51];
int visited[51][51]={0,};
int visited2[51][51]={0,};
int r;
int c;
int sx,sy,ex,ey,wx,wy;
struct p{
  int x;
  int y;
};
struct p2{
  int x;
  int y;
  int c;
};
queue <p> q;
queue <p2> q2;

int dr[4]={0,0,-1,1};
int dc[4]={1,-1,0,0};

void water(){

  
  while(!q.empty()){
    int nx=q.front().x;
    int ny=q.front().y;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx<0||yy<0||xx>=r||yy>=c)continue;
      if(visited[xx][yy]==0&&map[xx][yy]==0){
        visited[xx][yy]=1;
        map[xx][yy]=map[nx][ny]+1;
        q.push({xx,yy});
      }
    }
  }
}

void go(){
  q2.push({sx,sy,0});
  visited2[sx][sy]=1;
  
  while(!q2.empty()){
    int nx=q2.front().x;
    int ny=q2.front().y;
    int nc=q2.front().c;

    q2.pop();
    if(nx==ex&&ny==ey){
      printf("%d\n",nc);
      return;
    }
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx<0||yy<0||xx>=r||yy>=c)continue;
      if(visited2[xx][yy]==0&&nc+1<map[xx][yy]){
        
       
       
      // printf("%d %d %d %d\n",xx,yy,nc,map[xx][yy]);
          visited2[xx][yy]=1;
          q2.push({xx,yy,nc+1});
        }
        
      }
    }
  
  printf("KAKTUS\n");
}
int main() {
  
  scanf("%d %d",&r,&c);
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char input;
      scanf(" %c",&input);
      if(input=='.')map[i][j]=0;
      if(input=='*'){
        map[i][j]=0;
        q.push({i,j});
      }
      if(input=='X')map[i][j]=-2;
      if(input=='S'){
        map[i][j]=0;
        sx=i;
        sy=j;
      }
       if(input=='D'){
        map[i][j]=9999999;
        ex=i;
        ey=j;
      }
    }
  }
  water();
  go();

  return 0;
}