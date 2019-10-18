#include <stdio.h>
#include <queue>

using namespace std;


struct p{
  int x;
  int y;
};
int map[52][52]={0,};
int smap[52][52]={0,};
int cmap[52][52]={0,};
int visited[52][52]={0,};
int result[11]={0,};

int n,m;
int k;
queue <p> q[11];

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

int full(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]==0)return 0;
    }
  }
  return 1;
}

void BFS(int a){

  while(!q[a].empty()){
    int nx=q[a].front().x;
    int ny=q[a].front().y;

    q[a].pop();
    
    for(int i=0;i<4;i++){
      int xx = nx+dr[i];
      int yy = ny+dc[i];
      if(xx<0||yy<0||xx>=n||yy>=m)continue;
      if(map[xx][yy]==0){
        map[xx][yy]=map[nx][ny];
        cmap[xx][yy]=0;
        smap[xx][yy]=1;
      }
      
      if(map[xx][yy]>0&&visited[xx][yy]==0){
       
        if(map[xx][yy]<map[nx][ny]){
   
          map[xx][yy]=map[nx][ny];
          cmap[xx][yy]=0;
          smap[xx][yy]=1;
        }
      }
    }
  }
}

void visitedc(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]>0)visited[i][j]=1;
    }
  }
}

void grow(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]>0)++cmap[i][j];
      if(cmap[i][j]>=map[i][j]&&map[i][j]>0){
        if(smap[i][j]==k)continue;
        ++smap[i][j];
      }
    }
  }
}

void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      map[i][j]=0;
      smap[i][j]=0;
      cmap[i][j]=0;
      visited[i][j]=0;
    }
  }
  for(int i=0;i<11;i++){
    q[i].empty();
    result[i]=0;
  }
}

int main() {
 int ts;
 scanf("%d",&ts);
 
 for(int t=1;t<=ts;t++){
    reset();
    
     scanf("%d %d",&n,&m);
     k=0;
     for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
         char c;
         scanf(" %c",&c);
         if(c!='0'){
           int num = c-'A'+1;
           if(num>k)k=num;
           map[i][j]=num;
           cmap[i][j]=0;
           smap[i][j]=1;
         }
       }
     }
     
      
    while(1){
      
     if(full()==1)break;
       
     grow();
     for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
         if(map[i][j]==0)continue;
         if(map[i][j]>cmap[i][j])continue;
         int tall;
         tall = smap[i][j];
         q[tall].push({i,j});
       }
     }
   
     for(int i=10;i>0;i--){
       BFS(i);
       visitedc();
     }
    }
  
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int idx =map[i][j];
        ++result[idx];
      }
    }
    
    
    printf("#%d ",t);
    for(int i=1;i<11;i++){
      printf("%d ",result[i]);
    }
    printf("\n");
    
 }
 


  

  return 0;
}