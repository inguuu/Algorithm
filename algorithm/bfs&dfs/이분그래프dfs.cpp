#include <stdio.h>
#include <vector>

using namespace std;

vector <int> g[100002];
int check[100002]={0,};
int flag=1;

void DFS(int x,int y){
  check[x]=y;
  for(int i=0;i<g[x].size();i++){
    if(check[g[x][i]]==y){
      flag=0;
      return ;
    }
    
    int yy;
    if(y==1)yy=2;
    else yy=1;
    
    if(check[g[x][i]]==0){
      int xx;
      xx=g[x][i];
      DFS(xx,yy);
    }
  }
  
}

int main() {
 
 int n,m;
 scanf("%d %d",&n,&m);
 
 for(int i=0;i<m;i++){
   int a,b;
   scanf("%d %d",&a,&b);
   g[a].push_back(b);
   g[b].push_back(a);
   
 }
 
 DFS(1,1);
 if(flag==0){
   printf("No");
 }else{
   printf("Yes");
 }
 
  return 0;
}