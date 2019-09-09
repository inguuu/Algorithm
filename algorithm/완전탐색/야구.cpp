#include <stdio.h>

int main() {

  int answer[1000]={0,};
  int q[100];
  int x[100];
  int y[100];
  int z[100];
  int s[100];
  int b[100];
  int n;
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
     scanf("%d",&q[i]);
     scanf("%d",&s[i]);
     scanf("%d",&b[i]);
     int d;
     x[i]=q[i]/100;
     d=q[i]%100;
     y[i]=d/10;
     z[i]=d%10;
  }
  

  for(int k=0;k<n;k++){
    for(int i=111;i<1000;i++){
      int di=0;
      int si=0;
      int bi=0;
      
      int xi=i/100;
      di=i%100;
      int yi=di/10;
      int zi=di%10;
      
      if(xi==yi||yi==zi||xi==zi){
        continue;
      }
       if(xi==0||yi==0||zi==0){
        continue;
      }
       
       if(x[k]==xi){
         ++si;
       }
       if(y[k]==yi){
         ++si;
       }
       if(z[k]==zi){
         ++si;
       }
      
      
      if(si==s[k]){
        
        //볼수 = 볼 - 중복 스트라이크 수 
          if(x[k]==xi||x[k]==yi||x[k]==zi){
            ++bi;
          }
           if(y[k]==xi||y[k]==yi||y[k]==zi){
            ++bi;
          }
           if(z[k]==xi||z[k]==yi||z[k]==zi){
            ++bi;
          }
           
          if(bi-si==b[k]){
            ++answer[i];
          }
        
      }else{
        continue;
      }
    }
  }

  int count =0;
  for(int i=111;i<1000;i++){
    if(answer[i]==n){
      ++count;
    }
  }
  
  printf("%d",count);
  return 0;
}