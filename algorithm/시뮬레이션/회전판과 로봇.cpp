#include <stdio.h>

int go(int e,int f,int idx, int k){
  
  int result=idx;

  if(e==2){
    for(int i=0;i<f;i++){
      if(result+1>k-1){
        
        result=0;
      }else{
       
        result=result+1;
      }
    }
    
      return result;
  }else{
    for(int i=0;i<f;i++){
      if(result-1<0){
        result=k-1;
      }else{
        result=result-1;
      }
    }     
      return result;
  }
}


int main() {

 
 int n,m,x,y;
 int map[500][500]={0,};
 int k=0;
 int c[9];
 int d[101];
 int e[101];
 int f[101];
 
 int tc;
 scanf("%d",&tc);
 
 for(int t=0;t<tc;t++){
    scanf("%d %d %d %d",&n,&m,&x,&y);
    int score =0;
 for(int i=1;i<=m;i++){
   for(int j=1;j<=n;j++){
    scanf("%d", &map[i][j]); 
   }
 }
 
 score+=map[y][x];
 map[y][x]=0;
 int ni=y;
 int nj=x;
 

 scanf("%d",&k);
 for(int i=0;i<k;i++){
   scanf("%d",&c[i]);
 }
 int idx=0;
 
 int l;
 scanf("%d",&l);
 
 for(int i=0;i<l;i++){
   scanf(" %c",&d[i]);
    scanf("%d",&e[i]);
     scanf("%d",&f[i]);
  
   
   int g= go(e[i],f[i],idx,k);
   idx=g;
   int gg=c[g];
  
   if(d[i]=='S'){
    for(int j=0;j<gg;j++){
      if(map[ni+1][nj]==-1||ni+1>m) break;
      ++ni;
      score=score+map[ni][nj];
      map[ni][nj]=0;
     
    }
   }
    
    if(d[i]=='N'){
    for(int j=0;j<gg;j++){
      if(map[ni-1][nj]==-1||ni-1<1) break;
      --ni;
      score=score+map[ni][nj];
      map[ni][nj]=0;
      
     }
    }
    
     if(d[i]=='W'){
    for(int j=0;j<gg;j++){
      if(map[ni][nj-1]==-1||nj-1<1) break;
      --nj;
      score=score+map[ni][nj];
      map[ni][nj]=0;
      
     }
    }
    
      if(d[i]=='E'){
    for(int j=0;j<gg;j++){
      if(map[ni][nj+1]==-1||nj+1>n) break;
      ++nj;
      score=score+map[ni][nj];
      map[ni][nj]=0;
      
     }
    }
    
     
  }
  printf("#%d %d %d %d\n",t+1,score,nj,ni);
 }
 

  return 0;
}