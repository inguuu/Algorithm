#include <stdio.h>
#include <queue>

using namespace std;

int visited[101][101]={0,};
int count =0;
int x,y,k;
int n;
int map[101][101]={0,};

  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0};
  
struct p{
  int a;
  int b;
};

int end(){
  for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
     if(map[i][j]>k&&map[i][j]!=99999){
      return 1;
     }
   }
 }
 return 0;
}
void BFS(int a, int b){

  
  visited[a][b]=1;
  queue<p> q;
  q.push({a,b});
  
  while(!q.empty()){
    int nx=q.front().a;
    int ny=q.front().b;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      
      if(xx<1||yy<1||xx>n||yy>n)continue;
      if(visited[xx][yy]==0&&map[xx][yy]!=99999){
        map[xx][yy]=map[nx][ny]+1;
        visited[xx][yy]=1;
        q.push({xx,yy});
      }
    }
  }
  
}


int main() {

 scanf("%d",&n);
 for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
     scanf("%d",&map[i][j]);
     if(map[i][j]==1)map[i][j]=99999;
   }
 }
 
     scanf("%d %d %d",&x,&y,&k);
 BFS(y,x);
 int e=end();
 if(end()==0){
   printf("-1");
   return 0;   
 }
  map[x][y]=0;
  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++){
  //     printf("%d ",map[i][j]);
  //   }
  //   printf("\n");
  // }
 for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
       if(map[i][j]==k){
        ++count;
       }
     }
   }
 
 printf("%d",count);

  return 0;
}