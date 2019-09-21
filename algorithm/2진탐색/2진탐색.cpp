#include <stdio.h>

int bin(int s,int e,int arr[],int val){
  
  if(s>e){
    return -1;
  }
  else if(s==e){
    if(arr[s]==val) return 1;
    else{
      return -1;
    }
  }
  else{
    int mid = (s+e)/2;
    if(arr[mid]==val)return 1;
    else if(arr[mid]>val)return bin(s,mid-1,arr,val);
    else if(arr[mid]<val)return bin(mid+1,e,arr,val);
  }
  
  
  
}

int main() {

  int arr[100001];
  int n,q;
  
  scanf("%d",&n);
  scanf("%d",&q);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  for(int i=0;i<q;i++){
    int val;
    scanf("%d",&val);
    int answer;
    answer=bin(0,n-1,arr,val);
    if(answer==1){
      printf("YES\n");
    }else if(answer==-1){
      printf("NO\n");
    }
    
  }
  return 0;
}