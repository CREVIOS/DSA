#include<bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int>g[N];
bool vis[N];
int level[N];

int bfs(int source){

queue<int>nodes;
nodes.push(source);
vis[source]= true;

while(!nodes.empty())
{
    int cur_v = nodes.front();
    nodes.pop();
    cout<<cur_v<<" ";
    for(int x:g[cur_v])
    {
        if(!vis[x]){
            vis[x] = true;
            nodes.push(x);
            level[x] = level[cur_v] + 1;
        }
    }


}

cout<<endl;
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

int source;
cin>>source;
bfs(source);


for(int i = 1;i<=n;i++)
{
 cout<<i<<" : "<<level[i]<<endl;
}


return 0;
}

/*
13 13
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
9 11
1
*/

// output

/*

1 2 3 13 5 4 6 7 8 9 10 12 11 1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : 3
7 : 3
8 : 3
9 : 3
10 : 3
11 : 4
12 : 4
13 : 1

*/



