#include <stdio.h>
 const int MAX =100;
 
 struct Tree{
    int left;
    int right;
 };
 
   Tree tree[100];
   //tree[i] = 노드 i의정보를 담고있음
 //tree[i].left = 노드 i의 왼쪽 노드 번호
 //tree[i].right = 노드 i의 오른쪽 노드 번호
 
 void preorder(int x){
   //x를 루트로 하는 서브트리 전위 순위 Root L R
   // preorder(2) 2=> 4=> 5
   if(tree[x].left==-1&&tree[x].right==-1){
     printf("%d ",x);
   }else{
     printf("%d ",x);
    if(tree[x].left!=-1){
        preorder(tree[x].left);
    }
     if(tree[x].right!=-1){
        preorder(tree[x].right);
    }
   }
   
 }
 void inorder(int x){
   // L Root R
  if(tree[x].left==-1&&tree[x].right==-1){
    printf("%d ", x);
  }else{
    
    if(tree[x].left!=-1){
      inorder(tree[x].left);
    }
    printf("%d ",x);
     if(tree[x].right!=-1){
         inorder(tree[x].right);
    }
    
  }
   
 }
 void postorder(int x){
   // L R Root
  if(tree[x].left==-1&&tree[x].right==-1){
    printf("%d ", x);
  }else{
    
    if(tree[x].left!=-1){
      postorder(tree[x].left);
    }
   
     if(tree[x].right!=-1){
         postorder(tree[x].right);
    }
     printf("%d ",x);
  }
   
 }
 
int main() {
  

  int n;
   
   scanf("%d",&n);
   
   for(int i=0;i<n;i++){
     int a,b,c;
     scanf("%d %d %d",&a,&b,&c);
     
     tree[a].left=b;
     tree[a].right=c;
   }
   

   
   preorder(0);
   printf("\n");
    inorder(0);
    printf("\n");
     postorder(0);
  return 0;
}