#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, int> s2, t2;

    // Mapping characters of s to their first occurrence index
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (s2.count(c) == 0)
        {
            s2[c] = i;
        }
    }

    // Mapping characters of t to their first occurrence index
    for (int i = 0; i < t.size(); i++)
    {
        char c = t[i];
        if (t2.count(c) == 0)
        {
            t2[c] = i;
        }
    }

    // Compare mapped values of s and t
    for (int i = 0; i < s.size(); i++)
    {
        if (s2[s[i]] != t2[t[i]])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // 0-is false
    // 1-is true
    string s = "eggge";
    string t = "title";
    cout << isIsomorphic(s, t) << endl; 
    return 0;
}
