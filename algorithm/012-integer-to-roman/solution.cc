class Solution {
public:
    string intToRoman(int num) {
        const string c_str_one          = "I";
        const string c_str_five         = "V";
        const string c_str_ten          = "X";
        const string c_str_fifty        = "L";
        const string c_str_one_hundred  = "C";
        const string c_str_five_hundred = "D";
        const string c_str_one_thousand = "M";
        int int_digit_counter = 0;
        stack<string> stack_str_result;
        string str_result;
        while (num) {
            int int_curr_dig   = num % 10;
            num               /= 10;
            switch (++int_digit_counter) {
                case 1:
                    stack_str_result.push(digitIntToRoman (int_curr_dig, c_str_one, c_str_five, c_str_ten));
                    break;
                case 2:
                    stack_str_result.push(digitIntToRoman (int_curr_dig, c_str_ten, c_str_fifty, c_str_one_hundred));
                    break;
                case 3:
                    stack_str_result.push(digitIntToRoman (int_curr_dig,
                        c_str_one_hundred, c_str_five_hundred, c_str_one_thousand));
                    break;
                case 4:
                    for (int i = 0; i != int_curr_dig; ++i) str_result += c_str_one_thousand;
                    break;
            }
        }
        while (!stack_str_result.empty()) {
            str_result += stack_str_result.top();
            stack_str_result.pop();
        }
        return str_result;
    }
private:
    string digitIntToRoman (const int& c_int_input, const string& one, const string& five, const string& ten) {
        string str_result;
        switch (c_int_input) {
            case 0: break;
            case 1: str_result += one; break;
            case 2: str_result += one; str_result += one; break;
            case 3: str_result += one; str_result += one; str_result += one; break;
            case 4: str_result += one; str_result += five; break;
            case 5: str_result += five; break;
            case 6: str_result += five; str_result += one; break;
            case 7: str_result += five; str_result += one; str_result += one; break;
            case 8: str_result += five; str_result += one; str_result += one; str_result += one; break;
            case 9: str_result += one; str_result += ten; break;
        }
        return str_result;
    }
};
