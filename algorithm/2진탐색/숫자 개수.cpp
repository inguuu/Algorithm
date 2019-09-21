#include <stdio.h>
#include <algorithm>

using namespace std;

int n,q;
int arr[100001];
int getFront(int a){
  //a의 첫번째 시작점을 구한다 end로
  int start,end;//start는 항상 작다 end는 크거나 같다
  if(arr[0]>a) return -1;
  else if(arr[0]==a) return 0;
  else if(arr[0]<a) start =0;
  
  if(arr[n-1]>=a) end=n-1;
  else if(arr[n-1]<a) return -1;
  
  while(end-start>1){
    int mid =(start+end)/2;
    if(arr[mid]<a){
      start=mid;
    }else{
      end=mid;
    }
    
  }
  if(arr[end]==a) return end;
  else return -1;
  
}
int getEnd(int a){
   //a의 마지막 끝점을 구한다 start로
  int start,end;//start는 항상 작거나 같다 end는 크디
  if(arr[0]<=a) start =0;
  else if(arr[0]>a)return -1;
  
  if(arr[n-1]<a) return -1;
  else if(arr[n-1]==a) return n-1;
  else end=n-1;
  
  while(end-start>1){
    int mid=(end+start)/2;
    if(arr[mid]<=a){
      start=mid;
    }else{
      end=mid;
    }
  }
  
  if(arr[start]==a){
    return start;
  }else {
    return -1;
  }
}
int main(){
 scanf("%d %d",&n,&q);
 for(int i=0;i<n;i++){
   scanf("%d",&arr[i]);
 }
 sort(arr,arr+n);
 
 for(int i=0;i<q;i++){
   int val;
   scanf("%d",&val);
   int front,end;
   front = getFront(val);
   end = getEnd(val);

  if(front==-1){
    printf("0\n");
  }else {
      printf("%d\n",end-front+1);
  }
 
 }
  
  
  return 0;
}