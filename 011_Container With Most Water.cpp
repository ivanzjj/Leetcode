/*
every index i has its own best choice best_i;
consider [0...i-1] and [j+1...sz-1] have all ready find their best choice
now we consider height[i] and height[j].
if (height[i] < height[j])
	then the best choice of i is j 
	because for all k, satisfy with i<k<j will not be the best choice of i,
	for all k, st k > j, if i's best choice is k, then k's best choice must also be i, 
	now the k's best choice is not i, so i's best choice will not k.
	for all k, st k < i, for the same reason.
	
else
	the best choice if j is i

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size () - 1, ans = 0;
        while (i < j){
            if (height[i] < height[j]){
                ans = max(ans, (j - i) * height[i]);    i++;
            }
            else{
                ans = max(ans, (j - i) * height[j]);    j--;
            }
        }
        return ans;
    }
};