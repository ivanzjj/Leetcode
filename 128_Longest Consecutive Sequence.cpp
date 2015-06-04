/*
for every integer, we keep track two variable L[i] and R[i]
the L[i] is the max consecutive sequence length to left
and R[i] is to right

for every new value x;
if x has appeared, ignore it
otherwise 
	using L[x-1] update L[x], and R[x+1] update R[x];
	if necessary update R[x - L[x-1]] and L[x + R[x+1]] 
*/
/*
retrieve element's time complexity of map is O(logN), because elements is ordered
retrieve element's time complexity of unordered_map is O(1), because it is actually a hash_map
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> l, r;
        int ans = 0;
        for (auto a : nums){
            if (l[a] != 0)   continue;
            l[a] = l[a - 1] + 1;
            r[a] = r[a + 1] + 1;
            ans = max (ans, l[a] + r[a] - 1);
            if (l[a - 1] != 0) r[a - l[a - 1]] += r[a];
            if (r[a + 1] != 0) l[a + r[a + 1]] += l[a];
        }
        return ans;
    }
};