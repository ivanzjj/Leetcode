class Solution {
public:
    typedef long long LL;
    
    string fractionToDecimal(int numerator, int denominator) {
        LL x = numerator, y = denominator;
        if (x == 0) return "0";
        int sgn = 1;
        if (x < 0) x = -x, sgn = -sgn;
        if (y < 0) y = -y, sgn = -sgn;
        ostringstream out;
        if (sgn == -1)  out << "-";
        out << x / y;
        LL left = x - x / y * y;
        if (left == 0)  return out.str ();
        vector<int>vec;
        unordered_map<LL,int> mp;
        mp[left] = 0;
        int last = -1;
        out << ".";
        
        while (left != 0){
            left *= 10;
            vec.push_back (left / y);
            left = left - left/y*y;
            if (mp.find(left) != mp.end()){
                last = mp[left];
                break;
            }
            mp[left] = vec.size ();
        }
        for (int i=0;i<vec.size();i++){
            if (last == i)  out << "(";
            out << vec[i];
        }
        if (last != -1) out << ")";
        return out.str ();
    }
};
