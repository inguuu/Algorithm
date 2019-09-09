#include <stdio.h>

int main() {

int map[5][5];
int a[25];
int count=0;

    
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
       scanf("%d",&map[i][j]);
    }
  }
  
  
   for(int i=0;i<25;i++){
     scanf("%d",&a[i]);
   }
   

   //게임시작
   
  for(int k=0;k<25;k++){
    //printf("======= %d =====\n",k);
     int bingo =0;
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         if(map[i][j]==a[k]){
           map[i][j]=0;
         }
      }
    }

  
    
    //가로빙고
  
    for(int i=0;i<5;i++){
        count=0;
       for(int j=0;j<5;j++){
        if(map[i][j]==0){
          ++count;
        }
      }
      if(count==5){
      // printf("가로빙고\n");
        ++bingo;
      }
    }
    
     //세로빙고
   
    for(int j=0;j<5;j++){
      count=0;
       for(int i=0;i<5;i++){
         if(map[i][j]==0){
          ++count;
        }
      }
      if(count==5){
     // printf("세로빙고\n");
        ++bingo;
      }
    }
    
     //대각빙고
    count=0;
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
        if(i==j){
          if(map[i][j]==0){
              ++count;
          }
        }
      }
    }
    if(count==5){
      //  printf("대각빙고\n");
        ++bingo;
      }
    
     //대각빙고2
    count=0;
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
         if(i+j==4){
           if(map[i][j]==0){
                 ++count; 
           }
        }
      }
    }
     if(count==5){
        ++bingo;
      //  printf("대각빙고2\n");
      }
    
    if(bingo==3){
      printf("%d",k+1);
      break;
    }
    
   }
   
  return 0;
}