class Solution {
public:
 bool isValid(string s)
{
    stack<char> characters;

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

    if (!(characters.empty()) || s.size() % 2 != 0)
    {
        return false;
    }
    return true;
}
};
