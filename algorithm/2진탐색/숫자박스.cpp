#include <stdio.h>
#include <algorithm>

using namespace std;

int bin(int s,int e,int arr[],int val){
   if(s>e){
    return -1;
  }
  else if(s==e){
    if(arr[s]==val) {
      return 1;
    }
    else{
      return -1;
    } 
  }else {
    int mid=(s+e)/2;
    if(arr[mid]==val)return 1;
    else if(arr[mid]>val) return bin(s,mid-1,arr,val);
    else if(arr[mid]<val)return bin(mid+1,e,arr,val);
  }
}

int main() {

  int n,m;
  
  int arr[300000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  sort(arr,arr+n);

   scanf("%d",&m);
  for(int i=0;i<m;i++){
    int val;
    scanf("%d",&val);
    int idx = bin(0,n-1,arr,val);
    
    if(idx==-1){
       printf("0\n");
    }else {
       printf("1\n");
    }
 
    
  }

  return 0;
}