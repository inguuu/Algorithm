#include <stdio.h>


int map[101][101]={0,};

int n,k;

int check1(int i,int x){
  int count =1;
  
  while(1){
     if(map[i][x]+1<map[i+1][x]){
      ++count;
      ++i;
    }else{
      if(count>=k)return 1;
      else{
        count=1;
        ++i;
      }
    }
     
     if(i==n-1){
        if(count>=k)return 1;
        else return 0;
     }
  }
}

int check2(int i,int x){
  int count =1;
  
  while(1){
     if(map[i][x]>map[i+1][x]+1){
      ++count;
      ++i;
    }else{
      if(count>=k)return 1;
      else{
        count=1;
        ++i;
      }
    }
     
     if(i==n-1){
        if(count>=k)return 1;
        else return 0;
     }
  }
}



int check3(int i,int x){
  int count =1;
  
  while(1){
     if(map[x][i]+1<map[x][i+1]){
      ++count;
      ++i;
    }else{
      if(count>=k)return 1;
      else{
        count=1;
        ++i;
      }
    }
     
     if(i==n-1){
        if(count>=k)return 1;
        else return 0;
     }
  }
}

int check4(int i,int x){
  int count =1;
  
  while(1){
     if(map[x][i]>map[x][i+1]+1){
      ++count;
      ++i;
    }else{
      if(count>=k)return 1;
      else{
        count=1;
        ++i;
      }
    }
     
     if(i==n-1){
        if(count>=k)return 1;
        else return 0;
     }
  }
}

int main() {
 
 int ts;
 scanf("%d",&ts);
 for(int t=1;t<=ts;t++){
   
 scanf("%d %d",&n,&k);
 
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     scanf("%d",&map[i][j]);
   }
 }
 
 int cnt =0;
 int val;
 for(int j=0;j<n;j++){
   val=check1(0,j);
   if(val==0){
     val=check2(0,j);
   }
   
   if(val==1)++cnt;
 }
 
 for(int i=0;i<n;i++){
   val=check3(0,i);
   if(val==0){
     val=check4(0,i);
   }
   
   if(val==1)++cnt;
 }
 
 printf("#%d %d\n",t,cnt);
 
   

 }
 
  return 0;
}