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
