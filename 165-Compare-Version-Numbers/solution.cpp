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