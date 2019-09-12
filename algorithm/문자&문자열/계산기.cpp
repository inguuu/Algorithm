#include <stdio.h>

int main() {

 int a,c;
 char b;
 
  scanf("%d\n",&a);
  scanf("%c\n",&b);
  scanf("%d\n",&c);
  
  if(b=='+'){
    printf("%d",a+c);
  }else if(b=='-'){
    printf("%d",a-c);
  }else if(b=='*'){
    printf("%d",a*c);
  }else if(b=='/'){
    printf("%d",a/c);
  }
  
  return 0;
}