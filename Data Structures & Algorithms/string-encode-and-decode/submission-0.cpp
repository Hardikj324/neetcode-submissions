

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encoded_word = "";

        for (int i = 0; i < strs.size(); i++)
        {
            {

                for (int j = 0; j < strs[i].size(); j++)
                {
                    int ascii = (int)strs[i][j];

                    encoded_word += (char)ascii + 20;
                }

                encoded_word += " ";
            }
        }
        return encoded_word;
    }

    vector<string> decode(string s)
    {
        vector<string> strs;
        string decoded_word = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                strs.push_back(decoded_word);
                decoded_word = "";
            }
            else
            {
                int ascii = (int)s[i];
                decoded_word += (char)ascii - 20;
            }
        }
        return strs;
    }
};

