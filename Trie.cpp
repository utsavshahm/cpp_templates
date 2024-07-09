#include <bits/stdc++.h>

using namespace std;

class Trie{
    public:

    Trie *chars[26];
    bool isWord;

    Trie(){
        for (int i = 0; i < 26; i++){
            this->chars[i] = nullptr;
        }
        this->isWord = false;
    }

    void insertWord(string &word){
        Trie *curr = this;
        for (char ch : word){
            int index = ch - 'a';
            if (!curr->chars[index])
            {
                curr->chars[index] = new Trie();
            }
            curr = curr->chars[index];
        }
        curr->isWord = true;
    }

    bool searchWord(string &target){
        Trie *curr = this;
        for (char ch : target)
        {
            int index = ch - 'a';
            if (!curr->chars[index])
            {
                return false;
            }
            curr = curr->chars[index];
        }
        return curr->isWord;
    }

    void createTrie(vector<string>& words){
        Trie *root = this;

        for(auto word : words){
            insertWord(word);
        }
    }
};