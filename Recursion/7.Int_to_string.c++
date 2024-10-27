
#include <iostream>
#include<string>
using namespace std;
string s[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void int_to_string(int N)
{   if(N==0)
    {
        return;
    }
    
    int digit = N%10;
    N = N/10;
    int_to_string(N);
    cout<<s[digit]<<" ";
}
int main() {
    
    int N;
    cin>>N;
    int_to_string(N);
    return 0;
}