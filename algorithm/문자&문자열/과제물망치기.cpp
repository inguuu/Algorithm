#include <stdio.h>
#include <string.h>

int main() {

  char str[100000];

  fgets(str,100000,stdin);

  for(int i=0;i<strlen(str);i++){
    if(str[i]==32){
      continue;
    }
    printf("%c",str[i]);
  }
  

  return 0;
}