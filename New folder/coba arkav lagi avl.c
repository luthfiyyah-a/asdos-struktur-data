// ========[AVL Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    28-03-2020
    Struktur Data 2020
    For C
    
	Referensi: codingan mas zydhan (zydhanlinnar11)
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

typedef struct a{
	int first, second;
} pii;

typedef struct AVLNode_t
{
//    int data;
	pii data;
    struct AVLNode_t *left,*right;
    int height;
    int anak_kiri;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(pii value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    newNode->anak_kiri = 0;
    return newNode;
}

AVLNode* _search(AVLNode *root, pii value) {
    while (root != NULL) {
        if (value.first < root->data.first)
            root = root->left;
        else if (value.first > root->data.first)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node, pii value) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value.first < node->data.first)
    {
    	// jika newnode ke kiri, berarti jumlah anak kiri dari node yg sekarang bertambah
    	node->anak_kiri++;
		node->left = _insert_AVL(avl,node->left,value);
	}
    else if(value.first > node->data.first)
    	node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value.first < node->left->data.first) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value.first > node->left->data.first) // 
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value.first > node->right->data.first)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value.first < node->right->data.first)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node, pii value){
    if(node==NULL)
        return node;
    if(value.first > node->data.first)
    	node->right=_remove_AVL(node->right,value);
    else if(value.first < node->data.first)
    	node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

	if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, pii value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data.first == value.first)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, pii value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

void avl_remove(AVL *avl, pii value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}


int parent;
// DIMODIFIKASI DARI FUNGSI SEARCH
AVLNode* getParentIndex(AVLNode *root, pii value) {
    
	// untuk mengetahui suatu node berada di index ke berapa (secara descending), perlu menghitung jumlah child kanan dan kalo dia merupakan child kiri, perlu melihat index parentnya
	parent = 0;
	while (root != NULL) {
        if (value.first < root->data.first)
        {
        	root = root->left;	
		}
        else if (value.first > root->data.first)
        {
        	parent += root->anak_kiri + 1;
        	root = root->right;
		}
        else
            return root;
    }
    return root;
}

// DIMODIFIKASI
int getIndex(AVL *avl, pii value) {
    AVLNode *temp = getParentIndex(avl->_root, value);
    if (temp == NULL)
        return 0;
    
    if (temp->data.first == value.first)
    {
//    	printf("anak kanan = %d\n", temp->anak_kanan);
    	return temp->anak_kiri + parent + 1;	
	}
    else
        return 0;
}

int main(){
    AVL avlku;
    avl_init(&avlku);
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    int B;
    int i;
    int weight[N];
    pii temp;
    
    for(i=0; i<N; i++)
	{
		weight[i] = INT_MIN;
	}
    for(i=0; i<N; i++)
	{
    	scanf("%d", &B);
    	temp.first = i;
    	temp.second = B;
    	avl_insert(&avlku, temp);
    	weight[B-1] = i;
	}
	
	int counter = -1;
	unsigned long long sum = 0ULL;
	
	for(i=0; i<M; i++)
	{
		scanf("%d", &B);
		pii current = (pii) {weight[B-1] , B};
		
		printf("get index = %d\n", getIndex(&avlku, current));
		
		if(sum == 50448546) printf("");
		sum += 2 * getIndex(&avlku, current);
		printf("sum = %d\n", sum);
		avl_remove(&avlku, current);
		
		current.first = counter--;
		weight[B-1] = current.first;
		avl_insert(&avlku, current);
	}
	
	printf("%llu\n", sum);
}
