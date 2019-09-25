#include <stdio.h>
#include <string.h>

int main() {

  char paren[50];
  int len;
  int stack[50];
  int top=0;;
  
  scanf("%s",paren);
  len = strlen(paren);
  
  //push stack[top++]
  //pop stack[--top]=0; 
  //top stack[top-1];
  
  for(int i=0;i<len;i++){
    
    if(paren[i]=='['||paren[i]=='('){ // (,[
      if(paren[i]=='['){
        stack[top++]=-2;
      }else{
        stack[top++]=-1;
      }
    }
    else{ //값,),}
      if(top==0){
        printf("0\n");
        return 0;
      }
      if(stack[top-1]==-1||stack[top-1]==-2){
        if(paren[i]==')'&&stack[top-1]==-1){
          stack[--top]=0;
          stack[top++]=2;
        }
        else if(paren[i]==']'&&stack[top-1]==-2){
          stack[--top]=0;
          stack[top++]=3;
        }
        else{
          printf("0");
          return 0;
        }

      }
      else{
        int val=stack[top-1];
        stack[--top]=0;
        if(paren[i]==')'&&stack[top-1]==-1){
          stack[--top]=0;
         stack[top++]= val*2;
        }else if(paren[i]==']'&&stack[top-1]==-2){
          stack[--top]=0;
         stack[top++]= val*3;
        }else{
           printf("0");
          return 0;
        }
        
      }
       if(top>=2&&stack[top-1]>0&&stack[top-2]>0){
          stack[top-2]+=stack[top-1];
          stack[--top]=0;
        }
      
    }
    
  }//for문 끝
  
  if(top==1&&stack[0]>0) printf("%d",stack[top-1]);
  else printf("0");
  return 0;
}