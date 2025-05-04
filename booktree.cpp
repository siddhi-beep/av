#include<iostream>
using namespace std;
struct node{
    char name[50];
    int chcount;
    node *child[50];
};

class BookTree{
    node *root;
    public:
        BookTree(){
            root=NULL;
        }
        void create();
        void display();
};

void BookTree::create(){
    root= new node();
    cout<<"Enter book name:"<<endl;
    cin>>root->name;
    cout<<"enter total no. of chapters:"<<endl;
    cin>>root->chcount;
    for(int i=0;i<root->chcount;i++){
        root->child[i]=new node();
        cout<<"enter name of chapter"<<" "<<i+1<<endl;
        cin>>root->child[i]->name;
        cout<<"Enter total no. of sections in chapter:"<<i+1;
        cin>>root->child[i]->chcount;
        for(int j=0;j<root->child[i]->chcount;j++){
            root->child[i]->child[j]=new node;
            cout<<"enter name of section:"<<" "<<j+1<<endl;
            cin>>root->child[i]->child[j]->name;
            cout<<"Enter total no. of subsections in"<<" "<<j+1<<":"<<endl;
            cin>>root->child[i]->child[j]->chcount;
            for(int k=0;k<root->child[i]->child[j]->chcount;k++){
                root->child[i]->child[j]->child[k]=new node();
                cout<<"enter name of subsection in"<<" "<<k+1<<":"<<endl;
                cin>>root->child[i]->child[j]->child[k]->name;

            }
        }


    }
}

void BookTree:: display(){
    node *temp=root;
    cout<<temp->name<<endl;

    for(int i=0;i<root->chcount;i++){
        cout<<"\n\t"<<i+1<<" ."<<root->child[i]->name<<endl;
        for(int j=0;j<root->child[i]->chcount;j++){
            cout<<"\n\t"<<j+1<<" ."<<root->child[i]->child[j]->name<<endl;
            for(int k=0;k<root->child[i]->child[j]->chcount;k++){
                cout<<"\n\t"<<k+1<<" ."<<root->child[i]->child[j]->child[k]->name<<endl;
            }
        }
    }
}

int main(){
    char cont;
    int ch;
    BookTree t;
    do{
        cout<<"1.Create\n 2.Dispaly";
        cout<<"\nenter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                t.create();
                break;
            case 2:
                t.display();
                break;
            default:
                cout<<"invalid choice";
        }
        cout<<"do you want to continue(y/n):";
        cin>>cont;

    }
    while(cont=='y');
        return 0;
    
}