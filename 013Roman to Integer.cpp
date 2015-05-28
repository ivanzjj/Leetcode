class Solution {
public:
    int romanToInt(string s) {
        int ref [300];
        ref['I'] = 1; ref['V'] = 5; ref['X'] = 10; ref['L'] = 50; ref['C'] = 100, ref['D'] = 500; ref['M'] = 1000;
        int res = 0;
        for (int i=0,sz=s.length ();i<sz;i++){
            if (i == sz-1)  res += ref[ s[i] ];
            else{
                if (ref[ s[i] ] < ref[ s[i+1] ]){
                    res += ref[ s[i+1] ] - ref[ s[i] ]; i++;   
                }
                else{
                    res += ref[ s[i] ];
                }
            }
        }
        return res;
    }
};