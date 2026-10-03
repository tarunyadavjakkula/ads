#include 

// Function to perform Shell Sort using while loops for easier readability
void shellSort(int arr[], int n) {
    int gap = n / 2;
    
    // Continue sorting as long as we have a valid gap
    while (gap > 0) {
        
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            
            // Shift earlier gap-sorted elements up until the correct location is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            
            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
        
        // Reduce the gap for the next pass
        gap = gap / 2;
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n------Elements given---------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("\n------Sorted order---------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}