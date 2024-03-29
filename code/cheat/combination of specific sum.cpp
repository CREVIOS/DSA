#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)

int sum(vector<int> &tmp)
{
    int sum = 0;
    FOR(i, 0, tmp.size())
    sum += tmp.at(i);

    return sum;
}

void solve(int ara[], int n, vector<int> &tmp, int start)
{
    if (sum(tmp) == 8 && tmp.size() > 0) // Check for non-empty subset
    {
        for (auto i : tmp)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    for (int i = start; i < n; i++)
    {
        if (i > start && ara[i] == ara[i - 1]) // Skip duplicates
            continue;

        tmp.push_back(ara[i]);
        solve(ara, n, tmp, i + 1);
        tmp.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> tmp;
    int ara[n];
    FOR(i, 0, n)
    cin >> ara[i];

    sort(ara, ara + n);  // Sorting the array to handle duplicates

    solve(ara, n, tmp, 0);

    return 0;
}
