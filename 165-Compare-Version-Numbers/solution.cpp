class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1len = version1.size(), v2len = version2.size();
        for (int i = 0, j = 0; (i < v1len || j < v2len); i++, j++ ) {
        	long long a = 0, b =0;
        	while (i < v1len && version1[i] != '.') {
        		a = a * 10 + version1[i++] - '0';
        	}
        	
        	while (j < v2len && version2[j] != '.') {
        		b = b * 10 + version2[j++] - '0';
        	}
        	
        	if (a > b) return 1;
        	if (a < b) return -1;
        }
    	return 0;
    }
};

/*以小数点为分隔符，先取出最前面的数字部分，并转换成整数。

如果两个版本对应的整数不等，则直接给出比较结果。
如果两个版本对应的整数相等，那就再比较版本后面的部分

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        while (!version1.empty() || !version2.empty())
        {
            auto ver1 = version1.empty() ? 0 : stoi(version1);
            auto ver2 = version2.empty() ? 0 : stoi(version2);
            if (ver1 < ver2)
            {
                return -1;
            }
            else if (ver1 > ver2)
            {
                return 1;
            }
            else
            {
                auto pos1 = version1.find('.');
                version1 = (pos1 == string::npos) ? "" : version1.substr(pos1 + 1);
                auto pos2 = version2.find('.');
                version2 = (pos2 == string::npos) ? "" : version2.substr(pos2 + 1);
            }
        }
        return 0;
    }
};