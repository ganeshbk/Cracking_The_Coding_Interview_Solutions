/******************************************************************************************************************************************/
//Problem 4.1 4.1 Implement a function to check if a tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.
//Filename:41.cpp //Naming Convention is 41 means Chapter 4 and problem 1
//Author:  Ganesh Kudleppanavar
//Version:    01/12/2018 Ganesh Kudleppanavar
/******************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#define length  100
using namespace std;

struct node {
    int data;
    node * left;
    node * right;
};

node * createBST(node *);
node * insertNode(node *,int);
node * getNewNode(int);
void inOrderTraversal(node *);
bool isBSTBalanced(node * );
int heightOfBST(node*);

int main(void){
    node * root = NULL;
    root = createBST(root);
    inOrderTraversal(root);
    bool balanced= false;
    balanced = isBSTBalanced(root);
    if(balanced){
        cout <<  " The BST is balanced";
    }
    else 
    cout <<  "the BST is not balanced";

    return 0;
}

node * createBST(node * root){
    char ch ='n';
    cout << "Wanna Enter data : ";
    cin >> ch;
    while(ch !='n'){
        int data;
        cout << "\nEnter Data: ";
        cin >>data;
        root = insertNode(root,data);
        cout << "Wanna Enter data : ";
        cin >> ch;
    }
    return root;
}

node * insertNode(node * root, int data){
    if( root == NULL){
        root = getNewNode(data);
    }
    else if(root->data > data)
        root->left  = insertNode(root->left,data);
    else
        root->right = insertNode(root->right,data);
    
    return root;
}

node * getNewNode(int data){
    node * newNode = new(node);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(node* root){
    if( root == NULL)return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool isBSTBalanced(node * root){
    int balanceFactor=0;
    if(abs(heightOfBST(root->left)-heightOfBST(root->right))>1){
        return false;
    }
    else
        return true;
}
int heightOfBST(node* root){
    if(root == NULL)return -1;
    return(max(heightOfBST(root->left),heightOfBST(root->right))+1);
}