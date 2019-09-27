#include <stdio.h>

int result[100005];

int getResult(int s,int e){
 if(s==e) return result[s]; 
 else{
   int mid =(s+e)/2;
   int leftMax=getResult(s,mid);
   int rightMax=getResult(mid+1,e);
   
   int leftSubMax = result[mid];
   int rightSubMax = result[mid+1];
   
    int leftsum = result[mid];
   int rightsum = result[mid+1];
   
   for(int i=mid-1;i>=s;i--){
     leftsum+=result[i];
     if(leftsum>leftSubMax)leftSubMax=leftsum;
   }
   
    for(int i=mid+2;i<=e;i++){
     rightsum+=result[i];
     if(rightsum>rightSubMax)rightSubMax=rightsum;
   }
   
   int middleMax = rightSubMax+leftSubMax;
   if(middleMax>=rightMax&&middleMax>=leftMax) return middleMax;
   else if(rightMax>=middleMax&&rightMax>=leftMax) return rightMax;
   else return leftMax;
 }
}

int main() {
 int n;
 scanf("%d",&n);
 
 for(int i=0;i<n;i++){
   scanf("%d",&result[i]);
 }
 
 printf("%d",getResult(0,n-1));
 
 
}