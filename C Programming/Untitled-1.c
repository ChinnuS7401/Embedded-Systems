#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int size) {
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return (second == INT_MIN) ? -1 : second; // Return -1 if no second largest found
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findSecondLargest(arr, size);

    if (result != -1)
        printf("The second largest element is %d\n", result);
    else
        printf("No second largest element found.\n");

    return 0;
}