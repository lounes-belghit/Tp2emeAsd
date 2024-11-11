#include <stdio.h>
void f1(int *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("enter the indice %d",i);
        scanf("%d",p+i);
    }
}
int main(){
    int a[100];
    int n;
    printf("enter the number of elements");
    scanf("%d",&n);
    f1(a,n);
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}