#include <stdio.h>

int result[16];
int n;
int max=0;
int score[15][3]={0,};
void getResult(int x,int pre){
  if(x==n){
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=score[i][result[i]];

    }
    if(sum>max)max=sum;

  }else{
    for(int i=0;i<3;i++){
      if(pre!=i){
        result[x]=i;
        getResult(x+1,i);
      }
      
    }
    
  }
  
  
}

int main() {
 
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&score[i][j]);
 
    }

  }
 getResult(0,3);
 printf("%d",max);
  return 0;
}