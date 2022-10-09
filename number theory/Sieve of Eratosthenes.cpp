#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool>prime(N,1);

int sieve(int n)
{

prime[0] = prime[1] =false;

for(int i= 2; i*i <n;i++)
{

    if(prime[i]==true)
    {
    for(int j  = i*i ; j < n; j += i)
    {
        prime[j] = false;
    }
    }

}

}


int main()
{
    int n = 1e6+7;
    sieve(n);
    int q;
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        cout<<prime[a]<<endl;
    }
    return 0;
}


/* Optimization 1.0

int sieve(int n)
{

prime[0] = prime[1] =false;

for(int i= 3; i*i <n;i= i+2)
{

    if(prime[i]==true)
    {
    for(int j  = i*i ; j < n; j += i)
    {
        prime[j] = false;
    }
    }

}

}


int main()
{
    int n = 1e6+7;
    sieve(n);
    int q;
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        if(a%2==0 && a!=2)
        {
        cout<<0<<endl;
        }
        else{
        cout<<prime[a]<<endl;
        }
    }
    return 0;
}
*/
