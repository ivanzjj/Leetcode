/*
 linear prime search algorithm
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)  return 0;
        char *is_prime = new char[n];
        int *prime = new int[n >> 1];
        int cnt = 0;
        memset (is_prime, 0, sizeof(char)*n);
        is_prime[0] = is_prime[1] = 1;
        for (int i=2;i<n;i++){
            if (is_prime[i] == 0){
                prime[cnt++] = i;
            }
            for (int j=0;j<cnt && i*prime[j]<n;j++){
                is_prime[i * prime[j]] = 1;
                if (i % prime[j] == 0)  break;
            }
        }
        return cnt;
    }
};
