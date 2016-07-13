public class Solution {
    public int lengthOfLongestSubstring(String s) {
    int ret = 0;
    Map<Character, Integer> map = new HashMap<>();
    for (int i = 0, start = 0; i < s.length(); i++) {
        char c = s.charAt(i);
        if (map.containsKey(c)) 
            start = Math.max(map.get(c)+1, start);
        ret = Math.max(ret, i-start+1); 
        map.put(c, i);
    }
    return ret;
}
}// 20 ms 


/*The idea is almost the same with a Hashmap solution, which costs about 20ms. 
To speed up,1) replace Hashmap with an array, and the index is the int value of its asicii code. 
            2) use char array instead of string.
            
public class Solution {
    public int lengthOfLongestSubstring(String s) {
    int[] map = new int[128];
    int max = 0, j = 0;
    char[] str = s.toCharArray();
    int length = s.length();

    for(int i = 0; i < length; i++) {
        if(map[str[i]] > 0)
            j =  Math.max(j, map[str[i]]);
        map[str[i]] = i + 1;
        max = Math.max(max, i - j + 1);
    }
    return max;
    }
}
    
    
/* 5 ms
 */