#include 
#include 

// Utility function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to perform Jump Search
int jumpSearch(int arr[], int n, int target) {
    // Finding block size to be jumped
    int step = sqrt(n);
    int prev = 0;

    // Phase 1: Finding the block where element is present (if it is present)
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    // Phase 2: Doing a linear search for target in block beginning with prev
    while (arr[prev] < target) {
        prev++;

        // If we reached next block or end of array, element is not present
        if (prev == min(step, n)) {
            return -1;
        }
    }

    // If element is found
    if (arr[prev] == target) {
        return prev;
    }

    return -1;
}

int main() {
    int arr[100], n, target, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target element to search: ");
    scanf("%d", &target);

    printf("\n------Elements given---------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int index = jumpSearch(arr, n, target);

    if (index != -1) {
        printf("\nElement %d found at index %d\n", target, index);
    } else {
        printf("\nElement %d not found in the array\n", target);
    }

    return 0;
}