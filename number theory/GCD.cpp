#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
     if(b==0) return a;
     return gcd(b,a%b);// Euclidian GCD algorithm
}

// a * b = gcd(a,b) * lcm(a*b) 
/* GCD(12,8)

8 ) 12 ( 1
    8
    -
    4
 
 
4 ) 8 ( 2
    8
    -
    0   


*/

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(min(a,b),max(a,b))<<endl;
}

// STL gcd function is __gcd(a,b)
// converting two number in their lowest fraction m / n => (a/gcd(a,b)) / (b / gcd(a,b))
