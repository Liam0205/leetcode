class Solution {
public:
    int myAtoi(string str) {
        int len    = str.size();
        int pmFlag = 1; // postive == 1, negtive = -1
        int result = 0;
        // find the fist chat not ' '
        int working = 0;
        for (; working != len; ++working){
            if (str[working] != ' ') {
                if (str[working] == '+') {
                    ++working;
                }
                else if (str[working] == '-') {
                    pmFlag = -1;
                    ++working;
                }
                break;
            }
        }
        for (; working != len; ++working) {
            // cout << "This is the " << working << "-th round" << endl;
            if (str[working] < '0' || str[working] > '9') {
                break;
            }
            int temp = str[working] - '0';
            cout << "digit: " << temp << "\t";
            if (pmFlag == 1  && (result > (int) (INT_MAX / 10) || (result == (int) (INT_MAX / 10) && temp > 7))) {
                // cout << "INT_MAX detected!\t";
                result = INT_MAX; break;
            } else if (pmFlag == -1 && (result < (int) (INT_MIN / 10) || (result == (int) (INT_MIN / 10) && temp > 7))) {
                // cout << "INT_MIN detected!\t";
                result = INT_MIN; break;
            }
            result = 10 * result + pmFlag * temp;
            cout << "result: " << result << endl;
        }
        return result;
    }
};
