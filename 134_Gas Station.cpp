class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size ();
        vector<int> nxt(sz, 0);
        for (int i=0;i<sz-1;i++)  nxt[i] = i+1;
        nxt[sz-1] = 0;
        for (int s=0,e,j;s<sz;){
            int left = gas[s];
            for (e=s,j=0;j<sz;j++){
                if (left < cost[e]) break;
                left = left - cost[e] + gas[ nxt[e] ];
                e = nxt[e];
            }
            if (j == sz)    return s;
            if (j == sz-1)  return -1;
            s += j + 1;
        }
        return -1;
    }
};

/*
we generate a new array diff, the value of diff[i] = gas[i] - cost[i]
let sum[i] = SUM{diff[k]}, k=0...i 
then the problem become whether we can find a index x, such that sum[(x + i)%len] >= 0 for all i=0...len-1
if sum[len-1] < 0 
	then there is no answer obviously
otherwise
	there will always have answer
	for proof detail
	the start pointe is idx + 1, where idx = min{sum[k]},k=0...len-1 
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, sz = gas.size ();
        int _min = INT_MAX, idx = -1;
        for (int i=0;i<sz;i++){
            sum += gas[i] - cost[i];
            if (sum < _min){
                _min = sum;
                idx = i;
            }
        }
        if (sum < 0)    return -1;
        return (idx + 1) % sz;
    }
};