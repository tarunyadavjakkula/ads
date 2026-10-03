#include 

// Function to find the maximum value in the array
int getMax(int a[], int n) {
    int max_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }
    return max_val;
}

// A function to do counting sort of a[] according to the digit represented by pos
void countingSortForRadix(int a[], int n, int pos) {
    int b[100]; // Temporary output array
    int i, count[10] = {0}; // Initialize count array for digits 0-9

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        count[(a[i] / pos) % 10]++;
    }

    // Modify count[i] so it contains actual positions of digits in output array
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (looping backwards maintains stability)
    for (i = n - 1; i >= 0; i--) {
        b[count[(a[i] / pos) % 10] - 1] = a[i];
        count[(a[i] / pos) % 10]--;
    }

    // Copy the output array to a[], so a[] now contains sorted numbers for this digit
    for (i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

// Main function that sorts a[] of size n using Radix Sort
void radixsort(int a[], int n) {
    // Find the maximum number to determine the total number of digits
    int max_val = getMax(a, n);

    // Apply counting sort for every digit position (1, 10, 100, etc.)
    for (int pos = 1; max_val / pos > 0; pos *= 10) {
        countingSortForRadix(a, n, pos);
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n------Elements given---------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    radixsort(a, n);

    printf("\n------Sorted order---------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}