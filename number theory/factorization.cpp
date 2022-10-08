#include<bits/stdc++.h>
using namespace std;

vector<int>d;

int divisors(int n)
{

    for(int i = 1; i*i <= n; i++)
    {
        if(n%i==0)
        {
            if(i!=n/i)
            {
            d.push_back(i);
            d.push_back(n/i);
            }
            else{
                d.push_back(i);
            }

        }
    }
}

int main()
{
    int n;
    cin>>n;
    divisors(n);
    sort(d.begin(),d.end());
    cout<<"Number of Factors :"<<d.size()<<endl;
for(int i =  0 ; i <d.size();i++)
{
    cout<<d[i]<<endl;
}
}
