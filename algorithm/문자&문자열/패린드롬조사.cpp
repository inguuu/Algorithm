#include <stdio.h>
#include <string.h>

int main() {

  char str1[1002];

  scanf("%s",str1);
  
  int len = strlen(str1);

  for(int i=0;i<len/2;i++){
    if(str1[i]!=str1[len-i-1]) {
      printf("NO");
      return 0;
    }
  }
  
  printf("YES");
  return 0;
}