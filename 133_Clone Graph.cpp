/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    typedef pair<UndirectedGraphNode*, UndirectedGraphNode*> PP;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)   return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);

        queue<PP> que;
        que.push ({res,node});
        mp[node] = res;
        UndirectedGraphNode* tmp, *new_tmp, *p;
        
        while (!que.empty ()){
            new_tmp = que.front().first;
            tmp = que.front().second;
            que.pop();
            
            vector<UndirectedGraphNode*> &vec = tmp->neighbors;
            for (int i=0;i<vec.size();i++){
                if (mp.count (vec[i]) == 0){
                    p = new UndirectedGraphNode (vec[i]->label);
                    mp[ vec[i] ] = p;
                    new_tmp->neighbors.push_back (p);
                    que.push ({p, vec[i]});
                }
                else{
                    new_tmp->neighbors.push_back (mp[ vec[i] ]);
                }
            }
        }
        return res;
    }
};