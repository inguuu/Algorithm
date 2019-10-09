#include <stdio.h>
#include <queue>

using namespace std;
struct p{
  int x;
  int y;
};
int n,m;
int map[301][301];
int nmap[301][301];
queue <p> q;
queue <p> cq;
int count;//맵전체 얼음
int count2;// 아무점 기준 얼음
int day2=0;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int visited[301][301]={0,};

void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      visited[i][j]=0;
    }
  }
}
void BFS(){
  // map보고 nmap에 기록하고 다 끝나면 map에도 nmap 대입
  reset();
  
  while(!q.empty()){
    int x = q.front().x;
    int y = q.front().y;
    q.pop();
    visited[x][y]=1; 
    
    for(int i=0;i<4;i++){
      int xx=x+dr[i];
      int yy=y+dc[i];
      if(xx<0||yy<0||xx>=n||yy>=m)continue;
      if(map[xx][yy]==0&&visited[xx][yy]==0){
        if(nmap[x][y]>0)--nmap[x][y];
        
      }
      if(map[xx][yy]>0&&visited[xx][yy]==0){
        visited[xx][yy]=1;
      }
      
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       map[i][j]=nmap[i][j];
    }
  }
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//       printf("%d ",nmap[i][j]);
//     }
//     printf("\n");
//   }
// printf("\n");
}
void check(){
  reset();
 count2=1;
 while(!cq.empty()){
     int x=cq.front().x;
     int y=cq.front().y;
     cq.pop();
     visited[x][y]=1;
     for(int i=0;i<4;i++){
       int xx=x+dr[i];
       int yy=y+dc[i];
       if(xx<0||yy<0||xx>=n||yy>=m)continue;
       if(visited[xx][yy]==0&&map[xx][yy]>0){
         ++count2;
         visited[xx][yy]=1;
         cq.push({xx,yy});
       }
     }
 }

  
  
}
int main() {

  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&map[i][j]);
      nmap[i][j]=map[i][j];
    }
  }
  
  while(1){
    //빙산 넣기
    count=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
       if(map[i][j]>0){
         ++count;
         q.push({i,j});
      }
     }
    }
    // 검사
    int one =0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
       if(map[i][j]>0&&one==0){
         cq.push({i,j});
        check();
        one=1; 
       }
      }
    }
    // 분리확인
    if(count!=count2){
      printf("%d",day2);
      return 0;
    }
    if(count==0){
       printf("0");
      return 0;
    }
    
    BFS();
    ++day2;
    
  }
  
  return 0;
}