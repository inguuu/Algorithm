#include <stdio.h>
#include <vector>

using namespace std;

vector <int> g[100];
int visited[100];

int count =-1;


void DFS(int x){

  visited[x]=1;
  ++count;
  for(int i=0;i<g[x].size();i++){
    int w=g[x][i];
    if(visited[w]==0){
      DFS(w);
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
  DFS(1);
  
  printf("%d",count);

  return 0;
}