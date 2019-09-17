#include <stdio.h>
#include <string.h>

void reverse(char arr[]){
  
  for(int i=0;i<strlen(arr)/2;i++){
    char tmp =arr[i];
    arr[i]=arr[strlen(arr)-i-1];
    arr[strlen(arr)-i-1]=tmp;
  }
  
  
}
int main() {

  char a[102];
  char b[102];
  int result[203][102]={0,};// i+j//k¹ø
  
  scanf("%s",a);
  scanf("%s",b);
  
  int lena =strlen(a);
  int lenb =strlen(b);

  reverse(a);
   reverse(b);
   int k=0;
   for(int i=0;i<lena;i++){
     for(int j=0;j<lenb;j++){
       result[i+j][k]+=(a[i]-'0')*(b[j]-'0');
     }
     ++k;
   }
  
   int answer[12000];
   
   int carry=0;
     
     for(int i=0;i<lena+lenb-1;i++){
       int val=0;
      for(int j=0;j<k;j++){
    
        val+=result[i][j];
      }
        if(val+carry<10){
          answer[i]=val+carry;
          carry=0;
     
        }else{
          answer[i]=(val+carry)%10;
             carry=(val+carry)/10;
        }
     }
     
     if(carry!=0){
       printf("%d",carry);
     }
     
     for(int i=lenb+lena-2;i>=0;i--){
       printf("%d",answer[i]);
     }
 


  return 0;
}