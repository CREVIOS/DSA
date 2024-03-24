#include<bits/stdc++.h>
using namespace std;

void generateWords(int length, int countA, vector<char>& charset, stack<char>& wordStack, vector<string>& words) {
    if (length == 7) {
        if (countA == 4) {
            
            string word;
            stack<char> tempStack = wordStack; 
            while (!tempStack.empty()) {
                word = tempStack.top() + word; 
                tempStack.pop();
            }
            words.push_back(word);
        }
        return;
    }
    for (char c : charset) {
        wordStack.push(c);
        generateWords(length + 1, countA + (c == 'a' ? 1 : 0), charset, wordStack, words);
        wordStack.pop(); 
    }
}

int main() {
    vector<char> charset = {'a', 'b', 'c'}; 
    int k = 7; 
    vector<string> words;
    stack<char> wordStack;
    generateWords(0, 0, charset, wordStack, words);

    sort(words.begin(), words.end());

    for (const string& word : words) {
        cout << word << endl;
    }
    return 0;
}
