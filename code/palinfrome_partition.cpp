#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void backtrack(const string &s, int start, vector<string>& path, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(path);
        return;
    }
    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, path, result);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(s, 0, path, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = partition(s);
    for (const auto &p : partitions) {
        for (const auto &str : p) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}

