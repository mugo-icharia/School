/*Group Members:
	Mugo Icharia - SCT221-0279/2023
	Njenga Icharia - SCT221-0350/2023 */


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

void compareBinaryTree(struct Node* A, struct Node* B, struct Node* C) {
    int countA = countNodes(A);
    int countB = countNodes(B);
    int countC = countNodes(C);

    printf("Tree A has %d nodes\n", countA);
    printf("Tree B has %d nodes\n", countB);
    printf("Tree C has %d nodes\n", countC);

    if (countA >= countB && countA >= countC) {
        printf("Tree A has the highest number of nodes.\n");
        printf("\nTree A: ");
        printTree(A);
        printf("\n");
    } else if (countB >= countA && countB >= countC) {
        printf("Tree B has the highest number of nodes.\n");
        printf("\nTree B: ");
        printTree(B);
        printf("\n");
    } else {
        printf("Tree C has the highest number of nodes.\n");
        printf("\nTree C: ");
        printTree(C);
        printf("\n");
    }
}

void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("\n>>>>>>> Test 1 <<<<<<<\n");

    struct Node* treeA = createNode(11);
    treeA->left = createNode(7);
    treeA->right = createNode(15);

    struct Node* treeB = createNode(23);
    treeB->left = createNode(12);
    treeB->right = createNode(30);
    treeB->left->left = createNode(6);
    treeB->left->right = createNode(18);

    struct Node* treeC = createNode(41);
    treeC->left = createNode(29);
    treeC->right = createNode(53);
    treeC->left->left = createNode(22);
    treeC->left->right = createNode(34);
    treeC->right->left = createNode(48);
    treeC->right->right = createNode(60);

    compareBinaryTree(treeA, treeB, treeC);

    freeTree(treeA);
    freeTree(treeB);
    freeTree(treeC);

    printf("\n>>>>>>> Test 2 <<<<<<<\n");

    treeA = createNode(8);
    treeA->left = createNode(3);
    treeA->right = createNode(10);
    treeA->left->left = createNode(1);
    treeA->left->right = createNode(6);

    treeB = createNode(14);
    treeB->left = createNode(9);
    treeB->right = createNode(17);
    treeB->left->left = createNode(5);
    treeB->left->right = createNode(11);

    treeC = createNode(50);
    treeC->left = createNode(20);
    treeC->right = createNode(80);

    compareBinaryTree(treeA, treeB, treeC);

    freeTree(treeA);
    freeTree(treeB);
    freeTree(treeC);

    printf("\n>>>>>>> Test 3 <<<<<<<\n");

    treeA = NULL;

    treeB = createNode(16);
    treeB->left = createNode(8);
    treeB->right = createNode(24);

    treeC = createNode(42);

    compareBinaryTree(treeA, treeB, treeC);

    freeTree(treeB);
    freeTree(treeC);

    return 0;
}

