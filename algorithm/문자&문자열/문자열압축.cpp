#include <stdio.h>
#include <string.h>

int main() {
 
 char val;
 int count =1;
 char str[1001];
 
 scanf("%s",str);
 
 int len = strlen(str);
 
 val =str[0];
 for(int i=1;i<len;i++){
   if(val==str[i]){
     ++count;
   }else{
     if(count==1){
          printf("%c",val);
          count=1;
          val=str[i];
     }else{
          printf("%d%c",count,val);
          count=1;
          val=str[i];
     }
   }
   if(i==len-1){
      if(count==1){
          printf("%c",val);
     }else{
          printf("%d%c",count,val);
     }
   }
   
   
 }

  return 0;
}