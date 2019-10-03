#include <stdio.h>
#include <vector>

using namespace std;
int n,m;
vector <int> g[10001];
int check[10001]={0,};

int print =1;

void DFS(int x,int color){
  check[x]=color;
  
  if(color==1)color=2;
  else color=1;
  for(int i=0;i<g[x].size();i++){
    int w=g[x][i];
    if(check[x]==check[w]){
      print=0;
      return;
    }
    if(check[w]==0){
      DFS(w,color);
    }
  }
}

int main() {
  
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  DFS(0,1);
  if(print==0)printf("NO");
  else printf("YES");
  

  return 0;
}