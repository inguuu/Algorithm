#include <stdio.h>

int main() {

  int r,c,k;
  
  scanf("%d",&r);
  scanf("%d",&c);
  scanf("%d",&k);
  int map[1001][1001]={0,};
  int dr[4]={1,0,-1,0};
  int dc[4]={0,1,0,-1};
  
  int now=0;
  int count=1;
  int i=1;
  int j=1;
  map[1][1]=1;
  
  if(k==1){
    printf("1 1");
    return 0;
  }else if(k>r*c){
    printf("0");
    return 0;
  }
  
  while(count<r*c){
    
     ++count;
    if(i+dr[now]>=1&&j+dc[now]>=1&&i+dr[now]<=c&&j+dc[now]<=r&&map[i+dr[now]][j+dc[now]]==0){
      i=i+dr[now];
      j=j+dc[now];
      map[i][j]=count;
    }else{
      if(now==3){
        now=0;
      }else{
         ++now;
      }
      i=i+dr[now];
      j=j+dc[now];
      map[i][j]=count;
    }
    
    if(count==k){
      printf("%d %d",j,i);
      break;
    }
   
  }
  

  return 0;
}