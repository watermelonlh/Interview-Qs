class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = num.size();
        int i = N - 1;
        while (i > 0 && num[i - 1] >= num[i]) i--;
        if (i > 0)
        {
            int j = N - 1;
            while (num[j] <= num[i - 1]) j--;
            swap(num[j], num[i - 1]);
        }
        for (int l = i, r = N - 1; l < r; l++, r--)
        {
            swap(num[l], num[r]);
        }
    }
};
