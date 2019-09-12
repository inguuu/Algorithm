#include <stdio.h>

int main() {

  int n;
  int a[250000];
  
  for(int i=2;i<=250000;i++){
    if(a[i]==-1)continue;
    a[i]=1;
    for(int j=i*2;j<250000;j=j+i){
        a[j]=-1;
    }
  }


  while(1){
    
    scanf("%d",&n);
    int count=0;
    if(n==0) break;
    
    for(int i=n+1;i<=2*n;i++){
      if(a[i]==1){
        ++count;
      }
    }
    printf("%d\n",count);
    

  }

  return 0;
}