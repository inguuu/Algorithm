#include <stdio.h>
#include <queue>;
using namespace std;

int n;
int now=1;
struct p{
  int x;
  int cnt;
};
int check[100000]={0,};
p make_p(int a,int b){
  p p1;
  p1.x=a;
  p1.cnt=b;
  return p1;
}
void BFS(){
  queue <int> q;
  
  q.push(now);
  check[1]=1;
  int cc=0;
  while(!q.empty()){
    int nx=q.front();
    

    q.pop();

    if(nx==n) return;
    if(2*nx<=99999){
     
      if(check[nx*2]==0){
        q.push(2*nx);
        check[2*nx]=check[nx]+1;
      }
     
    }
    if(n/3>0){
       if(check[nx/3]==0){
           q.push(nx/3);
         check[nx/3]=check[nx]+1;
      }
    }

  }
}

int main() {

  scanf("%d",&n);
  BFS();

  printf("%d\n",check[n]-1);

  return 0;
}