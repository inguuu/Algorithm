#include <stdio.h>

int main() {

  int map[11][11]={0, };
  int n=0;
  scanf("%d",&n);
  
  for(int k=1;k<=n;k++){
    for(int i=1;i<=10;i++){
      for(int j=1;j<=10;j++){
         if(k==i||k==j){
           if(map[i][j]==0){
             map[i][j]=1;
           }else{
             map[i][j]=0;
           }
         }
     }
    }
  }
  
 for(int i=1;i<=10;i++){
    for(int j=1;j<=10;j++){
       printf("%d ",map[i][j]);
   }
   printf("\n");
  }

  return 0;
}