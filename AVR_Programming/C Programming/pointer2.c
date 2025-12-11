#include<stdio.h>
int main(){
int a=10,i;
int *ptr=&a;
int arr[5]={1,2,3,4,5};
int *arrptr=arr;
printf("value of a=%d\n",*ptr);
printf("value of ptr=%p\n",ptr);
*ptr=20;
printf("value of a=%d\n",a);
printf("%d\n",(*(ptr)+1));
for(i=0;i<5;i++){
    *(arrptr+i) += 5;
}
for(i=0;i<5;i++){
printf("%d ",arr[i]);
}
return 0;
}