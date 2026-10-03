#include 

// Function to merge two sorted sub-arrays
void merge(int a[], int low, int mid, int high) {
    int i, j, k = 0;
    // Using a temporary array large enough to hold the merged elements
    int b[100]; 
    
    i = low;
    j = mid + 1;
    
    // Compare and copy the smaller element
    while ((i <= mid) && (j <= high)) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    
    // Copy remaining elements from the left half
    while (i <= mid) {
        b[k++] = a[i++];
    }
    
    // Copy remaining elements from the right half
    while (j <= high) {
        b[k++] = a[j++];
    }
    
    // Copy back the merged result into the original array 'a'
    for (i = 0; i < k; i++) {
        a[low + i] = b[i];
    }
}

// Function to recursively divide the array
void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
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
    
    mergesort(a, 0, n - 1);
    
    printf("\n------Sorted order---------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}