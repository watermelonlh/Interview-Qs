class Solution {
public:
    void part(vector<vector<string>> &ans, vector<string> &tuple, const string &s, const vector<vector<bool> > palind,
    int pos, const int &len)
    {
        if (pos == len)
        {
            ans.push_back(tuple);
            return;
        }
        string tmp = "";
        for (int i = pos; i < len; i++)
        {
            tmp = tmp + s[i];
            if (palind[pos][i])
            {
                tuple.push_back(tmp);
                part(ans, tuple, s, palind, i + 1, len);
                tuple.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        vector<vector<bool> > palind(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                palind[l][r] = true;
                l--, r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                palind[l][r] = true;
                l--, r++;
            }
        }
        vector<vector<string> > ans;
        vector<string> tuple;
        part(ans, tuple, s, palind, 0, len);
        return ans;
    }
};
