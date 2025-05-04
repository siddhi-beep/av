#include<iostream>
#include<stack>
#include<string>
using namespace std;
struct Node{
    Node*left,*right;
    char data;
};

Node*createNode(char data){
    Node*newNode=new Node();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node*constructTree(string prefix, int& index){
    if(index>=prefix.length())
        return NULL;
    Node*newNode=createNode(prefix[index++]);

    if(newNode->data>='a' && newNode->data<='z')
    return newNode;
    newNode->left=constructTree(prefix,index);
    newNode->right=constructTree(prefix,index);
    return newNode;
}

void postOrder(Node*root){
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node*temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void deleteTree(Node*root){
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    string prefix;
    cout<<"Enter prefix expreesion:";
    cin>>prefix;
    int index=0;
    Node*root=constructTree(prefix,index);

    cout<<"postorder traversal:";
    postOrder(root);
    cout<<endl;
    deleteTree(root);
    return 0;
}