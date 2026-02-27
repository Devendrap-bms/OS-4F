#include<stdio.h>
#include<conio.h>
int linearSearch(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 10, 50, 30, 70, 80, 60, 20, 90, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 90;
    int i = linearSearch(arr, n, key);
    if (i == -1)
        printf("Search UnSuccess");
    else
        printf("Search Success at : %d", i);

    return 0;
}
