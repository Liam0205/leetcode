class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        if(!str.size()) return 0;
        stringstream tempSStream;
        tempSStream << str;
        tempSStream >> result;
        return result;
    }
};
