class Solution {
public:
    bool canWinNim(int n) {
        if (!(n > 0)) {
            return false;
        }
        return (n & 0b11);
    }
};
