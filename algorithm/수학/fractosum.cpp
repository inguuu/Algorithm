#include <stdio.h>

int main() {
 
 int a,b,c,d;
 scanf("%d %d %d %d",&a,&b,&c,&d);
 
 int x = a*d+b*c;
 int y = b*d;
 
 int i=2;
while(1){
    if(x%i==0&&y%i==0){
     x=x/i; 
     y=y/i;
    }else{
      ++i;
    }
    
    if(i>=x&&i>=y){
      break;
    }
 }
 
  printf("%d %d",x,y);
  return 0;
}