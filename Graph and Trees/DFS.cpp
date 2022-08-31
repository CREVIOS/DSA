#include<bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int>g[N];
bool vis[N];
vector<vector<int>>cc;
vector<int>current_cc;


int dfs(int vertex){
// take action after entering the vertex
 vis[vertex] = true;
cout<<"vertex: "<<vertex<<endl;
current_cc.push_back(vertex); // sorting all the node for a connected component
for(int child: g[vertex]){
// take action before entering the child
cout<<"parent: "<<vertex<<" child: "<<child<<endl;

if(vis[child]) continue;

dfs(child);

// take action after exiting the child
}
// take action after exiting the vertex
}


int main()
{
int n , m;
cin>>n>>m;

for(int i = 0; i < m; i++)
{
int u , v;
cin>>u>>v;

g[u].push_back(v);
g[v].push_back(u);
}

for(int i = 1; i<=n; i++)
{

    if(vis[i]) continue;
    current_cc.clear();
    dfs(i);
    cc.push_back(current_cc);
}


cout<<cc.size()<<endl;   // number of connected components or number of trees in the forest

// printing connected components
    for(auto x: cc)
    {
        for(int vertex: x)
        {
            cout<<vertex<<" ";
        }
        cout<<endl;
    }




return 0;
}





