class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> res;
        res.resize(n);
		for (int i = 0; i != n; ++i) {
            int j = i + 1;
            const bool three = 0 == j % 3, five = 0 == j % 5;
            if (three and five) {
                res[i] = "FizzBuzz";
            } else if (three) {
                res[i] = "Fizz";
            } else if (five) {
                res[i] = "Buzz";
            } else {
                res[i] = std::to_string(j);
            }
        }
        return res;
    }
};

