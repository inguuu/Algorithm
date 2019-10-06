#include <stdio.h>
#include <vector>

using namespace std;

vector <int> g[101];
int visited[101];
int count =0;

void getResult(int x){
  visited[x]=1;
  for(int i=0;i<g[x].size();i++){
    int w=g[x][i];
    if(visited[w]==0){
      getResult(w);
    }
  }
}
int main() {

  
  int n,m;
  
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d",&a);
     scanf("%d",&b);
     g[a].push_back(b);
     g[b].push_back(a);
  }
  
  for(int i=1;i<=n;i++){
      if(visited[i]==0){
      
        visited[i]=1;
        getResult(i);
        ++count;
      }
  }
printf("%d",count);
  

  return 0;
}