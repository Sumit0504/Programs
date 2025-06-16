#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Helper function to insert an element at the bottom of the stack
    void insert_at_bottom(stack<int>& s, int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        insert_at_bottom(s, x);
        s.push(temp);
    }

    // Function to reverse the stack using recursion
    void reverseStack(stack<int>& s) {
        if (s.empty()) return;

        int topElement = s.top();
        s.pop();
        reverseStack(s);
        insert_at_bottom(s, topElement);
    }
};

int main() {
    Solution sol;
    stack<int> s;

    // Push elements to the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // Reverse the stack
    sol.reverseStack(s);

    // Print reversed stack
    cout << "Reversed Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
