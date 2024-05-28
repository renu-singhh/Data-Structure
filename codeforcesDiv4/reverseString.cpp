#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st; // Initialize an empty stack
        s += " ";         // Add a space at the end to ensure the last word is processed
        string str = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (!str.empty())
                {
                    st.push(str); // Push the word into the stack
                    str = "";     // Reset the current word
                }
            }
            else
            {
                str += s[i]; // Constructing an individual word
            }
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top(); // Pop words from the stack and append them to the answer string
            st.pop();
            if (!st.empty())
            {
                ans += " "; // Add a space between words
            }
        }

        return ans; // Return the reversed string
    }
};

int main()
{
    Solution solution;
    string s = "TUF is great for interview preparation";
    string reversed = solution.reverseWords(s);
    cout << "After reversing words:" << endl;
    cout << reversed << endl;
    return 0;
}

// ------------------------optimal solution--------------------------------------------------------\\

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // Reverse the entire string
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        while (i < n)
        {
            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;

            // Copy the word to the right position
            while (i < n && s[i] != ' ')
            {
                s[right++] = s[i++];
            }

            // Reverse the word
            reverse(s.begin() + left, s.begin() + right);

            // Add a space after the word
            s[right++] = ' ';
            left = right;
            i++;
        }

        // Resize to remove the last extra space
        if (right > 0)
        {
            s.resize(right - 1);
        }
        else
        {
            s.resize(0);
        }

        return s;
    }
};

int main()
{
    Solution solution;
    string input = "  the sky is blue  ";
    string result = solution.reverseWords(input);
    cout << "Reversed words: '" << result << "'" << endl;

    return 0;
}
