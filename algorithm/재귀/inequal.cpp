#include <stdio.h>


int n;
int k;
char e[11];
int result[11];
int check[11]={0,};
int stop=0;
int stop2=0;

void getMax(int x){
  
  if(stop==1) return;
  if(x==k){
    int print=1;
    for(int i=0;i<n;i++){
      if(e[i]=='>'){
        if(result[i]<=result[i+1]){
          print =0;
          break;
        }
      }else{
        if(result[i]>=result[i+1]){
          print =0;
           break;
        }
      }
    }
    if(print==1){
      for(int i=0;i<k;i++){
        printf("%d",result[i]);
        stop=1;
      }
    }
  }else{
    
    for(int i=9;i>=0;i--){
    if(check[i]==0){
       result[x]=i;
       check[i]=1;
       getMax(x+1);
       check[i]=0;
      }
    }
  }
}

void getMin(int x){
  
  if(stop2==1) return;
  if(x==k){
    int print=1;
    for(int i=0;i<n;i++){
      if(e[i]=='>'){
        if(result[i]<=result[i+1]){
          print =0;
          break;
        }
      }else{
        if(result[i]>=result[i+1]){
          print =0;
           break;
        }
      }
    }
    if(print==1){
      for(int i=0;i<k;i++){
        printf("%d",result[i]);
        stop2=1;
      }
    }
  }else{
    
    for(int i=0;i<=9;i++){
    if(check[i]==0){
       result[x]=i;
       check[i]=1;
       getMin(x+1);
       check[i]=0;
      }
    }
  }
}
 
 int main(){
   
   scanf("%d",&n);
   k=n+1;
   for(int i=0;i<n;i++){
     scanf(" %c",&e[i]);
   }
   getMax(0);
   printf("\n");
   getMin(0);
   return 0;
 }