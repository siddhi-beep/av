#include<iostream>
#include<queue>
#define max 100
using namespace std;
int g[max][max];
bool visited[max];
int v;

void bfs(queue<int>&q){
    if(q.empty())
        return;
    
    int node=q.front();
        q.pop();
        cout<<node<<" ";
    
    for(int j=0;j<v;j++){
        if(g[node][j]==1 && !visited[j]){
            visited[j]=true;
            q.push(j);
        }
    }
    bfs(q);

}

int main(){
    int e,i,j,s;
    cout<<"enter total no. of verticesL";
    cin>>v;

    cout<<"enter total no. of edges:";
    cin>>e;

    for(int i=0;i<v;i++){
        visited[i]=false;
        for(int j=0;j<v;j++){
            g[i][j]=0;
        }
    }

    cout<<"enter the starting and ending vertex of each edge:"<<endl;
    for(int k=0;k<e;k++){
        cin>>i>>j;
        g[i][j]=1;
        g[j][i]=1;

    }

    cout<<"enter starting vertex for bfs:";
    cin>>s;

    queue<int>q;
    visited[s]=true;
    q.push(s);
    bfs(q);
}