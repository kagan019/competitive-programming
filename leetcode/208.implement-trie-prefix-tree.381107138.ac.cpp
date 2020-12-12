class Trie {
public:
    Trie *sub[26];
    bool terminating;
    /** Initialize your data structure here. */
    Trie() {
        terminating = false;
        for (int i = 0; i < 26; i++) {
            sub[i] = nullptr; 
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0) {
            terminating = true;
            return;
        }
        int idx = word[0]-'a';
        if (sub[idx] == nullptr) {
            sub[idx] = new Trie();
        }
        sub[idx]->insert(string(word.begin()+1,word.end()));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (!word.size()) {
            return terminating;
        }
        if (sub[word[0]-'a'] == nullptr)
            return false;
        return sub[word[0]-'a']->search(string(word.begin()+1,word.end()));
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (!prefix.size())
            return true;
        if (sub[prefix[0]-'a'] == nullptr)
            return false;
        return sub[prefix[0]-'a']->startsWith(string(prefix.begin()+1,prefix.end()));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
