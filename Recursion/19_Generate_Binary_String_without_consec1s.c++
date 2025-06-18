#include<iostream>
#include<vector>
using namespace std;

void f(int i, string &s, vector<string> &res)
  {
    if(i == s.size())
    {
        bool b=1;
        for(int j=0; j< s.size()-1; j++)
        {
            if(s[j] == '1' && s[j+1] == '1')
            {
                b = 0;
                break;
            }
        }
        if(b) 
        {
            res.push_back(s);
        }
        return;
    }
    s[i] = '0';
    f(i+1,s,res);
    s[i] = '1';
    f(i+1, s, res);
  }
  
    vector<string> generateBinaryStrings(int num) {
        vector<string> res;
        string s(num,'0');
        f(0, s, res);
        return res;
    }

int main() {
    int n = 3;
    vector<string> result = generateBinaryStrings(n);
    for (string &s : result) {
        cout << s << endl;
    }
    return 0;
}