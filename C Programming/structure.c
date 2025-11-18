#include<stdio.h>
#include<string.h>
#pragma pack(1)

typedef struct{
    int rollnumber;
    char name[10];
    float marks;
}student;
int main(){
student akhil;
akhil.rollnumber=1;
strcpy(akhil.name,"akhil");
akhil.marks=100;
printf("rollnumber:%d,name:%s,marks:%f\n", akhil.rollnumber,akhil.name,akhil.marks);
 return 0;
}