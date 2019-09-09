#include <stdio.h>

int main() {

  int c,r;
  scanf("%d",&c);
  scanf("%d",&r);
  
  int map[21][21];
  int smap[21][21];
  int max =0;
  int idx=-1;
  
   for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&map[i][j]);
      smap[i][j]=map[i][j];
    }
  }


  for(int j=0;j<c;j++){
    
    //초기화
    for(int n=0;n<r;n++){
      for(int m=0;m<c;m++){
            map[n][m]=smap[n][m];
      }
    }
    int jc=0;
    
    //한줄씩 칸수세기 
    for(int i=0;i<r;i++){
    if(map[i][j]==1){
      ++jc;
      }
    }

    //넣을수 있는지 확인 가능하면 넣기
    if(jc+4<=r){
    // printf("%d %d %d\n",j, jc, r );
      for(int i=c;i>c-(4+jc);i--){
        map[i][j]=1;
      }
     //전체 읽어서 가로가 다 1인경우 
     
     int answer=0;
     for(int n=0;n<r;n++){
       int count =0;
      for(int m=0;m<c;m++){
           if(map[n][m]==1){
             ++count;
           }
      }
      if(count==c){
        ++answer;
      }
     }
     if(answer>max){
       max=answer;
       idx=j;
     }
    }
    else{
      continue;
    }
    
  }
  if(idx==-1||max==0){
      printf("0 0");
  }else{
      printf("%d %d",idx+1,max);
  }

  
  return 0;
}