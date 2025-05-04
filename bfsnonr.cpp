#include<iostream>
#include<queue>
#define max 10
using namespace std;

int g[max][max];
bool visited[max];
int v;

void bfs(int start){
    queue<int>q;
    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";

        for(int j =0;j<v;j++){
            if(g[node][j]==1 && !visited[j]){
                visited[j]=true;
                q.push(j);
            }
        }
    }

}

int main(){
    int e,i,j,s;
    cout<<"enter total no. of vertices:"<<endl;;
    cin>>v;

    cout<<"enter total no. of edges:";
    cin>>e;

    for(int i=0;i<v;i++){
        visited[i]=false;
        for(int j=0;j<v;j++){
            g[i][j]=0;
        }
    }

    cout<<"enter starting and ending vertex of each edge:"<<endl;
    for(int k=0;k<v;k++){
        cin>>i>>j;
        g[i][j]=1;
        g[j][i]=1;

    }

    cout<<"enter starting vertex for bfs:";
    cin>>s;
    bfs(s);
    return 0;
}