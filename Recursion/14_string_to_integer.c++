
/*Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain
 in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.

Return the integer as the final result.
*/

#include <iostream>
#include <string>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public:
    int recursive_my_Atoi(string s, int i, long long ans, int sign, bool dig_set, bool sign_set)
    {
        if(i>=s.size())
        {
            return (int) ans*sign;
        }
        if(s[i]==' '&& !dig_set && !sign_set)
        {
            return recursive_my_Atoi(s, i+1, ans, sign, dig_set, sign_set);
        }
        if((s[i]=='+' || s[i]=='-') && !dig_set && !sign_set)
        {
            sign  = (s[i]=='-') ? -1 : 1;
            return recursive_my_Atoi(s,i+1, ans, sign, dig_set, 1);
        }
        if(isdigit(s[i]))
        {
            dig_set = 1;
            ans = ans * 10 + (s[i]-'0');
            if (sign * ans <= INT_MIN) return INT_MIN;
            if (sign * ans >= INT_MAX) return INT_MAX;
            return recursive_my_Atoi(s,i+1, ans, sign, dig_set, sign_set);
        }
        return (int) ans*sign;
    }
    int brute_force_myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int i = 0;

        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;

        // Handle sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Convert digits
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Clamp to 32-bit signed integer range
            if (sign * ans <= INT_MIN) return INT_MIN;
            if (sign * ans >= INT_MAX) return INT_MAX;

            i++;
        }

        return (int)(sign * ans);
    }
};

int main() {
    Solution sol;

    // Test cases like in LeetCode
    vector<string> testCases;
testCases.push_back("42");
testCases.push_back("   -42");
testCases.push_back("4193 with words");
testCases.push_back("words and 987");
testCases.push_back("-91283472332");
testCases.push_back("+1");
testCases.push_back("00000-42a1234");
testCases.push_back("  +0 123");
testCases.push_back("-2147483648");
testCases.push_back("2147483648");


    for (int j = 0; j < testCases.size(); ++j) 
    {
        cout << "Input: \"" << testCases[j] << "\"\n";
        int result = sol.brute_force_myAtoi(testCases[j]);
        cout << "Output: " << result << "\n\n";
    }

    cout<<endl<<"Recursive: ";
    for (int j = 0; j < testCases.size(); ++j) 
    {
        cout << "Input: \"" << testCases[j] << "\"\n";
        int result = sol.recursive_my_Atoi(testCases[j],0,0,1,0,0);
        cout << "Output: " << result << "\n\n";
    }


    return 0;
}
