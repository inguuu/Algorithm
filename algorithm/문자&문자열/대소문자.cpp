#include <stdio.h>
#include <string.h>

int main() {

  char str[1001];
  fgets(str,1001,stdin);
  
  
  
  int len=strlen(str);
  
  for(int i=0;i<len;i++){
    if(str[i]>=65&&str[i]<=90){
    str[i]=str[i]+32;
    }else if(str[i]>=97&&str[i]<=122){
     str[i]=str[i]-32;
    }
  }
  
  printf("%s",str);
  
  return 0;
}