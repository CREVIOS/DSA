#include<bits/stdc++.h>
using namespace std;

vector<int>d;

int divisors(int n)
{

    for(int i = 2; i*i <= n; i++)
    {
       while(n%i==0)
       {
           d.push_back(i);
           n = n / i;
       }
    }
    if(n>1)
    {
        d.push_back(n);
    }
}

int main()
{
    int n;
    cin>>n;
    divisors(n);
    sort(d.begin(),d.end());
   for(int i =  0 ; i <d.size();i++)
  {
    int cnt = count(d.begin(),d.end(),d[i]);
    cout<<d[i]<<"^"<<cnt<<endl;
    i = i+ cnt-1;
  }
}
