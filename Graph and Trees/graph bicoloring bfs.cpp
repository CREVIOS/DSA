#include<bits/stdc++.h>
using namespace std;
const int N = 100000;

vector<int>g[N];
bool vis[N];
int level[N];
int color[N]; // while = 0, red = 1 and blue = 2
int mark = 0;

int bfs(int source){

queue<int>nodes;
nodes.push(source);
vis[source]= true;
color[source] = 1;
while(!nodes.empty())
{
    int cur_v = nodes.front();
    nodes.pop();
    cout<<cur_v<<" "<<"color :"<<color[cur_v]<<" ||| ";
    for(int x:g[cur_v])
    {
        if(!vis[x]){
            vis[x] = true;
            nodes.push(x);
            level[x] = level[cur_v] + 1;
            if(color[cur_v]==1)
            {
                color[x] = 2; // if parent is red color, then make the child blue color
            }
            else{
                color[x] = 1; // otherwise mark the child red color
            }
        }
        if(color[x] == color[cur_v])
        {
            int mark = 1; // if parent and child has same color then mark
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

if(mark==1)
{
    cout<<"Not Bicoloring graph"<<endl;
}

return 0;
}

/*
6 6
1 2
1 3
2 4
3 5
4 6
5 6
1
*/

// output

/*

1 color :1 ||| 2 color :2 ||| 3 color :2 ||| 4 color :1 ||| 5 color :1 ||| 6 color :2 |||
1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : 3

*/



