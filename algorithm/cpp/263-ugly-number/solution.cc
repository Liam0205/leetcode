class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;

        vector<int> primes;
        primes.push_back(2); primes.push_back(3); primes.push_back(5);

        for (auto prime : primes) {
            while (num % prime == 0) {
                num /= prime;
            }
        }

        return (num == 1);
    }
};
