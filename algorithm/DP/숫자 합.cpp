#include <stdio.h>

int table[100];
int n,m;



int main() {

  scanf("%d",&n);
  int m=3;
  int sum=0;
 table[1]=1;
 for(int i=2;i<=m;i++){
   sum+= table[i-1];
   table[i]=sum+1;
 }
  
  for(int i=m+1;i<=n;i++){
    for(int j=i-m;j<=i-1;j++){
      table[i]+=table[j];
    }
  }
  printf("%d\n",table[n]%1000007);

  return 0;
}