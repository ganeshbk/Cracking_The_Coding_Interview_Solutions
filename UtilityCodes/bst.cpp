#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
};

class tree{
    public:
        node * insertNode(node * root, int);
        node * getNewNode(int data);
        node * createTree(node * root);
        node * findCommonAncesestor(int,int, node*);

};

node * tree::createTree(node * root){
    char ch = 'n';
    cout << "want to enter data(Y|N) :" ;
    cin >> ch;
    int data;
    while(ch !='n'){
        cout << "Enter data : ";
        cin >> data;
        root =  insertNode(root, data);
        cout << "\nWant to enter data(Y|N) :" ;
        cin >> ch;
    }
    return root;
}
node * tree::insertNode(node * root, int data){
    if (root == NULL)
        root = getNewNode(data);
    else if(root->data>data)
        root->left = insertNode(root->left,data);
    else    
        root->right = insertNode(root->right,data);
return root;
}
node * tree::getNewNode(int data){
    node * newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node * tree::findCommonAncesestor(int data1, int data2, node* root){
    vector<node*> path1;
    vector<node*> path2;
    node * temp;
    while(temp->data!= data1 && temp!=NULL)
    {
        if(data1>temp->data)
        {
            path1.push_back(temp);
            temp = temp->right;            
        }
        else if(data1<temp->data)
        {
            path1.push_back(temp);
            temp =  temp->left;
        }
    }
    temp = root;
    while(temp->data!= data2 && temp!=NULL)
    {
        if(data2>temp->data)
        {
            path2.push_back(temp);
            temp = temp->right;            
        }
        else if(data2<temp->data)
        {
            path2.push_back(temp);
            temp =  temp->left;
        }
    }
    vector<node *>::iterator itr1,itr2;
    int size1,size2;
    size1= path1.size();
    size2 = path2.size();
        for(itr1=path1.begin();itr1!= path1.end();++itr1){
            itr2 = std::find(path2.begin(),path2.end(),*itr1);
            if(*itr2)
                return *itr2;
        }
    return NULL;
}

int main(void){
    tree t;
    node *root=NULL;
    t.createTree(root);
    node * found;
    found = t.findCommonAncesestor(100,32, root);
    cout <<"\nFound data: "<<found->data;
    return 0; 
}