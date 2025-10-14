#include<stdio.h>
#include<string.h>
 
typedef struct{
    char title[50];
    char author[50];
    float price;
}books;
 
int main(){
    books book[3];
    int i,maxprice=0,minprice=0;
    for(i=0;i<3;i++){
        printf("Enter the details of book %d\n",i+1);
        printf("title:");
        scanf("%s",book[i].title);
        printf("author=");
        scanf("%s",book[i].author);
        printf("price:");
        scanf("%f",&book[i].price);
    }
    for(i=0;i<3;i++){
        if(book[i].price>book[maxprice].price)
        maxprice=i;
        if(book[i].price<book[minprice].price)
        minprice=i;
    }
    printf("Expensive book is=\n");
    printf("title:%s\nauthor=%s\nprice=%f\n",book[maxprice].title,book[maxprice].author,book[maxprice].price);
    printf("least expensive book is=\n");
    printf("title:%s\nauthor=%s\nprice=%f\n",book[minprice].title,book[minprice].author,book[minprice].price);
    return 0;
}
