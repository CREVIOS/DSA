#include <iostream>
#include <vector>
using namespace std;

void generateParenthesis(int open, int close, string str, vector<string>& ans) {
    if(open == 0 && close == 0) {
        ans.push_back(str);
        return;
    }
    if(open > 0) generateParenthesis(open-1, close, str+"(", ans);
    if(close > open) generateParenthesis(open, close-1, str+")", ans);
}

int main() {
    int n = 3; // 3 pairs of parentheses
    vector<string> ans;
    generateParenthesis(n, n, "", ans);
    for(auto &str : ans) cout << str << endl;
    return 0;
}
