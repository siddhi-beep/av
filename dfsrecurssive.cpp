#include<iostream>
#include<vector>
#define max 10
using namespace std;
int g[max][max];
bool visited[max];
int n;

void dfs(int i){
    cout<<i<<" ";
    visited[i]=true;

    for(int j=0;j<n;j++){
        if(!visited[j] && g[i][j]==1){
            dfs(j);
        }
    }
}

int main(){
    cout<<"enter total no. of verices:";
    cin>>n;

    cout<<"enter adjacency matric:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    cout<<"dfs starting from vertex 0:"<<endl;
    dfs(0);
    return 0;
}