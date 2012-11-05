class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        int n = matrix.size();
        if (n == 0) return ans;
        int m = matrix[0].size();       
        if (m == 0) return ans;
        
        vector<int> h(m, 0), left(m, 0), right(m, 0);
                
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == '1') h[j] += 1;
                else h[j] = 0;
            
            left[0] = 0;
            for (int j = 1; j < m; j++)
            {
                left[j] = j;
                while (left[j] - 1 >= 0 && h[left[j] - 1] >= h[j]) left[j] = left[left[j] - 1];
            }
            right[m - 1] = m - 1;
            for (int j = m - 2; j >= 0; j--)
            {
                right[j] = j;
                while (right[j] + 1 <= m - 1 && h[right[j] + 1] >= h[j]) right[j] = right[right[j] + 1];
            }
            
            for (int j = 0; j < m; j++)
            {
                int sum = (right[j] - left[j] + 1) * h[j];
                if (sum > ans) ans = sum;
            }
        }
        return ans;
    }
};
