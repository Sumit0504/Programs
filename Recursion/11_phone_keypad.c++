#include<iostream>
using namespace std;
string key[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
// contact is additional 
string contact[]= {"SUMIT"};
void phone_keypad(string &inp, string &op, int i)
{
    //base
    if(i==inp.size())
    {
        // cout<<op<<endl;
        for(int i=0; i<contact->size(); i++)
        {
            if(contact[i]==op)
            {
                cout<<op<<endl;
            }
        }
        return;
    }
    //recursive
    int digit = inp[i] - '0';
    for(int k=0; k<key[digit].size(); k++)
    {
        char ch = key[digit][k];
        // is ch  ko op me daal denge aur ask recursion
        op.push_back(ch);
        phone_keypad(inp, op, i+1);
        op.pop_back();

    }
}
int main()
{
    string inp="78648", op;
    phone_keypad(inp,op,0);

}