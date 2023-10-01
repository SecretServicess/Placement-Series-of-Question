#include <iostream>
#include <queue>
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
    cout<< "Enter the data for inserting at left of :"<<data<<endl;
    root->left =build_tree(root->left);
    cout<<"Enter the data for inserting in the right of :"<<data<<endl;
    root->right = build_tree(root->right);
    return root;
    
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

int main() {

    node* root = NULL;

    build_tree(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    //creating a Tree
    root = build_tree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
}
