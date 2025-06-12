/*A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime.
However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    // Recursive Power Function
    long long recursive_power(long long base, long long exp, long long mod, long long result = 1) {
        if (exp == 0) return result;
        if (exp % 2 == 1) result = (base * result) % mod;
        base = (base * base) % mod;
        return recursive_power(base, exp / 2, mod, result);
    }

    // Iterative Power Function (preferred in competitive programming)
    long long brute_force_power(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (base * result) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_ways = brute_force_power(5, (n + 1) / 2, mod);  // even indices
        long long odd_ways = brute_force_power(4, n / 2, mod);         // odd indices
        return (even_ways * odd_ways) % mod;
    }
};

int main() {
    Solution sol;

    vector<long long> testCases;
    testCases.push_back(1);
    testCases.push_back(2);
    testCases.push_back(3);
    testCases.push_back(4);
    testCases.push_back(5);
    testCases.push_back(50);
    testCases.push_back(100000);

    for (size_t i = 0; i < testCases.size(); ++i) {
        long long n = testCases[i];
        int result = sol.countGoodNumbers(n);
        cout << "Input: " << n << "\nOutput: " << result << "\n\n";
    }

    return 0;
}

