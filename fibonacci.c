#include 

#define MAX 100

// Helper function to find minimum of two integers
int min(int x, int y) {
    return (x <= y) ? x : y;
}

// Function to perform Fibonacci Search
int fibonacciSearch(int arr[], int n, int key) {
    // Initialize Fibonacci numbers
    int f2 = 0;              // (k-2)-th Fibonacci number
    int f1 = 1;              // (k-1)-th Fibonacci number
    int f = f2 + f1;         // k-th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (f < n) {
        f2 = f1;
        f1 = f;
        f = f2 + f1;
    }

    // Offset marks the eliminated range from the beginning
    int offset = -1;

    // Inspect elements while there are Fibonacci numbers to inspect
    while (f > 1) {
        // Compute index to inspect
        int i = min(offset + f2, n - 1);

        // If key is greater than element at index i, search right subarray
        if (key > arr[i]) {
            f = f1;
            f1 = f2;
            f2 = f - f1;
            offset = i;
        }
        // If key is less than element at index i, search left subarray
        else if (key < arr[i]) {
            f = f2;
            f1 = f1 - f2;
            f2 = f - f1;
        }
        // Element found
        else {
            return i;
        }
    }

    // Compare the last remaining element with key
    if (f1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    return -1;
}

int main() {
    int arr[MAX], n, key;

    printf("Enter number of elements (sorted): ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int index = fibonacciSearch(arr, n, key);

    if (index >= 0) {
        printf("\nFibonacci Search: Element found at index %d\n", index);
    } else {
        printf("\nFibonacci Search: Element not found\n");
    }

    return 0;
}