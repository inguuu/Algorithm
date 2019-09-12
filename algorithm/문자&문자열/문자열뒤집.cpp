#include <stdio.h>
#include <string.h>

int main() {

 char str1[1001];

 fgets(str1,1001,stdin);
 

 for(int i=strlen(str1)-1;i>=0;i--){
   printf("%c",str1[i]);
 }

  return 0;
}