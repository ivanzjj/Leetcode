class TrieNode {
public:
    TrieNode *nxt[26];
    bool end;
    TrieNode() {
        memset (nxt, 0, sizeof(nxt));
        end = false;
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode *now = root;
        for (int i=0,sz=s.length();i<sz;i++){
            if (now->nxt[ s[i]-'a' ] == NULL)
                now->nxt[ s[i]-'a' ] = new TrieNode ();
            now = now->nxt[ s[i]-'a' ];
        }
        now->end = true;
    }

    bool search(string key) {
        TrieNode *now = root;
        for (int i=0,sz=key.length();i<sz;i++){
            if (now->nxt[ key[i]-'a' ] == NULL) return false;
            now = now->nxt[ key[i]-'a' ];
        }
        return now->end;
    }

    bool startsWith(string key) {
        TrieNode *now = root;
        for (int i=0,sz=key.length();i<sz;i++){
            if (now->nxt[ key[i]-'a' ] == NULL) return false;
            now = now->nxt[ key[i]-'a' ];
        }
        return true;
    }

private:
    TrieNode* root;
};
