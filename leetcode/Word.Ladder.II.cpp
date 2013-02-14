class Solution {
public:
    void getPath(vector<vector<string> > &ansSet, vector<string> &ans, int now, vector<vector<int> > &pa, vector<string> &que)
    {
        if (now == -1) 
        {
            ansSet.push_back(vector<string>(0));
            for (int i = ans.size() - 1; i >= 0; i--)
                ansSet.back().push_back(ans[i]);
            return;
        }
        for (int i = 0; i < pa[now].size(); i++)
        {
            ans.push_back(que[now]);
            getPath(ansSet, ans, pa[now][i], pa, que);
            ans.pop_back();
        }
        
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> que;
        vector<int> step;
        vector<vector<int> > pa;
        unordered_map<string, int> hash;
        step.push_back(1);
        que.push_back(start);
        pa.push_back(vector<int>(0));
        pa.back().push_back(-1);
        int head = 0;
        int bestStep = -1;
        vector<vector<string> > ans;
        while (head < que.size())
        {
            string now = que[head];
            int nowStep = step[head];
            if (bestStep > -1 && nowStep == bestStep) break;
            for (int i = 0; i < now.size(); i++)
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    string next = now;
                    if (next[i] == ch) continue;
                    next[i] = ch;
                    if (next == end)
                    {
                        bestStep = nowStep + 1;
                        vector<string> single(0);
                        single.push_back(end);
                        getPath(ans, single, head, pa, que);
                    } else if (dict.count(next))
                    {
                        if (hash[next] == 0)
                        {
                            que.push_back(next);
                            step.push_back(nowStep + 1);
                            pa.push_back(vector<int>(0));
                            pa.back().push_back(head);
                            hash[next] = pa.size() - 1;
                        } else if (step[hash[next]] == nowStep + 1)
                        {
                            pa[hash[next]].push_back(head);
                        }
                    }
                }
            head++;
        }
        return ans;
    }
};
