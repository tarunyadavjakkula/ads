#include 

#define MAX_SIZE 100
int P[MAX_SIZE];

// Function to find the root with path compression (Collapsing Find)
int CollapsingFind(int i) {
    int r = i;
    
    // Find root
    while (P[r] > 0) {
        r = P[r];
    }
    
    // Collapse path: make all nodes in path point directly to root
    while (i != r) {
        int s = P[i];
        P[i] = r;
        i = s;
    }
    return r;
}

// Function to perform Weighted Union
void WeightedUnion(int i, int j) {
    int root_i = CollapsingFind(i);
    int root_j = CollapsingFind(j);

    if (root_i == root_j) {
        return; // Elements are already in the same set
    }

    // P[root] stores negative count of nodes in the tree
    int temp = P[root_i] + P[root_j];
    
    if (P[root_i] > P[root_j]) { // i has fewer nodes (values are negative)
        P[root_i] = root_j;
        P[root_j] = temp;
    } else { // j has fewer nodes, or counts are equal
        P[root_j] = root_i;
        P[root_i] = temp;
    }
}

int main() {
    int n = 7; 
    
    // Initialize sets: each element is its own root with count 1 (-1)
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }

    printf("Initial state: %d disjoint sets.\n", n);
    
    printf("Performing Union(1, 2)\n");
    WeightedUnion(1, 2);
    
    printf("Performing Union(3, 4)\n");
    WeightedUnion(3, 4);
    
    printf("Performing Union(1, 3)\n");
    WeightedUnion(1, 3);
    
    printf("Find(4) returns root: %d\n", CollapsingFind(4));
    
    printf("\nArray state (P):\n");
    for(int i = 1; i <= 4; i++) {
        printf("P[%d] = %d\n", i, P[i]);
    }

    return 0;
}