#include <stdio.h>
#include <string.h>
 typedef struct{
    char Title[20];
    char Author[20];
    float price;
 }books;
 int main(){
    books book[3];
    int i;
    for (i=0;i<3;i++){
        printf("Enter the details of the book %d:\n",i+1);
        printf("Title: \n");
        scanf("%s \n",book[i].Title);
        printf("Author= \n");
        scanf("%s \n",book[i].Author);
        printf("%f \n",book[i].price);
    }
return 0;

 }