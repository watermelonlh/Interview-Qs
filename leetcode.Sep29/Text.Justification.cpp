class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = words.size();
        vector<string> ans(0);
        if (N == 0) return ans;
        for (int i = 0; i < N; i++)
        {
            int j = i;
            int len = 0;
            while (j < N && words[j].size() + len + (j - i) <= L) len += words[j].size(), j++;
            j--;
            string line = "";
            int spaces = L - len;
            int extra = 0;
            int space = 1;
            if (j < N - 1 && j > i)
            {
                space = (L - len) / (j - i);
                extra = (L - len - space * (j - i)) % (j - i);
            }
            for (int k = i; k <= j; k++)
            {
                line += words[k];
                if (k < j)
                {
                    line += string(space, ' ');
                    spaces -= space;
                    if (k - i < extra) line += " ", spaces--;
                }            
            }
            line += string(spaces, ' ');
            ans.push_back(line);
            i = j;
        }
    }
};
