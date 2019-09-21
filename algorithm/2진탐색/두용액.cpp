#include <stdio.h>

int arr[100001];
int a[2];
int getResult(int n){
  for(int i=0;i<n;i++){
     a[0]=arr[i];
    int b;
    if(a[0]<0){
      b=-1*a[0];
    }else{
      b=a[0];
    }
    int s=0;
    int e=n-1;
    while(e-s>1){
      int mid=(e+s)/2;
      if(arr[mid]<b) s=mid;
      else if(arr[mid]==b){
         a[1]= b;
         return a[1];
      }
      else e=mid;
    }
    int n1,n2;
    if(a[0]+arr[s]<0){
      n1=-1*(a[0]+arr[s]);
    }else{
      n1=(a[0]+arr[s]);
    }
    
    if(a[0]+arr[e]<0){
      n2=-1*(a[0]+arr[e]);
    }else{
      n2=(a[0]+arr[e]);
    }
    
    if(n1>=n2){
      a[1]=arr[e];
       return a[1];
    }else{
      a[1]=arr[s];
       return a[1];
    }
  }
  
}
int main() {

  int n;
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  a[1]=getResult(n);
  printf("%d %d",a[0],a[1]);
  return 0;
}