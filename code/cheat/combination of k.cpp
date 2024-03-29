
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void print(vector<int> temp)
{
    for (auto it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
}

void makeCombiUtil(
    vector<int> &tmp, int n, int left, int k)
{

    if (k == 0)
    {
        print(tmp);
        return;
    }
    for (int i = left; i <= n; ++i)
    {

        tmp.push_back(i);
        cnt++;
        makeCombiUtil(tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}

int main()
{

    int n = 41;
    int k = 3;
    vector<int> tmp;
    makeCombiUtil(tmp, n, 1, k);
    return 0;
}
