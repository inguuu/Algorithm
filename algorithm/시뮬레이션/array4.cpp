#include <stdio.h>

int n;

int main() {
  int num=2;
  scanf("%d",&n);
  int map[31][31];
  map[1][1]=1;
  
  for(int k=2;k<=n;k++){
    if(k%2==1){
        for(int j=1;j<=k;j++){
          map[k][j]=num;
          ++num;
        }
        
        for(int i=k-1;i>=1;i--){
          map[i][k]=num;
          ++num;
        }
        
      }else{
       
       for(int i=1;i<=k;i++){
        map[i][k]=num;
        ++num;
      }
      
      for(int j=k-1;j>=1;j--){
        map[k][j]=num;
        ++num;
      }
    
    }
    
  }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      printf("%d ",map[i][j]);
    }
    printf("\n");
  }

  return 0;
}