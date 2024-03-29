#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)

void solve(int ara[], int n, vector<int> &tmp, int start, int k)
{
    if (tmp.size() == k)
    {
        FOR(i, 0, k)
        cout << tmp.at(i) << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < n; i++)
    {
        if (tmp.empty() || (tmp.back() < ara[i]))
        {
            tmp.push_back(ara[i]);
            solve(ara, n, tmp, i + 1, k);
            tmp.pop_back();
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> tmp;
    int ara[n];
    FOR(i, 0, n)
    cin >> ara[i];

    sort(ara, ara + n); // Sorting the array to handle duplicates

    solve(ara, n, tmp, 0, k);

    return 0;
}
