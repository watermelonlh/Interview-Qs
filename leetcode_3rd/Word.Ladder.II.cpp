class Solution {
public:
    void getPath(vector<vector<string> > &result, vector<string> &tuple, vector<string> &que, vector<vector<int> > &pa, int now)
    {
        if (now == -1)
        {
            result.push_back(vector<string>(0));
            for (int i = tuple.size() - 1; i>= 0; i--)
                result.back().push_back(tuple[i]);
            return;
        }
        tuple.push_back(que[now]);
        for (int i = 0; i < pa[now].size(); i++)
            getPath(result, tuple, que, pa, pa[now][i]);
        tuple.pop_back();
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = start.size();
        unordered_map<string, int> hash;
        vector<string> que(0);
        vector<int> step(0);
        vector<vector<int> > pa(0);
        que.push_back(start);
        step.push_back(1);
        pa.push_back(vector<int>(0));
        pa.back().push_back(-1);
        int head = 0;
        hash[start] = 1;
        vector<vector<string> > result(0);
        vector<string> tuple(0);
        tuple.push_back(end);
        int ans = 0;
        while (head < que.size())
        {
            string nowStr = que[head];
            int nowStep = step[head];
            if (ans == 0 || nowStep < ans)
            {
                for (int i = 0; i < len; i++)
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch == nowStr[i]) continue;
                        string nextStr = nowStr;
                        nextStr[i] = ch;
                        int nextStep = nowStep + 1;
                        if (nextStr == end)
                        {
                            ans = nextStep;
                            getPath(result, tuple, que, pa, head);
                        } else if (dict.count(nextStr))
                        {
                            if (hash.count(nextStr) == 0)
                            {
                                que.push_back(nextStr);
                                step.push_back(nextStep);
                                pa.push_back(vector<int>(0));
                                pa.back().push_back(head);
                                hash[nextStr] = que.size();
                            } else
                            {
                                int x = hash[nextStr] - 1;
                                if (step[x] == nextStep) pa[x].push_back(head);
                            }
                        }
                    }
            }
            head++;
        }
        
        return result;
    }
};
