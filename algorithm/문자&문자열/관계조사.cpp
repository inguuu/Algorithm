#include <stdio.h>
#include <string.h>

int main() {

  char str1[1000];
  char str2[1000];
  
 scanf("%s",str1);
 scanf("%s",str2);
 
 int len1 = strlen(str1);
 int len2 = strlen(str2);
 int count=0;
 
 for(int i=0;i<len1-4; i++){
   count=0;
   for(int j=0;j<len2;j++){
     if(str1[i+j]==str2[j]){
       ++count;
       if(count==len2){
           printf("YES");
           return 0;
       }
     }
   }
 }
 
printf("NO");
 
  return 0;
}