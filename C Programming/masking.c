#include<stdio.h>
void printbin(int n){
    int mask;
    for(int i=31;i>=0;i--){
        mask=1<<i;
        if(n & mask)
        printf("1");
        else
        printf("0");
    }

}
void setbit(int n,int pos){
    int mask= 1<<pos;
    n=n|mask;
    printbin(n);

}
void clearbit(int n,int pos){
    int mask=1<<pos;
    n=n&mask;
    printbin(n);
}
void toggle(int n){
    int mask=1<<31;
    n=n^mask;
    printbin(n);
}
int main(){
    int a;
    int pos;
    printf("enter the number= ");
    scanf("%d",&a);
    printbin(a);
    printf("enter the bit position to set: ");
    scanf("%d",&pos);
    setbit(a,pos);
    return 0;
}