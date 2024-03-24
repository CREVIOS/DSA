#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void generateWords(int k, vector<char>& charset, stack<char>& wordStack, vector<string>& words) {
    if (k == 0) {
        // Convert stack to string
        string word;
        stack<char> tempStack = wordStack; // Copy the stack to preserve order for backtracking
        while (!tempStack.empty()) {
            word = tempStack.top() + word; // Prepend character
            tempStack.pop();
        }
        words.push_back(word);
        return;
    }
    for (char c : charset) {
        wordStack.push(c);
        generateWords(k - 1, charset, wordStack, words);
        wordStack.pop(); // backtrack
    }
}

int main() {
    vector<char> charset = {'a', 'b', 'c'};
    int k = 4;
    vector<string> words;
    stack<char> wordStack;
    generateWords(k, charset, wordStack, words);

    for (const string& word : words) {
        cout << word << endl;
    }
    return 0;
}
