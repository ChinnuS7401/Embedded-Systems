<<<<<<< HEAD
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
} book;

int main() {
    book books[3];
    int i, maxIndex = 0, minIndex = 0;

    // Input details for 3 books
    for (i = 0; i < 3; i++) {
        printf("Enter details for Book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", books[i].title);  // Reads string with spaces
        printf("Author: ");
        scanf(" %[^\n]", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    // Find most expensive and least expensive books
    for (i = 1; i < 3; i++) {
        if (books[i].price > books[maxIndex].price)
            maxIndex = i;
        if (books[i].price < books[minIndex].price)
            minIndex = i;
    }

    // Display results
    printf("\n📚 Most Expensive Book:\n");
    printf("Title: %s\nAuthor: %s\nPrice: ₹%.2f\n", books[maxIndex].title, books[maxIndex].author, books[maxIndex].price);

    printf("\n📘 Least Expensive Book:\n");
    printf("Title: %s\nAuthor: %s\nPrice: ₹%.2f\n", books[minIndex].title, books[minIndex].author, books[minIndex].price);

    return 0;
}
=======
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
>>>>>>> bb9ae80bec18c3ebb8ee0e6a80284fb23d215fe9
