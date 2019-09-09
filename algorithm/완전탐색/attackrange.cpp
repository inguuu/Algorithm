#include <stdio.h>

int main() {

 int n;
 int x,y,r;
 int map[100][100];
 
 scanf("%d",&n);
 scanf("%d",&x);
  scanf("%d",&y);
  scanf("%d",&r);

  for(int i=0;i<n;i++){
      int val=0;
        if(x-i-1>=0){
          val=x-i-1;
        }else{
          val=-x+i+1;
        }
        for(int j=0;j<n;j++){
          map[i][j]=val;
         int xval=0;
          if(y-j-1>=0){
            xval=y-j-1;
          }else{
            xval=-y+j+1;
          }
           map[i][j]+=xval;
      }
        
  }
  
 
    
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
         if(map[i][j]<=r){
           if(x-1==i&&y-1==j){
               printf("x ");
           }else{
               printf("%d ",map[i][j]);
           }
      
         }else if(map[i][j]>r){
            printf("0 ");
         }
      }
      printf("\n");
    }
  return 0;
}