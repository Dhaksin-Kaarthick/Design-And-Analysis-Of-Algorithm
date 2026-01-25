//CH.SC.U4CSE24115
#include <stdio.h>
#include <stdlib.h>

struct AVL {
    int key;
    struct AVL *left, *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct AVL *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

struct AVL* newNode(int key) {
    struct AVL* node = (struct AVL*)malloc(sizeof(struct AVL));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct AVL* rightRotate(struct AVL* y) {
    struct AVL* x = y->left;
    struct AVL* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct AVL* leftRotate(struct AVL* x) {
    struct AVL* y = x->right;
    struct AVL* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct AVL* n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct AVL* insertAVL(struct AVL* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorderAVL(struct AVL* root) {
    if (root != NULL) {
        inorderAVL(root->left);
        printf("%d ", root->key);
        inorderAVL(root->right);
    }
}

int main() {
    int keys[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = sizeof(keys)/sizeof(keys[0]);

    struct AVL* root = NULL;

    for (int i = 0; i < n; i++)
        root = insertAVL(root, keys[i]);

    printf("AVL Tree Inorder Traversal:\n");
    inorderAVL(root);

    return 0;
}
