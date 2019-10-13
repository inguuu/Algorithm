#include <stdio.h>


int arr[20];
int n,m;
int k=0;
int print =0;
int map[20][20]={0,};
int smap[20][20]={0,};
int min =9999999;
void init(){
  min =9999999;
  k =0;
  print =0;
   for(int i=0;i<20;i++){
     arr[i]=0;
    for(int j=0;j<20;j++){
      map[i][j]=0;
      smap[i][j]=0;
      
    }
  }
 
}

void reset(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      map[i][j]=smap[i][j];
    }
  }
}
int check(){
  for(int j=0;j<m;j++){
     int cnt =1;
     int max=0;
    for(int i=0;i<n-1;i++){
       
      if(map[i][j]>map[i+1][j]){
        if(max<cnt)max=cnt;
        cnt=1;
        continue;
      }
      ++cnt;
      if(i==n-2){

        if(max<cnt)max=cnt;
      }
    }
    if(max<k)return 0;
  }
  return 1;
}

void DFS(int x){
  if(print==1)return;
  if(x==n){

   //k를 DBACD 다 다르게 해야한다. 당연히 m포문 다르게 
   //지금은 모든줄을 똑같은 D~S로 통일시켰지만 
   // 이제는 각각의 줄을 D~S 모든경우로 짜야한다.
       int count =0;
       reset();
      for(int i=0;i<n;i++){
      if(arr[i]==1){
        ++count;
        for(int j=0;j<m;j++){
          map[i][j]=k;
   
        }
      }
      if(check()==1){
        if(min>count) min=count;
        return;
      }
    }
  

    return;
  }
  
  for(int i=0;i<2;i++){
      arr[x]=i;
      DFS(x+1);
  }
  
}

int main() {
 int ts;
 scanf("%d",&ts);
 for(int t=0;t<ts;t++){

   init();
 scanf("%d %d %d",&n,&m,&k);
 for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
     char c;
     scanf(" %c",&c);
     if(c=='F')map[i][j]=0;
     if(c=='D')map[i][j]=1;
     if(c=='C')map[i][j]=2;
     if(c=='B')map[i][j]=3;
     if(c=='A')map[i][j]=4;
     if(c=='S')map[i][j]=5;
     smap[i][j]=map[i][j];
   }
 }
 
  
 
 printf("#%d ",t+1);
  DFS(0);
  printf("%d",min);
  printf("\n");
  
  // for(int i=0;i<n;i++){
  // for(int j=0;j<m;j++){
  //   printf("%d ",map[i][j]); 
  // }
  // printf("\n");
  // }
 }
 
  return 0;
}