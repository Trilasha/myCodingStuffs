#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* left=NULL;
    node* right=NULL;
    int data;
    node(int x){
        data=x;
    }
};
bool nodeIsPresent(node* root,int key){
    if(root==NULL) return 0;
    if(root->data==key) return 1;
    bool found=false;
    if(root->data<key){
        found|=nodeIsPresent(root->right,key);
    }else{
        found|=nodeIsPresent(root->left,key);
    }
    return found;
}
int main(){
    node* root=new node(3);
    root->left=new node(2);
    root->left->left=new node(1);
    root->right=new node(5);
    root->right->right=new node(6);
    bool findNode=nodeIsPresent(root,9);
    cout<<findNode<<endl;
    return 0;
}


