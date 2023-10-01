#include <iostream>
using namespace std;

class node{
public:
//DATA MEMBERS
    int data; 
    node* right;
    node* left;
    
    node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

node* build_tree(node* root){
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    
    if(data==-1){
        return NULL;
    }
    cout<< "Enter the data for inserting at left of"<<data<<endl;
    root->left =build_tree(root->left);
  
    cout<<"Enter the data for inserting in the right of"<<data<<endl;
    root->right = build_tree(root->right);
    
  return root;
    
}

int main() {
    node* root = NULL;
    
    //CREATING A  TREE
    root = build_tree(root);
    
}
