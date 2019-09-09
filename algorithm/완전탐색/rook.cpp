#include <stdio.h>

int main() {

  int map[10][10];
  int kr;
  int kc;
  int lr[1]={-1, };
  int lc[1]={-1, };
  int br[29]={-1, };
  int bc[29]={-1, };
  
  int lcount=0;
  int bcount=0;
   for(int i=0;i<8;i++){
     for(int j=0;j<8;j++){
       
       scanf("%d",&map[i][j]);
       if(map[i][j]==1){
         kr=i;
         kc=j;
       }
       if(map[i][j]==2){
         lr[lcount]=i;
         lc[lcount]=j;
         ++lcount;
       }
       if(map[i][j]==3){
         br[bcount]=i;
         bc[bcount]=j;
         ++bcount;
       }
     }
   }
   
  int result =0;
   int min;
   int j;
   for(int i=0;i<2;i++){
     if(kr==lr[i]){
      if(kc<lc[i]){
        for(j=kc+1;j<lc[i];j++){
          if(map[kr][j]==3){
            break;
          }
        }
         if(j==lc[i]){
          result=1;
        }
      }   
      if(kc>lc[i]){
        for(j=lc[i]+1;j<kc;j++){
          if(map[kr][j]==3){
            break;
          }
        }
         if(j==kc){
          result=1;
        }
      }   
     }
     
     
     if(kc==lc[i]){
       if(kr<lr[i]){
        for(j=kr+1;j<lr[i];j++){
          if(map[j][kc]==3){
            break;
          }
        }
         if(j==lr[i]){
          result=1;
        }
      }   
      if(kr>lr[i]){
        for(j=lr[i]+1;j<kr;j++){
          if(map[j][kc]==3){
            break;
          }
        }
         if(j==kr){
          result=1;
        }
      }   
     }
     
     
   }
   printf("%d",result);
  return 0;
}