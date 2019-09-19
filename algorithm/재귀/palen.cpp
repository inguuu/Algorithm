#include <stdio.h>
#include <string.h>
int func(char str[],int s,int e){
  
  if(str[s]!=str[e]){
    
    return 0;
    
  }else{
    
    if(s==strlen(str)/2){
      return 1;
    }else{
      return func(str,s+1,e-1);
    }
    
    
  }
  
  
}

int main() {

  char str[100];

  scanf("%s",str);
  int len =strlen(str);
  
  int val;
  val=func(str,0,len-1);
  
  if(val==1){
     printf("TRUE");
  }else{
    printf("FALSE");
  }
  
  
  

  return 0;
}