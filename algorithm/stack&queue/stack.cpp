#include <stdio.h>

struct Stack{
  int data[100];
  int len =0;
  int cap =0;
  
  void create(int y){
    cap=y;
  }
  void push(int y){
    if(len<cap){
       ++len;
       data[len-1]=y;
    }else{
      printf("Overflow\n");
    }
   
  }
   void pop(){
    if(len>0){
      data[len-1]=0;
       --len;
    }else{
      printf("Underflow\n");
    }
  }
   int top(){
    if(len<=0){
      return -1;
    }else{
      return data[len-1];
    }
  }
  int size(){
   return len;
  }
};

int main() {
 
  int n;
  int m;
   
  Stack s;
  scanf("%d %d",&n,&m);
  s.create(n);
  
  for(int i=0;i<m;i++){
    int num;
    int data;
    scanf("%d",&num);
    if(num==1){
      scanf("%d",&data);
      s.push(data);
    }
    if(num==2){
      s.pop();
    }
    if(num==3){
      if(s.top()==-1){
        printf("NULL\n");
      }else{
        printf("%d\n",s.top());
      }
      
    }
  }
  

  

  return 0;
}