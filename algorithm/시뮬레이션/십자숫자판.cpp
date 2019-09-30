#include <stdio.h>

int idx[11]={0,};
int a[11][4]={0,};
int n;
int num1;
int flag =1;
long long int max=0;
long long int sum =0;
void flagCheck(){
  if(flag==1)flag=2;
  else flag=1;
}

int check(int l,int r){
  int ll;
  int rr;
  
  if(l<0) ll=-1*l;
  else ll= l;
  
  if(r<0) rr=-1*r;
  else rr= r;
  
   if((ll%2==0&&rr%2==0)||(ll%2==1&&rr%2==1)){
     return 0;
   }else{
     return l*r;
   }
}

void getResult(int x){
  if(x==n){
    sum=0;
    for(int i=0;i<n;i++){
       if(i==0){
         num1=a[i][idx[i]];
         flagCheck();
       }else if(i==n-1){
         sum+= check(num1,a[i][idx[i]]);
       }else{
         int num[2];
         num[0]=a[i][idx[i]];
          num[1]=a[i][3-idx[i]];
          for(int k=0;k<2;k++){
              if(flag==2){
                sum+= check(num1,num[k]);
                flagCheck();
              }else{
                num1=num[k];
                flagCheck();
              }
          }
          
       }
      
    }
    if(sum>=max){
      max=sum;
    }
  }else{
    for(int i=0;i<4;i++){
      idx[x]=i;
      getResult(x+1);
    }
  }
  
 
  
}

int main() {

  
  int tc;
  scanf("%d",&tc);
  
 for(int t=0;t<tc;t++){
     scanf("%d",&n);
     max=0;

      for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
          scanf("%d",&a[i][j]);
        }
      }
        
    if(n==1){
      printf("%d 0\n",t+1);
      continue;
    } 
    
         getResult(0);
        
        printf("%d %lld\n",t+1,max);
     
 
 }
 
 int a=-3;
 int b= -1*a;
 //printf("%d %d",b,b%2);
 
  

  return 0;
}