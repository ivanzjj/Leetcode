class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> head (numCourses, vector<int>());
        vector<int> deg (numCourses, 0);
        vector<int> ans;
        for (auto p : prerequisites){
            head[p.second].push_back (p.first);
            deg[p.first]++;
        }
        queue<int> que;
        for (int i=0;i<numCourses;i++) if (deg[i] == 0) que.push (i);
        for (int i=0;i<numCourses;i++){
            if (que.empty()){
                ans.clear (); return ans;
            }
            int now = que.front (); que.pop();
            ans.push_back (now);
            for (auto u : head[now]){
                if (--deg[u] == 0)  que.push (u);
            }
        }
        return ans;
    }
};
