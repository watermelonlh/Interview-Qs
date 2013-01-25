class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = L.size();
        vector<int> ans;
        if (N == 0) return ans;
        int len = L[0].size();
        int lenS = S.size();
        map<string, int> countL;
        for (int i = 0; i < N; i++) countL[L[i]]++;
        for (int i = 0; i < len && i + len * N <= lenS; i++)
        {
            int l = i, r = i;
            int matched = 0;
            for (int k = 0; k < N; k++, r += len)
            {
                string sub = S.substr(r, len);
                countL[sub]--;
                if (countL[sub] >= 0) matched++;
            }
            if (matched == N) ans.push_back(i);
            while (r + len <= lenS)
            {
                string sub = S.substr(l, len);
                countL[sub]++;
                if (countL[sub] > 0) matched--;
                sub = S.substr(r, len);
                countL[sub]--;
                if (countL[sub] >= 0) matched++;
                l += len, r += len;
                if (matched == N) ans.push_back(l);
            }
            while (l <= r)
            {
                string sub = S.substr(l, len);
                countL[sub]++;
                if (countL[sub] > 0) matched--;
                l += len;
            }
        }
        return ans;
    }
};
