#include<bits/stdc++.h>
using namespace std;

void print(int ara[],int index,int k,int n)
{
    if(index == k)
    {
        cout << ara[0];
    
    for(int index = 1 ; index <k;index++ )
    {
        cout << " " << ara[index];
    }   
    cout<<endl;
    return;
    }

    for(int i = n-1;i >=0;i--)
    {
        ara[index] = i;
        print(ara,index+1,k,i);
    }

}

int main ()
{
    int n,k;
    cin >> n>>k;
    int ara[k];
    print(ara,0,k,n);
}