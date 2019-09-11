#include <stdio.h>

int main() {

  int n,m;
  
  scanf("%d %d",&n,&m);
  
   if(m==0||n==0){
    printf("1");
    return 0;
 }
 
  int a=1;
  int b=1;
  long int c=1;
 for(int i=0;i<m;i++){
   c=c*a*(n-i)/(b*(i+1));
 }

    printf("%d",c);
    return 0;
 

}