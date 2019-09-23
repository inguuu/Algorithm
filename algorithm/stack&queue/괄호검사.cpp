
#include <stdio.h>
#include <string.h>

int main() {

  int idx=0;
  
  char str[52];
  scanf("%s",str);
  
  int len = strlen(str);
  
  for(int i=0;i<len;i++){
    if(str[i]=='('){
      ++idx;
    }else{
      --idx;
    }
    if(idx<0){
      printf("NO");
      return 0;
    }
  }
  if(idx==0){
     printf("YES");
  }else{
     printf("NO");
  }

  return 0;
}