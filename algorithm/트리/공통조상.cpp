#include <stdio.h>

int main() {
 
 int n,x,y;
 scanf("%d %d %d",&n,&x,&y);
 int color[1005]={0,};
 int parent[1005]={0,};
 
 for(int i=0;i<n;i++){
   int a,b;
   scanf("%d %d",&a,&b);
   parent[b]=a;
 }
 
 while(1){
   color[x]=1;
   if(x==0)break;
   x=parent[x];
 }
 
 while(1){
   if(color[y]==1){
     printf("%d",y);
     break;
   }
   color[y]=1;
   y=parent[y];
 }
  return 0;
}