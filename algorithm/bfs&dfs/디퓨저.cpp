#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct p{
  int x;
  int y;
};

int arr[11]={0,};
int size; 

int map[101][101]={0,};
int smap[101][101]={0,};
int n,m,k;

queue <p> q;
vector <p> d;

int checkDiffuse[12]={0,};
int min1 =999999;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int no=0;
void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      smap[i][j]=0;
    }
  }
}
int checkk(int a[]){
  int count=0;
  for(int i=0;i<size;i++){
    if(a[i]==1)++count;
  }
  if(count==k)return 1;
  else return 0;
}

int checkmin(){
  int max=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]==2)continue;
      if(smap[i][j]>max)max=smap[i][j];
    }
  }
  return max;
}

int full(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]==2) continue;
      if(map[i][j]==1) continue;
      if(smap[i][j]==0) return 0;
    }
  }
  return 1;
  
}
int BFS(){
  
  while(!q.empty()){
 
    int nx=q.front().x;
    int ny=q.front().y;

    q.pop();
    for(int i=0;i<4;i++){
      int xx=nx+dr[i];
      int yy=ny+dc[i];
      if(xx<0||yy<0||xx>=n||yy>=m)continue;
      if(smap[xx][yy]==0&&map[xx][yy]!=1){
        q.push({xx,yy});
        smap[xx][yy]=smap[nx][ny]+1;
      }
    }
   }
   
   return checkmin();
   
}
void getResult(int x){
  if(x==k){

    reset();
    for(int i=0;i<k;i++){
       int idx =arr[i];
        q.push({d[idx].x,d[idx].y});
         smap[d[idx].x][d[idx].y]=0;
    }
    int val=BFS();
    if(full()==1){
      no=1;
      if(min1>val) min1=val;
    }
    return ;
  }
  for(int i=0;i<size;i++){
    if(x==0){
       arr[x] = i;
      checkDiffuse[i] = 1;
      getResult(x+1);
      checkDiffuse[i] = 0;
    }
    else{
      if(arr[x-1] < i && checkDiffuse[i]==0){
       arr[x] = i;
        checkDiffuse[i] = 1;
        getResult(x+1);
        checkDiffuse[i] = 0;
      }
    }
  }
}

void init(){
  d.clear();
  min1 =999999;
  no=0;
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
      map[i][j]=0;
      smap[i][j]=0;
    }
  }
  
  size=0;
}
int main() {

   int ts;
   scanf("%d",&ts);
   for(int t=1;t<=ts;t++){
     init();
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==2){
              d.push_back({i,j});
            }
          }
        }
        
        size = d.size();
      
        getResult(0);
       
       int all=0;
       for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
           if(map[i][j]!=1)all=1;
         }
       }
       if(all==0){
         printf("#%d 0\n",t);
         continue;
       }
       if(no==0){
         printf("#%d -1\n",t);
        }else{
          printf("#%d %d\n",t,min1);
        }
   }
 

 
  return 0;
}