#include <stdio.h>
#include <queue>

using namespace std;

queue <int> q;
int map[1001][1001]={0,};
int check[1001]={0,};
int flag=1;

int n,m;

void BFS(){
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(int i=1;i<=n;i++){
      if(map[x][i]==1&&check[i]==check[x]){
        flag=0;
        return;
      }
      
      if(map[x][i]==1&&check[i]==0){
        q.push(i);
        int yy;
        if(check[x]==1)yy=2;
        else yy=1;
        check[i]=yy;
       
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
  
}
 q.push(1);
 check[1]=1;
 BFS();

 if(flag==1)printf("Yes");
 else printf("No");
  

  return 0;
}