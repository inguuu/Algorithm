#include <stdio.h>
#include <string.h>

int main() {

 int n;
 scanf("%d",&n);
 char str[101][101];
 
 for(int i=0;i<n+1;i++){
   scanf("%s",str[i]);
   
 }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int val=strcmp(str[i],str[j]);

         if(val>0){// 좌측이 작으면
    
           char temp[101];
           strcpy(temp,str[i]);
           strcpy(str[i],str[j]);
           strcpy(str[j],temp);
         }
    }
  printf("%s\n",str[i]);

 }
 
 

  return 0;
}