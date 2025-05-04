#include<iostream>
#define max 10
using namespace std;
int g[max][max];
bool visited[max];
int stack[max];

int main(){
    int n,e,i,j,v;
    int top=0;
    cout<<"enter total no. of vertices(1base index):"<<endl;
    cin>>n;

    cout<<"enter no. of edges:"<<endl;
    cin>>e;

    for(int i=0;i<n;i++){
        visited[i]=0;
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }

    cout<<"enter start and end vertex of each edge:"<<endl;
    for(int k=0;k<e;k++){
        cin>>i>>j;
        g[i][j]=1;
        g[j][i]=1;
    }

    cout<<"enter starting vertex for dfs:";
    cin>>v;

    cout<<"dfs traversal is:";
    cout<<v<<" ";
    visited[v]=true;
    stack[top++]=v;

    while(top>0){
        v=stack[top-1];
        bool found=false;
        for(int j=1;j<=n;j++){
            if(g[v][j]==1 && !visited[j]){
                cout<<j<<" ";
                visited[j]=true;
                stack[top++]=j;
                found =true;
                break;
            }
        }
        if(!found){
            top--;
        }
    }
    cout<<" ";
    return 0;

}



