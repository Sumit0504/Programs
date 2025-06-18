#include <iostream>
#include<vector>
using namespace std;

void f(int i, int j, string &s, vector<string> &res, int n)
{
    if(i + j == 2*n)
    {
        res.push_back(s);
        return;
    }
    if(i < n)
    {
        s[i+j] = '(';
        f(i+1,j,s,res, n);
    }
    if(i > j)
    {
        s[i+j] =')';
        f(i,j+1,s,res,n);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string s(2*n,'_');
    f(0,0,s,res,n);
    return res;
}
int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (string &s : result) {
        cout << s << endl;
    }
    return 0;
}