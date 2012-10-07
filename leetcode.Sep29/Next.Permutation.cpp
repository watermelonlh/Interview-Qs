class Solution {
public:
    void rotate(vector<int> &num, int l, int r)
    {
        int mid = (r - l + 1) / 2;
        for (int i = 0; i < mid; i++)
        {
            swap(num[l + i], num[r - i]);
        }
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int right = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (num[right] > num[i])
            {
                for (int k = n - 1; k > i; k--)
                    if (num[k] > num[i])
                    {
                        swap(num[k], num[i]);
                        rotate(num, i + 1, n - 1);
                        return;
                    }
            } else right = i;
        }
        rotate(num, 0, n - 1);
    }
};
