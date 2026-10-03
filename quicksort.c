#include 

int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);
int n;

int main() {
    int a[12], i;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("\n ------Elements given---------\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    quicksort(a, 0, n - 1);
    
    printf("\n ------sorted order---------\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}

void quicksort(int a[], int low, int high) {
    int k, i;
    if(low < high) {
        k = partition(a, low, high);
        
        printf("\n====pvt= %d pvt index=%d====\n", a[k], k);
        for(i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        
        quicksort(a, low, k - 1);
        quicksort(a, k + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pvt, i, j, temp;
    
    pvt = a[low];
    i = low;
    j = high + 1;
    
    do {
        do {
            i++;
        } while(i <= high && a[i] < pvt);
        
        do {
            j--;
        } while(a[j] > pvt);
        
        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while(i < j);
    
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    return j;
}