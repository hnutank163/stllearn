#include "Stack.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "string"
using namespace std;

template<class intype, class outtype>
outtype convert(const intype &in)
{
    stringstream stream;
    stream<<in;
    outtype ret;
    stream >> ret;

    return ret;
}

bool isOperator(string &s)
{
    if( s=="+" || s=="-" || s=="/" || s=="*")
        return true;
    return false;
}

double calc(double val1, double val2, string op)
{
    char ch = op[0];
    double ret = 0;
    switch (ch) {
        case '+':
            ret = val1 + val2;
            break;
        case '-':
            ret = val1 - val2;
            break;
        case '*':
            ret = val1 * val2;
            break;
        case '/':
            ret = val1 / val2;
            break;
        default:
            break;
    }

    return ret;
}

string  reverse_polish(string *s, int n)
{
    Stack <string> st;
    double val1, val2;
    string tmp;
    for (int i = 0; i < n; ++i) {
        if( isOperator(s[i]) )
        {
            val1 = convert<string, double>(st.top());
            st.pop();
            val2 = convert<string, double>(st.top());
            st.pop();
            st.push( convert<double, string>(calc(val1, val2, s[i])) );
        }
        else
            st.push(s[i]);
    }

    return st.top();
}

int
main()
{
    string s[] = {"6","5","2","3","+","8","*","+","3","+","*"};
    cout<<reverse_polish(s, 11)<<endl;
}

