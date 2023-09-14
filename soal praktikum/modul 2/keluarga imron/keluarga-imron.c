#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
    char nama[100];
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value, char nama[]) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    strcpy(newNode->nama, nama);
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, char nama[]) {
    if (root == NULL) 
        return __bst__createNode(value, nama);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, nama);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, nama);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, char nama[]) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, nama);
        bst->_size++;
    }
}

char* cari_kota(BST* bst, int B1, int B2){
    
    BSTNode* root = bst->_root;
    while(1){
        
        if( (B1<root->key && B2>root->key) ||(B2<root->key && B1>root->key)){
            return root->nama;
        }
        else if( B1<root->key && B2<root->key){
            root = root->left;
        }
        else if( B1>root->key && B2>root->key){
            root = root->right;
        }
        else if( B1==root->key || B2==root->key){
            return root->nama;
        }
        
    }
    
}
int main()
{
    BST bst;
    int N;
    int B; //id yang akan dimasukkan ke pohon keluarga
    int B1, B2; //2 id kota yang akan dicek kota pertemuannya
    int i;
    char nama_kota[100];
    bst_init(&bst);

    scanf("%d", &N);
    
    for(i=0; i<N; i++)
	{
        scanf("%d %s", &B, &nama_kota);
        bst_insert(&bst, B, nama_kota);
	}
    
    int t;
    scanf("%d", &t);
    for(i=0; i<t; i++)
	{
        scanf("%d %d", &B1, &B2);
        printf("%s\n", cari_kota(&bst, B1, B2));
    }
    
    
    return 0;
}
