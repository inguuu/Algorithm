#include <stdio.h>
#include <queue>

using namespace std;

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
int n;
int map1[101][101]={0,};
int map2[101][101]={0,};
int cnt1=0;
int cnt2=0;
void getResult(int x,int y,int color, int map[101][101]){
  map[x][y]=0;
  queue <p> q;
  q.push(make_p(x,y));
  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0,};
  while(!q.empty()){
    int nx=q.front().x;
    int ny=q.front().y;
    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx>n||yy>n||xx<0||yy<0)continue;
      if(map[xx][yy]==color){
        map[xx][yy]=0;
        q.push(make_p(xx,yy));
      }
    }
    
  }
  
  
}

int main() {

 scanf("%d",&n);
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     char c;
     scanf(" %c",&c);
     if(c=='R'){
     map1[i][j]=1;
     map2[i][j]=1;
     }else if(c=='G'){
       map1[i][j]=2;
     map2[i][j]=1;
     }else{
       map1[i][j]=3;
     map2[i][j]=2;
     }
     
   }
   
 }
 
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     if(map1[i][j]!=0){
       getResult(i,j,map1[i][j],map1);
       ++cnt1;
     }
   }
 }
  
   for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     if(map2[i][j]!=0){
       getResult(i,j,map2[i][j],map2);
       ++cnt2;
     }
   }
 }
  printf("%d %d",cnt1,cnt2);

  return 0;
}