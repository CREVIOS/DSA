#include<bits/stdc++.h>
using namespace std;

void print(int ara[],int start,int n )
{
    if(start == n)
    {
        for(int i = 0; i < n;i++)
        {
            cout << ara[i] << " ";
        }

        cout << endl;
        return;
    }

    for(int i = 4; i >= 0;i--)
    {
        if(i % 2 != start % 2 )
        {
            ara[start] = i;
            print(ara,start+1,n);
        }
    }
}
int main ()
{
    int n;
    cin >> n;
    int ara[n];
    print(ara,0,n);
}