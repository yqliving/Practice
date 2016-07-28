// 第二种的方法
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int citationSize = citations.size();
        if (citationSize < 1) return 0;
        vector<int> record(citationSize + 1, 0);
        for (int i = 0; i < citationSize; ++i)
        {
            if (citations[i] <= citationSize)
                ++record[citations[i]];
            else
                ++record[citationSize];
        }

        for (int j = citationSize, paperNum = 0; j >= 0; --j)
        {
            paperNum += record[j];
            if (paperNum >= j) return j;
        }
        return 0;
    }
};
/*
// 排序+遍历
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](const int &a, const int &b){return a > b; });
        int i = 0;
        for (; i < citations.size(); ++i)
            if (citations[i] <= i)
                break;
        return i;
    }
};

