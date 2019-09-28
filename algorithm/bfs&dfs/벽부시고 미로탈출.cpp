#include <stdio.h>
#include<queue>
using namespace std;

 int map[1001][1001]={0,};
  int smap[1001][1001]={0,};
  int visited[1001][1001]={0,};
  
  int n,m;
  
  
  int d1[100000]={0,};
  int d2[100000]={0,};
  int idx=0;
  int sr,sc,er,ec;
   queue <pair<int,int>> q;
  
void reset(){
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      
      map[i][j]=smap[i][j];
       visited[i][j]=0;
      
    }
  }
  while(!q.empty()){
    q.pop();
  }
}  
  
int sbfs(int x,int y){
  map[x][y]=0;
   int dr[4]={1,-1,0,0};
  int dc[4]={0,0,1,-1};     
  q.push(make_pair(sr,sc));
  visited[sr][sc]=1;
  int now_row;
  int now_col;
  while(!q.empty()){
     now_row = q.front().first;
    now_col = q.front().second;
  //  printf("%d %d map[][]: %d\n",now_row,now_col,map[now_row][now_col]);
    q.pop();
  
    if(now_row==x&&now_col==y){
      return map[x][y];
    }
  
    for(int i=0;i<4;i++){
      int nxt_row = now_row+dr[i];
      int nxt_col = now_col+dc[i];
      
      if(nxt_col>=0&&nxt_row>=0&&nxt_row<m&&nxt_col<n){
        if(visited[nxt_row][nxt_col]==0&&map[nxt_row][nxt_col]==0){
          q.push(make_pair(nxt_row,nxt_col));
          visited[nxt_row][nxt_col]=1;
          map[nxt_row][nxt_col]=map[now_row][now_col]+1;
        }
      }
    }
   
  }
  
  
      return -1;
    
} 


int ebfs(int x,int y){
  map[x][y]=0;
   int dr[4]={1,-1,0,0};
  int dc[4]={0,0,1,-1};     
  q.push(make_pair(er,ec));
  visited[er][ec]=1;
  int now_row;
  int now_col;
  while(!q.empty()){
     now_row = q.front().first;
    now_col = q.front().second;
    q.pop();
  
    if(now_row==x&&now_col==y){
      return map[x][y];
    }
  
    for(int i=0;i<4;i++){
      int nxt_row = now_row+dr[i];
      int nxt_col = now_col+dc[i];
      
      if(nxt_col>=0&&nxt_row>=0&&nxt_row<m&&nxt_col<n){
        if(visited[nxt_row][nxt_col]==0&&map[nxt_row][nxt_col]==0){
          q.push(make_pair(nxt_row,nxt_col));
          visited[nxt_row][nxt_col]=1;
          map[nxt_row][nxt_col]=map[now_row][now_col]+1;
        }
      }
    }
   
  }
    
      return -1;
  
} 

int main() {

  scanf("%d %d",&n,&m);

  sr=n-1;
  sc=0;
  er=0;
  ec=m-1;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&map[i][j]);
      smap[i][j]=map[i][j];
      if(map[i][j]==1){
        d1[idx]=i;
        d2[idx]=j;
        ++idx;
      }
    }
  }
  
  int min=10000;
  
  for(int i=0;i<idx;i++){
    
   // printf("%d %d\n",d1[i],d2[i]);
    reset();
    int sn = sbfs(d1[i],d2[i]);
    reset();
    int en = ebfs(d1[i],d2[i]);
   
    if(sn==-1||en==-1) continue;
    
    if(sn+en>0&&min>sn+en){
      min=sn+en;
    }
    
    
 }
  printf("%d",min);


  return 0;
}