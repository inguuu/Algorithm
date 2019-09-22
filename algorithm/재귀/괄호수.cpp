#include <stdio.h>
int n;
char result[20];

void getResult(int sum,int x,int y,int idx){
  if(x==n/2&&y==n/2){
     printf("%s",result);
      printf("\n");
  }
  else{
    if(sum==0){
      result[idx]='(';
      getResult(sum+1,x+1,y,idx+1);
    }else if(x==n/2){
      result[idx]=')';
      getResult(sum-1,x,y+1,idx+1);
    }else if(x<n/2&&y<n/2){
      result[idx]='(';
      getResult(sum+1,x+1,y,idx+1);
      result[idx]=')';
      getResult(sum-1,x,y+1,idx+1);
    }
    
  }
}

int main() {
 scanf("%d",&n);
 getResult(0,0,0,0);
  

  return 0;
}