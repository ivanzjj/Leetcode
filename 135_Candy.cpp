/*
firstly, we give all children one candy
in this situation, some children did not follow condition 2
we can adjust as follow:
adjust children i's candy so that if ratings[i] > ratings[i-1] 
then candy[i] = candy[i-1] + 1
then adjust children i's candy so that if ratings[i] < ratings[i+1]
then candy[i] = max (candy[i], candy[i+1]+1);
the minimum candy needed is SUM{candy[i]}
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size ();
        vector<int> candy(N,-1);
        int cnt = 1;
        candy[0] = cnt++;
        for (int i=0;i<N-1;i++){
            if (ratings[i] < ratings[i+1]){
                candy[i+1] = cnt++;
            }
            else{
                candy[i+1] = 1; cnt = 2;
            }
        }
        for (int i=N-2;i>=0;i--){
            if (ratings[i] > ratings[i+1]){
                candy[i] = max (candy[i], candy[i+1]+1);
            }
        }
        int ans = 0;
        for (int i=0;i<N;i++)   ans += candy[i];
        return ans;
    }
};