#include <stdio.h>
#include <queue>

using namespace std;


int map[101][101]={0,};
int smap[101][101]={0,};
int r,c,s;
int dr[4]={0,0,-1,1};
int dc[4]={1,-1,0,0,};

struct p{
  int x;
  int y;
};

int cx1;
int cy1;
int cd1=0;
int cx2;
int cy2;
int cd2=0;

queue <p> q;
void check(){
   for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(map[i][j]>4){
        q.push({i,j});
      }
    }
  }
  
}

void BFS(){
  while(!q.empty()){
    int nx= q.front().x;
    int ny= q.front().y;
    
    q.pop();
    int val = map[nx][ny]/5;
    int count =0;
    
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx<0||yy<0||xx>=r||yy>=c)continue;
      if(map[xx][yy]==-1)continue;
      ++count;
      smap[xx][yy]+=val;
    }
    if(count>0){
       smap[nx][ny] = smap[nx][ny]- val*count;
    }
   
  }
  
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      map[i][j]=smap[i][j];
    }
  }
  
}

int checkcount(){
  int count =0;
   for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(map[i][j]==-1)continue;
      count+=map[i][j];
    }
  }
  
  return count;
}

int dc1[4]={-1,0,1,0};
int dr1[4]={0,-1,0,1};

int dc2[4]={-1,0,1,0};
int dr2[4]={0,1,0,-1};


void clean1(){
  
  int tmp=0;
  int save=0;
  int nx=cx1;
  int ny=cy1;
  cd1=0;
  
  while(1){
    
    
    int xx =nx+dr1[cd1];
    int yy =ny+dc1[cd1];
    if(xx<0||yy<0||xx>=r||yy>=c){

    ++cd1;
     xx =nx+dr1[cd1];
     yy =ny+dc1[cd1];
   }
 
if(map[xx][yy]==-1)break;
   tmp=map[xx][yy];
   map[xx][yy]=save;
   save=tmp;
   
   nx=xx;
   ny=yy;
  }

  
}

void clean2(){
  
  int tmp=0;
  int save=0;
  int nx=cx2;
  int ny=cy2;
  cd2=0;
  while(1){
    
    int xx =nx+dr2[cd2];
    int yy =ny+dc2[cd2];
    if(xx<0||yy<0||xx>=r||yy>=c){

    ++cd2;
     xx =nx+dr2[cd2];
     yy =ny+dc2[cd2];
   }
 
 if(map[xx][yy]==-1)break;
   tmp=map[xx][yy];
   map[xx][yy]=save;
   save=tmp;
   
   nx=xx;
   ny=yy;
  }

  
}

int main() {
 int ts;
 scanf("%d",&ts);
 
 for(int t=1;t<=ts;t++){
  scanf("%d %d %d",&r,&c,&s);

 int cc=0;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&map[i][j]);
      smap[i][j]=map[i][j];
      if(cc==0&&map[i][j]==-1){
        cx1=i;
        cy1=j;
        cc=1;
      }
      if(cc==1&&map[i][j]==-1){
        cx2=i;
        cy2=j;
      }
    }
  }
  
  
  for(int i=0;i<s;i++){
    
  check();
  BFS();
   clean1();
   clean2();
   for(int i=0;i<r;i++){
     for(int j=0;j<c;j++){
       smap[i][j]=map[i][j];
     }
   }
     
  }
  
  printf("#%d %d\n",t,checkcount());
 }
 

  return 0;
}