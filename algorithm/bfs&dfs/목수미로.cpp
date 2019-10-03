#include <stdio.h>
#include <queue>
#include<algorithm>
using namespace std;
int map[1001][1001]={0,};
int cost1[1001][1001]={0,};
int cost2[1001][1001]={0,};
int visited[1001][1001]={0,};
int n,m;
struct p{
  int x;
  int y;
};

void getResult(int y,int x, int c[1001][1001]){
  int dr[4]={0,1,0,-1};
  int dc[4]={1,0,-1,0};
  
  queue<p> q;
  p p1;
  p1.x=x;
  p1.y=y;
  
  q.push(p1);
  while(!q.empty()){
    int now_x = q.front().x;
    int now_y = q.front().y;
    q.pop();
    visited[now_y][now_x]=1;
    for(int i=0;i<4;i++){
      int nxt_x =now_x+dr[i];
      int nxt_y =now_y+dc[i];
      
      if(nxt_x>=0&&nxt_y>=0&&nxt_y<n&&nxt_x<m){
        if(visited[nxt_y][nxt_x]==0){
          p1.x=nxt_x;
          p1.y=nxt_y;
          visited[nxt_y][nxt_x]=1;
          c[nxt_y][nxt_x]=c[now_y][now_x]+1;
          if(map[nxt_y][nxt_x]==0){
            q.push(p1);
          }
        }
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
 getResult(n-1,0,cost1);

 for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
     visited[i][j]=0;
   }
 }
  getResult(0,m-1,cost2);


 int min = 1000*1000;
 for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
     if(map[i][j]==1&&cost1[i][j]>0&&cost2[i][j]>0){
       int sum=cost1[i][j]+cost2[i][j];
       if(sum<min)min=sum;
     }
   }
 }
 printf("%d",min);
  
}