#include <stdio.h>

typedef struct {
    char name[50];
    char author[50];
    float price;
} books;

int main() {
    books b1 = {"Randamoozham", "M.T Vasudevan Nair", 575.00};
    books b2 = {"The Goat Life", "Benyamin", 300.00};
    books b3 = {"Paranettu", "Rahul Kartha", 152.00};

    printf("name=%s, author=%s, price=%.2f\n", b1.name, b1.author, b1.price);
    printf("name=%s, author=%s, price=%.2f\n", b2.name, b2.author, b2.price);
    printf("name=%s, author=%s, price=%.2f\n", b3.name, b3.author, b3.price);

    return 0;
}