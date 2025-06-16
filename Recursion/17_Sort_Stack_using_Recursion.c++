/*
Time Complexity: O(N^2)  
    - For each element, we may need to move it through all the elements in the stack.

Space Complexity: O(N)
    - Due to recursion call stack in worst case (all N elements pushed deep).

This code sorts a stack in ascending order (smallest element at bottom, largest at top)
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Inserts an element into a sorted stack in the correct position
    void insert_n_sort(stack<int>& s, int x) {
        if (s.empty() || x > s.top()) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        insert_n_sort(s, x);
        s.push(temp);
    }

    // Recursively pops all elements, sorts them back using insert_n_sort
    void sortStack(stack<int>& s) {
        if (s.empty()) return;

        int topElement = s.top();
        s.pop();
        sortStack(s);
        insert_n_sort(s, topElement);
    }
};

int main() {
    Solution sol;
    stack<int> s;

    // Initial stack: Top -> 11, 2, 32, 3, 41
    s.push(41);
    s.push(3);
    s.push(32);
    s.push(2);
    s.push(11);

    // Sort the stack
    sol.sortStack(s);

    // Print the sorted stack: should be 11 2 3 32 41 (from top to bottom)
    cout << "Sorted Stack (Top to Bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
