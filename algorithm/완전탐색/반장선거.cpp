#include <stdio.h>

int main() {

  int student[1002][6];
  int val[1002][1002]={0,};
  int count[1002]={0,};
  int n;
  
  scanf("%d",&n);
  
  for(int i=1;i<n+1;i++){
    for(int j=1;j<6;j++){
      scanf("%d",&student[i][j]);
    }
  }
 

 for(int j=1;j<6;j++){
    for(int i=1;i<n+1;i++){
       for(int k=1;k<n-i+1;k++){
       if(student[i][j]==student[i+k][j]){
         if(val[i][i+k]==0){
             ++val[i][i+k];
             ++val[i+k][i];
             ++count[i];
             ++count[i+k];
         }
       }
     }
    }
  }
  
  
  // for(int i=1;i<6;i++){
    
  //   for(int j=1;j<n;j++){
  //     for(int k=1;k<n-j+1;k++){
  //       if(student[i][j]==student[i][j+k]){
  //         ++count[j];
  //         ++count[j+k];
  //         printf("%d %d %d\n",i,j,j+k);
  //         printf("%d %d\n",student[i][j],student[i][j+k]);
  //       }
  //     }
  //   }
    
  // }
  
  int max=0;
  int idx;
  for(int i=1;i<n+1;i++){
   
      if(max<count[i]){
        idx=i;
        max=count[i];
      }
    
  }
  
  printf("%d",idx);
  //printf("%d",max);
  return 0;
}