#include <stdio.h>
#include <string.h>

void reverse(char arr[]){
  for(int i=0;i<strlen(arr)/2;i++){
    char val= arr[i];
    arr[i]=arr[strlen(arr)-i-1];
    arr[strlen(arr)-i-1]=val;
  }
  
}

int big(char a[],char b[],int max){
  
  int val=1;
  for(int i=max-1;i>=0;i--){
    if((a[i]-'0')>(b[i]-'0')){
        
      return val;
      
    }
    if((a[i]-'0')<(b[i]-'0')){
      val =0;
        
      return val;
    }

  }
 
  return val;

}

int main() {

  char a[102]={0, };
  char b[102]={0, };
  int result[103]={0,};
  
  
  scanf("%s",a);
  scanf("%s",b);
  
  int lena = strlen(a);
  int lenb = strlen(b);
  
  reverse(a);
  reverse(b);
  
 int max;
  if(lena>=lenb){
    max=lena;
  }else{
    max=lenb;
  }
  

  if(lena>=lenb){
    for(int i=lenb;i<max;i++){
      b[i]='0';
    }
  }else{
    for(int i=lena;i<max;i++){
      a[i]='0';
    }
  }
  
  int val;
  val=big(a,b,max);

  int p;
  
  if(val==1){
    
      for(int i=0;i<max;i++){
  
        if((a[i]-'0')-(b[i]-'0')>=0){
          result[i]+=(a[i]-'0')-(b[i]-'0');
        }else{//자리수 뺄셈이 음수가 나오면
        
         result[i]+=(a[i]-'0')-(b[i]-'0')+10;
          for(int j=i+1;j<max;j++){//다음자리 
            
            if((a[j]-'0')-1>=0){//다음자리가 양수면
               a[j]=a[j]-1;
              
              
              break;
            }else{//다음자리가 음수면
              a[j]='9';
         
            }
          }
          
        }
      }
      
      
      for(int i=max-1;i>0;i--){
        if(result[i]!=0){
           p=i;
           break;
        }
      }
      
      for(int i=p;i>=0;i--){
        printf("%d",result[i]);
      }
      
     
  }
  
  
  if(val==0){
    for(int i=0;i<max;i++){
  
        if((b[i]-'0')-(a[i]-'0')>=0){
          result[i]+=(b[i]-'0')-(a[i]-'0');
        }else{//자리수 뺄셈이 음수가 나오면
        
         result[i]+=(b[i]-'0')-(a[i]-'0')+10;
          for(int j=i+1;j<max;j++){//다음자리 
            
            if((b[j]-'0')-1>=0){//다음자리가 양수면
               b[j]=b[j]-1;
              
              break;
            }else{//다음자리가 음수면
              b[j]='9';
         
            }
          }
          
        }
      }
      
        
      for(int i=max-1;i>0;i--){
        if(result[i]!=0){
           p=i;
           break;
        }
      }
      
      printf("-");
      for(int i=p;i>=0;i--){
        printf("%d",result[i]);
      }
  }
  
 
 
  return 0;
}