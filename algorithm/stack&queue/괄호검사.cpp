#include <stdio.h>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

char order[28];
char alpha[28];
int main() {
 int oidx=0;
 int aidx=0;
  stack<char> s;

  scanf("%s",order);
  int len = strlen(order);
  
  for(int i=0;i<len;i++){
    alpha[i]=order[i];
  }
  
  sort(alpha,alpha+len);
  int result[100]={0,};
  int ridx =0;
  while(1){
    if(s.empty()){
        s.push(alpha[aidx]);
        result[ridx]=1;
        ++aidx;
        ++ridx;
    }
    if(s.top()==order[oidx]){
     result[ridx]=2;
      ++ridx;
      ++oidx;
      s.pop();
    }else{
      if(aidx+1>len){
        printf("impossible");
        return 0;
      }else{
        s.push(alpha[aidx]);
        
        result[ridx]=1;
        ++ridx;
        ++aidx;
      }
      
    }
    if(oidx==len)break;
  
  }
  for(int i=0;i<100;i++){
    if(result[i]==1){
      printf("push\n");
    }else if(result[i]==2){
      printf("pop\n");
    }
  }
  return 0;
}