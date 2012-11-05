
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1) return s;           // when nRows == 1, will not fit the discipline
        string ans = "";
        int l = s.size();
        int sum = 2 * (nRows - 1);
        for (int i = 0; i < nRows && i < l; i++)
        {
            int step = i * 2;   // ATTENTION: the first step is (sum - step), but this will calc in the for-loop
            if (step == 0) step = sum;
            for (int j = i; j < l; j += step)
            {
                ans = ans + s[j];
                if (step < sum) step = sum - step;
            }
        }
        return ans;
    }
};
