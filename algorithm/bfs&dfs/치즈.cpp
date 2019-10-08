#include <stdio.h>
#include <queue>

using namespace std;
int map[101][101]={0,};
int cheese[1000]={0,};
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

int n,m;
int visited[101][101]={0,};
int count =-1;

struct p{
  int x;
  int y;
};

queue <p> q;

int clear(){
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]!=0){
         return 0;
      }
     
    }
  }
  return 1;
}
void cheesenum(int idx){
  int num=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]==1){
        ++num;
      }
     
    }
  }


  cheese[idx]=num;
}
void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     visited[i][j]=0;
     
    }
  }
  
}

void BFS2(){
  q.push({0,0});
  visited[0][0]=1;
  if(map[0][0]==2){
    map[0][0]=0;
  }
  
  while(!q.empty()){
    int nx=q.front().x;
    int ny=q.front().y;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx<0||yy<0||xx>=n||yy>=m)continue;
      if(visited[xx][yy]==0){
        if(map[xx][yy]==0)q.push({xx,yy});
        else if(map[xx][yy]==2)map[xx][yy]=0;
        visited[xx][yy]=1;
      }
      
    }
  }
}

void BFS1(){
  q.push({0,0});
  visited[0][0]=1;
  if(map[0][0]==1){
    map[0][0]=2;
  }
  
  while(!q.empty()){
    int nx=q.front().x;
    int ny=q.front().y;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
     
      if(xx<0||yy<0||xx>=n||yy>=m)continue;
       
      if(visited[xx][yy]==0){
       
        if(map[xx][yy]==0)q.push({xx,yy});
        else if(map[xx][yy]==1)map[xx][yy]=2;
        visited[xx][yy]=1;
      }
      
    }
  }
}


int main() {

  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&map[i][j]);
    }
  }
  while(1){
    
    if(clear()==1)break;
    cheesenum(count);
    reset();
    BFS2();
    reset();
    BFS1();
    ++count;
    
    
  }
  
  printf("%d \n%d",count,cheese[count-2]);

  return 0;
}