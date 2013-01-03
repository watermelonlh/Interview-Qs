class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = num.size();
        for (int i = N - 1; i >= 0; i--)
        {
            if (!i || num[i - 1] < num[i])
            {
                if (i > 0)
                {
                    for (int j = N - 1; j >= i; j--)
                    {
                        if (num[j] > num[i - 1])
                        {
                            swap(num[j], num[i - 1]);
                            break;
                        }
                    }
                }
                for (int l = i, r = N - 1; l < r; l++, r--)
                {
                    swap(num[l], num[r]);
                }
                break;
            }
        }
    }
};
