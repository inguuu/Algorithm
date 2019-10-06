#include <stdio.h>
#include <queue>
using namespace std;
int n;
int result[10000]={0,};
int ridx=0;
int max1=0;
int map[101][101]={0,};
int smap[101][101]={0,};
struct p{
  int x;
  int y;
};

p make_p(int a,int b){
  p p1;
  p1.x=a;
  p1.y=b;
  return p1;
}

void getRain(int r){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(map[i][j]<=r)map[i][j]=0;
    }
  }
}

void reset(){
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      map[i][j]=smap[i][j];
    }
  }
}

void getResult(int x,int y){
  
  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0};
  
  queue <p> q;
  q.push(make_p(x,y));
  map[x][y]=0;
  while(!q.empty()){
    int nx=q.front().x;
    int ny=q.front().y;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx<0||yy<0||xx>=n||yy>=n)continue;
      
      if(map[xx][yy]>0){
        map[xx][yy]=0;
        getResult(xx,yy);
      }
    }
    
    
  }
  
}

int main() {

 scanf("%d",&n);
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&map[i][j]);
      if(max1<map[i][j])max1=map[i][j];
      smap[i][j]=map[i][j];
    }
  }
 
 for(int i=1;i<=max1;i++){
   reset();
   getRain(i);
   
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      
      if(map[i][j]!=0){
        getResult(i,j);
        ++result[ridx];
        
      }
    }
  }
  ++ridx;
 }
 
 int ans=0;
 for(int i=0;i<ridx;i++){
   if(ans<result[i])ans=result[i];
  
 }
  printf("%d",ans);
  return 0;
}