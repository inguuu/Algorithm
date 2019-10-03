#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
vector <int> v[10001];
 int check[10001]={0,};
 int n,m;
 int color=1;
 int print=1;
 
 struct p{
   int x;
   int color;
 };
 
void BFS(int x){
  queue <p> q;
  q.push({x,1});
  check[x]=1;
  while(!q.empty()){
     int xx = q.front().x;
     int ncolor =q.front().color;
     q.pop();
    
     if(ncolor==1)ncolor=2;
     else ncolor=1;
     
     for(int i=0;i<v[xx].size();i++){
       int w=v[xx][i];
        
       if(check[xx]==check[w]){
         print=0;
         return;
       }
       if(check[w]==0){
         q.push({w,ncolor});
         check[w]=ncolor;
  
         
       }
       
     }
     
     
  }
  
} 
 
int main() {
 
 scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    v[n1].push_back(n2);
    v[n2].push_back(n1);
  }
  BFS(0);
  if(print==0)printf("NO");
  else printf("YES");
  return 0;
}