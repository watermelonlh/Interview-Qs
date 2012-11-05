class Solution {
public:
    void ip(string &s, int si, int p, vector<int> &part, vector<string> &ans)
    {
        if (p == 5)
        {
            string sub = s;
            for (int i = 3; i >= 1; i--)
                sub.insert(part[i], ".");
            ans.push_back(sub);
            return;
        }
        int l, r;
        if (p < 4) l = si, r = s.size();
        else l = s.size(), r = s.size() + 1;
        for (int i = l; i < r; i++)
        {
            string sub = s.substr(part[p - 1], i - part[p - 1]);
            stringstream sin;
            sin << sub;
            int num;
            sin >> num;
            if (i - part[p - 1] > 3) break;
            if (num > 255) break;
            if (s[part[p - 1]] == '0' && i - part[p - 1] > 1) break;
            part[p] = i;
            ip(s, i + 1, p + 1, part, ans);
            part[p] = 0;
        }
    
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> part(5, 0);
        vector<string> ans(0);
        ip(s, 1, 1, part, ans);
        return ans;
    }
};
