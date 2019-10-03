#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[1000][1000]={0,};
int visited[1000]={0,};
vector <int> g[1000];
queue <int> q;
 int n,m;

void DFS(int x){
 
 printf("%d ",x);
 visited[x]=1;

 sort(g[x].begin(),g[x].end());
 for(int i=0;i<g[x].size();i++){
    int w =g[x][i];
    if(visited[w]==0){
       DFS(w);
    }
 }

 
} 
void BFS(int x){
  q.push(x);
  visited[x]=1;
  
  while(!q.empty()){
    
    int now = q.front();
    printf("%d ", now);
    q.pop();

    for(int i=1;i<n;i++){
      if(visited[i]==0&&map[now][i]==1){
        q.push(i);
        visited[i]=1;
      }
    }
    
    
  }
  
  
}
int main() {
 
 

 scanf("%d %d",&n,&m);
 for(int i=0;i<m;i++){
   int a,b;
   scanf("%d %d",&a,&b);
   map[a][b]=1;
   map[b][a]=1;
   g[a].push_back(b);
   g[b].push_back(a);
 }
 
 DFS(0);

 for(int i=0;i<n;i++){
   visited[i]=0;
 }
 printf("\n");
 
   BFS(0);
  return 0;
}