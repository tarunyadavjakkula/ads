#include 
#include 

void computeLPS(char* pattern, int m, int lps[]) {
    lps[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[i] != pattern[k]) {
            k = lps[k - 1];
        }
        if (pattern[i] == pattern[k]) {
            k++;
        }
        lps[i] = k;
    }
}

void KMPSearch(char *T, int n, char *P, int m, int *lps) {
    int i = 0, j = 0, found = 0;
    
    while ((n - i) >= (m - j)) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }
        if (j == m) {
            printf("\nFound pattern at index %d", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < n && P[j] != T[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    
    if (!found) {
        printf("\nPattern not found in text.");
    }
}

int main() {
    char text[50], pattern[50];
    int lps[50], m, n;
    
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);
    
    n = strlen(text);
    m = strlen(pattern);
    
    computeLPS(pattern, m, lps);
    
    printf("\nLPS table:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", lps[i]);
    }
    
    printf("\nSearch results:");
    KMPSearch(text, n, pattern, m, lps);
    printf("\n");
    
    return 0;
}