/*
 we should design a data structure to support two operations
 1. check whether a key exist or not
 2. put a specific element to the end of the array

 for first operation, we can use a STL's unordered_map as a hashtable to solve it
 for second operation, if we use brute force, every operation's time complexity is O (N)
 this is so expensive.

 we can not move element directly, so we use two array L and R to specify every element's
 Left neighbor and Right neighbor.

 Actually, it is a double linked list, I just use array to imitate the double linked list
 
 */
class LRUCache{
public:
    unordered_map<int, int> mp; //key -> index
    int N, cnt;
    vector<int> L, R, V, K;
    
    LRUCache(int capacity) {
        N = capacity;
        L.resize (N + 2);
        R.resize (N + 2);
        V.resize (N + 2);
        K.resize (N + 2);
        R[0] = N + 1;
        L[N + 1] = 0;
        cnt = 0;
    }
    
    void update (int key){
        int pos = mp[key];
        // delete the pos
        R[L[pos]] = R[pos];
        L[R[pos]] = L[pos];
        
        // add pos to the end of the link
        L[pos] = L[N + 1];
        R[L[N+1]] = pos;
        R[pos] = N + 1;
        L[N + 1] = pos;
    }
    int get(int key) {
        if (mp.count (key) == 0)    return -1;
        update (key);
        return V[ mp[key] ];
    }
    
    void set(int key, int value) {
        if (mp.count (key) == 0){
            int idx;
            if (cnt == N){
                idx = R[0];
                R[0] = R[idx];
                L[R[idx]] = 0;
                mp.erase (K[idx]);
            }
            else
                idx = ++cnt;
            L[idx] = L[N+1];
            R[L[N+1]] = idx;
            R[idx] = N + 1;
            L[N + 1] = idx;
            V[idx] = value;
            K[idx] = key;
            mp[key] = idx;
        }
        else{
            V[mp[key]] = value;
            update (key);
        }
    }
};
