#include <stdio.h>
//T[i]: 정점 i에 도달하는데 걸리는 최단거리
// for i = 0-n

// (1) T[i] 중 최솟값을 정한다. 단, 지금까지 최솟값으로 뽑히지 않았던 값들 중/
// (2) index로 부터 뻗어나간다. T[index] +cost

#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector <int> g[MAX];
vector <int> cost[MAX];

int check[100];//i라는 노드가 최단거리가 확정 됬는지 안됬는지
int n,m,s,e;
int Table[100];
int main() {
  scanf("%d %d %d %d",&n,&m,&s,&e);
  
  for(int i=0;i<m;i++){
    int a,b,c;
    
    scanf("%d %d %d",&a,&b,&c);
    
    //a -- (c) -- b
    
    g[a].push_back(b);
    g[b].push_back(a);
    
    cost[a].push_back(c);
    cost[b].push_back(c);
    
  }
  
  for(int i=0;i<n;i++)Table[i]=913912;
  Table[s]=0;

 for(int i=0;i<n;i++){
   //(1)최소값을 구한다. 단 지금까지 최단거리로 확정되지 않았던 정점에 대해서
   //(2)그 최솟값을 갖는 노드로부터 뻗어나간다.
   
   int min =9999999;
   int midx=0;
    for(int j=0;j<n;j++){
      if(check[j]==0&&min>Table[j]){
        min=Table[j];
        midx=j;
      }
    }
    
    check[midx] = 1;
    
    for(int j=0;j<g[midx].size();j++){
      int node2 = g[midx][j];
      int cost2 = cost[midx][j];
    
      //midx---(cost2) --node2
      
      if(Table[node2]>Table[midx]+cost2){
        Table[node2] = Table[midx] + cost2;
      }
    }
 }
 printf("%d\n",Table[e]);
  return 0;
}