#include <stdio.h>
#include <vector>

using namespace std;

int pos=0;
vector <int> g[101];

int visited[100]={0,};
int cost[11]={0,};
int arr[11]={0,};

int min1 =9999999;
int n;

void reset(){
  for(int i=0;i<11;i++){
    visited[i]=0;
  }
  
}

int abs(int num1,int num2){
  if(num1-num2>0)return num1-num2;
  else return num2-num1;
}

void DFS(int x,int a){
  
  visited[x]=1;
  for(int i=0;i<g[x].size();i++){
    int w = g[x][i];
    if(visited[w]==0&&arr[w]==a){
      DFS(w,a);
    }
  }
  
}


int full(){
  for(int i=0;i<n;i++){
    if(visited[i]==0)return 0;
  }
  return 1;
}

void getResult(int x){
  
  if(x==n){
    reset();
    
    for(int i=0;i<n;i++){
      if(arr[i]==0){
          DFS(i,0);
          break;
      }
    }
     for(int i=0;i<n;i++){
      if(arr[i]==1){
          DFS(i,1);
          break;
      }
    }
    
    if(full()==1){
      pos=1;
      int suma, sumb;
      suma=0;
      sumb=0;
      for(int i=0;i<n;i++){
        if(arr[i]==0){
          suma+=cost[i];
        }
        if(arr[i]==1){
          sumb+=cost[i];
        }
      }
      int val = abs(suma,sumb);
      if(min1>val)min1=val;
    }
   return ;
  }
  
  for(int i=0;i<2;i++){
    arr[x]=i;
    getResult(x+1);
  }
}

void init(){
  min1=9999999;
  pos=0;
  for(int i=0;i<100;i++){
    visited[i]=0;
  }
  for(int i=0;i<11;i++){
    arr[i]=0;
    cost[i]=0;
  }
  for(int i=0;i<100;i++){
    g[i].clear();
  }
  
}


int main() {
  int ts;
scanf("%d",&ts);
for(int t=1;t<=ts;t++){
  init();
    scanf("%d",&n);
   for(int i=0;i<n;i++){
     int q,m;
     scanf("%d %d",&q,&m);
     cost[i]=q;
     for(int j=0;j<m;j++){
       char c;
       scanf(" %c",&c);
       int cnum= c-'A';
       g[i].push_back(cnum);
     }
     
   }
    
    getResult(0);
    
  if(pos == 0)printf("#%d -1\n",t);
  else printf("#%d %d\n",t,min1);
}
  return 0;
}

//2의 n승 시간복잡도 