class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++)
    {
        if ((char)toupper(s[i]) >= 'A' && (char)toupper(s[i]) <= 'Z')
        {
            continue;
        }
        else if ((char)toupper(s[i]) >= '0' && (char)toupper(s[i]) <= '9')
        {
            continue;
        }
        else
        {
            s.erase(i, 1);
            i--;
        }
    }

    cout << s << endl;
    int j = s.size() - 1;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if ((char)toupper(s[i]) == (char)toupper(s[j]))
        {
            j--;
        }
        else
        {
            return false;
        }
    }

    return true;
    }
};
