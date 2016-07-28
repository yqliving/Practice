// 首先想到的是将数组进行排序，然后从后往前遍历，找出这个h值，该方法的复杂度是：O(n*logn)。
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


// 第二种的方法
// 在面试中，若允许使用辅助内存，可以使用第二种方法，即开辟一个新数组record，用于记录0~N次引用次数的各有几篇文章（引用次数大于N的按照N次计算）遍历数组，统计过后，遍历一次统计数组record，即可算出h值的最大值。时间复杂度为O(n)。
/*
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

