class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = L.size();
        vector<int> ans;
        if (L.size() == 0) return ans;
        int len = L[0].size();
        int ls = S.size();
        if (len * N > ls) return ans;
        vector<bool> mark(ls, false);
        map<string, int> dict, ocur;
        for (int i = 0; i < N; i++)
            dict[L[i]]++;
        for (int i = 0; i < len && i + N * len <= ls; i++)
        {
            int j = i;
            int tot = 0;
            for (int k = 0; k < N; k++, j += len)
            {
                string sub = S.substr(j, len);
                if (dict[sub] >= 1) 
                {
                    ocur[sub]++;
                    if (ocur[sub] <= dict[sub]) tot++;
                }
            }
            for (int k = i; k < ls; j += len, k += len)
            {
                if (tot == N) mark[k] = true;
                string sub = S.substr(k, len);
                if (dict[sub] >= 1) 
                {
                    ocur[sub]--;
                    if (ocur[sub] < dict[sub]) tot--;
                }
                if (j + len <= ls) 
                {
                    sub = S.substr(j, len);
                    if (dict[sub] >= 1)
                    {
                        ocur[sub]++;
                        if (ocur[sub] <= dict[sub]) tot++;
                    }
                }
            }
        }
        for (int i = 0; i < ls; i++) 
            if (mark[i]) ans.push_back(i);
        return ans;
    }
};
