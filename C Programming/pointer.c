#include<stdio.h>
int i;
 int a=10;
 int *p= &a;
 int arr[10]={1,2,3,4,5,6,7,8,9,0};
 int *ptr2=arr;
 int main(){
    printf("value of a = %d",a);
    printf("\n address of a=%p",&a);
    printf("\n address of variable a using pointer p=%p\n",p);
    printf("\nvalue inside the address stored in p=%d",*p);
    printf("size of integer a=%ld bytes\n",sizeof(a));
    printf("size of pointer p=%ld bytes\n",sizeof(p));
    for (i=0;i<10;i++){
      printf("value of arr[%d]=%d and address is %p\n",i,*(ptr2+i),(ptr2+i));
    }

    return 0;
 }