#include <stdio.h>
#include <queue>
using namespace std;
//여기여기 bfs 숫자 보자 
int map[22][22];
int smap[22][22];
int visited[22][22]={0,};
int num[22]={0,};
int size;
  int n,m,k;
struct p{
  int x;
  int y;
  int dis;
  int s;
};
queue <p>q;

void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      map[i][j]=smap[i][j];
      visited[i][j]=0;
     
    }
  }
  for(int i=0;i<23;i++){
     num[i]=0;
  }
}
void BFS(int x,int y){
  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0};
  visited[x][y]=1;
  q.push({x,y,0,0});

  while(!q.empty()){
    
    int nx= q.front().x;
    int ny= q.front().y;
   int nd= q.front().dis;
   int ns =q.front().s;
   size=nd;
    q.pop();
    if(ns==1){
      ++num[nd];
    }
 
    for(int i=0;i<4;i++){
      int xx= nx+dr[i];
      int yy= ny+dc[i];
      if(xx<0||yy<0||xx>=n||yy>=m)continue;
      if(visited[xx][yy]==0){
         visited[xx][yy]=1;
        if(map[xx][yy]==1){
         // 
           q.push({xx,yy,nd+1,1});
        } else{
          q.push({xx,yy,nd+1,0});
        }  
      }
    }
    
    
  }
  
  
  
}

int sc;
int Score(int x){
  
  if(x==size)return x;
  sc=0;
  int j=x;

  for(int i=1;i<=x;i++){
      sc+=j*num[i];
        --j;
  }

 
  if(sc>k){
    int result =0;
    for(int i=1;i<x;i++){
      result+=num[i];
    }
    return result;
  }
  Score(x+1);
  
}
int max1=0;
int ts=0;
int main() {
 scanf("%d",&ts);
  
  
 for(int t=0;t<ts;t++){
  
    max1=0;
    scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&map[i][j]);
      smap[i][j]=map[i][j];
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(map[i][j]==0){
        BFS(i,j);
        int score = Score(1);
       
        if(max1<score){
          max1=score;
          }
        reset();
    }
    }
  }
  
    printf("#%d %d\n",t+1,max1);
    
  }
  return 0;
  
}
//  printf("%d %d %d\n",0,2,map[0][2]);
//  BFS(0,1);
//Score(1);
//   reset();
//   BFS(0,3);
// Score(1);
//   reset();
//   BFS(1,0);
// Score(1);
//   reset();
//   BFS(1,1);
// Score(1);
// reset();
//   BFS(1,2);
// Score(1);
// reset();
//  BFS(2,2);
// Score(1);

 
