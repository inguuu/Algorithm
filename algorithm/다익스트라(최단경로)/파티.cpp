#include <stdio.h>
#include <vector>

using namespace std;

vector<int> g1[1001];
vector<int> g2[1001];
vector <int> cost1[1001];
vector <int> cost2[1001];
int check[1001]={0,};
int T[1001]={0,};

int n,m,k;

void reset(){
  for(int i=1;i<=n;i++){
    check[i]=0;
    T[i]=99998;
  }
}

int getResult(int s, vector <int>g[],vector<int> cost[]){
  
  
  reset();
  T[s]=0;
 for(int i=0;i<n;i++){
    
    int min=99999;
    int midx;
   
    for(int j=1;j<=n;j++){
      if(check[j]==0&&min>T[j]){
        
        min=T[j];
        midx=j;
      
      }
    }
    check[midx]=1;
    
    for(int k=0;k<g[midx].size();k++){
  
      int w= g[midx][k];
      int costw = cost[midx][k];
      if(T[w]>T[midx]+costw)T[w]=T[midx]+costw;
    }
    
    
  }
  
}

int main() {

 int sum=0;
 scanf("%d %d %d",&n,&m,&k);
 
 for(int i=0;i<m;i++){
   int a,b,c;
   scanf("%d %d %d",&a,&b,&c);
   g1[a].push_back(b);
    g2[b].push_back(a);
   cost1[a].push_back(c);
   cost2[b].push_back(c);
 }
 

getResult(k,g1,cost1);
for(int i=1;i<=n;i++){
  sum+=T[i];
}
getResult(k,g2,cost2);
for(int i=1;i<=n;i++){
  sum+=T[i];
}

 
 printf("%d",sum);
  return 0;
}