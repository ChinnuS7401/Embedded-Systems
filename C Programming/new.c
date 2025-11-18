#include<stdio.h>
void printbin(int n){
    int mask;
    for(int i=8;i>=0;i--) {
        mask=1<<i;
        if (n&mask)
        printf("1");
        else
        printf("0");
    }
}
void setbit(int n,int pos){
    int mask=1<<pos;
    n=n|mask;
    printbin(n);
}
void togglebit(int n,int pos){
    int mask=1<<pos;
    n=n^mask;
    printbin(n);
}
int main(){
    int a;
    int pos;
    int count0=0,count1=0;
    printf("enter the number= ");
    scanf("%d",&a);
    printbin(a);
    printf("bit position to set= ");
    scanf("%d",&pos);
    setbit(a,pos);
    printf("enter the bit position to toggle=");
    scanf("%d",&pos);
    togglebit(a,pos);
    printf("number of 1s= ");
    printf("number of 0s= ");
    return 0;
}
