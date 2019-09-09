#include <stdio.h>

int main() {

  int a[100];
  int count[100]={0, };
  int n;
  
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
   scanf("%d",&a[i]);
  }
  
  int j=0;
  int sum=0;
 for(int i=0;i<n;i++){
   j=a[i];
   if(count[j]<2){
     ++count[j];
     ++sum;
   }
  }
  
  if(sum>=6){
    printf("YES");
  }
  if(sum<6){
    printf("NO");
  }
  return 0;
}