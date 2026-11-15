class Solution {
public:
 bool isValid(string s)
{
    stack<char> characters;
    if (s.size() % 2 != 0)
    {
        return false;
    }
    for (char ch : s)
    {
        if (ch == '[' || ch == '{' || ch == '(')
        {
            characters.push(ch);
        }
        else
        {
            if (characters.empty())
                return false;
            char top = characters.top();
            if (ch == ')' && top == '(' ||
                ch == '}' && top == '{' ||
                ch == ']' && top == '[')
            {
                characters.pop();
            }

            else
            {
                return false;
            }
            {
            }
        }
    }

    if (!(characters.empty()))
    {
        return false;
    }
    return true;
}
};
