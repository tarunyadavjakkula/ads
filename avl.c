#include 
#include 

// Structure for an AVL tree node
struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

// Helper function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to get height of tree
int height(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Helper function to create a new node
struct AVLNode* createNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // New node added as leaf
    return node;
}

// Right rotation (LL rotation)
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation (RR rotation)
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get Balance factor of node
int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Recursive function to insert key in AVL tree
struct AVLNode* insert(struct AVLNode* node, int data) {
    // 1. Perform standard BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate keys not allowed

    // 2. Update height of ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor to check if node became unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal (outputs sorted sequence)
void inOrder(struct AVLNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Preorder traversal (helps verify tree structure)
void preOrder(struct AVLNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct AVLNode* root = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nIn-order traversal of AVL Tree:\n");
    inOrder(root);

    printf("\nPre-order traversal of AVL Tree:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
