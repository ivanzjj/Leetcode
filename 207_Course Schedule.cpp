class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int *head = new int[numCourses];
        int edge_num = prerequisites.size ();
        int *nxt = new int[edge_num + 10];
        int *node = new int[edge_num + 10];
        int *deg = new int[numCourses];
        int cnt = 0;
        fill_n (head, numCourses, -1);
        fill_n (deg, numCourses, 0);
        
        for (auto p : prerequisites){
            nxt[cnt] = head[p.first], node[cnt] = p.second; head[p.first] = cnt++;
            deg[p.second]++;
        }
        int *que = new int[numCourses];
        int front = 0 ,rear = 0;
        
        for (int i=0;i<numCourses;i++) if (deg[i] == 0) que[rear++] = i;
        
        for (int i=0;i<numCourses;i++){
            if (front == rear)    return false;
            int now = que[front++];
            for (int j=head[now];j!=-1;j=nxt[j]){
                int u = node[j];
                if (--deg[u] == 0)  que[rear++] = u;
            }
        }
        return true;
    }
};
