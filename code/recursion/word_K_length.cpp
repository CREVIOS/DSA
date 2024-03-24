#include <iostream>
#include <vector>
using namespace std;

void generateWords(int k, vector<char>& charset, string& current, vector<string>& words) {
    if (k == 0) {
        words.push_back(current);
        return;
    }
    for (char c : charset) {
        current.push_back(c);
        generateWords(k - 1, charset, current, words);
        current.pop_back(); // backtrack
    }
}

int main() {
    vector<char> charset = {'a', 'b', 'c'};
    int k = 2;
    vector<string> words;
    string current;
    generateWords(k, charset, current, words);

    for (const string& word : words) {
        cout << word << endl;
    }
    return 0;
}
