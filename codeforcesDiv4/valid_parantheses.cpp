#include <iostream>
#include <stack>
using namespace std;

string removeOuterParentheses(string s)
{
    string answer = "";
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (!st.empty())
            {
                answer += s[i];
            }
            st.push('(');
        }
        else if (s[i] == ')')
        {
            st.pop();
            if (!st.empty())
            {
                answer += s[i];
            }
        }
    }

    return answer;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl;
    return 0;
}
