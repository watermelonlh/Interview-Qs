class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = numbers.size();
        vector<pair<int, int> > index(N);
        for (int i = 0; i < N; i++)
            index[i] = pair<int, int>(numbers[i], i + 1);
        sort(index.begin(), index.end(), cmp);
        int l = 0, r = N - 1;
        while (l < r)
        {
            while (l < r && index[l].first + index[r].first < target) l++;
            while (l < r && index[r].first + index[l].first > target) r--;
            if (l < r && index[l].first + index[r].first == target)
            {
                vector<int> tuple(2);
                tuple[0] = index[l].second;
                tuple[1] = index[r].second;
                if (tuple[1] < tuple[0]) swap(tuple[0], tuple[1]);
                return tuple;
            }
        }
    }
};


