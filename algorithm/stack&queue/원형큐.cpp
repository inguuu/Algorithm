#include <stdio.h>

int main() {

 int q[100]={0,};
 int front=0,rear=0;
 int count =0;
 int n,m;
  
scanf("%d %d",&n,&m);

for(int i=0;i<m;i++){
  int a;
  scanf("%d",&a);
  if(a==1){
    int b;
    scanf("%d",&b);
    if(count>=n)printf("Overflow\n");
    else{
      q[rear]=b;
      if(rear==n-1)rear=0;
      else ++rear;
      ++count;
    }
  }else if(a==2){
     if(count<=0)printf("Underflow\n");
    else{
      q[front]=0;
      if(front==n-1)front=0;
      else ++front;
      --count;
    }
  }else{
    if(count<=0){
      printf("NULL\n");
    }else{
      printf("%d\n",q[front]);
    }
  }
  
}
  
  return 0;
}