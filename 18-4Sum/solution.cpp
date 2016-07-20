class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n < 3)
            return ret;

        sort(nums.begin(), nums.end());

        int i = 0, j = 0;
        int left = 0, right = 0, target_3Sum = 0, target_2Sum = 0;

        for (i = 0; i < n-3; i++)
        {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
                
            // 这两行加速效果      
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;

            target_3Sum = target - nums[i];

            //3Sum Problem
            for (j = i + 1; j < n-2; j++)
            {
                if (j != (i+1) && nums[j] == nums[j-1])
                    continue;
                // 这两行加速效果    
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)  break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target)  continue;

                target_2Sum = target_3Sum - nums[j];
                left = j + 1;
                right = n - 1;

                while (left < right)
                {
                    if (nums[left] + nums[right] == target_2Sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ret.push_back(temp);

                        while (left < right && nums[left+1] == nums[left])
                            left++;
                        while (left < right && nums[right-1] == nums[right])
                            right--;

                        left++;
                        right--;
                    }
                    else if (nums[left] + nums[right] < target_2Sum)
                        left++;
                    else
                        right--;
                }
            }
        }

        return ret;
    }
};

//hashtable
/*
class Solution{ //using hashtable, avg O(n^2)
public:
    vector<vector<int> > fourSum(vector<int> &num, int target){
        vector<vector<int> > vvi;
        int n = num.size();
        if(n < 4) return  vvi;
        
        sort(num.begin(), num.end());        
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i>0 && num[i] == num[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && num[j] == num[j-1]) continue;
                int res = target - num[i] - num[j];
                if(mp.count(res)){
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                        int k = (*it).first, l = (*it).second;
                        if(k > j){ // k>j make sure that the second pair has bigger values than the first pair.
                            if(!vvi.empty() && num[i]==vvi.back()[0] && num[j]==vvi.back()[1]
                            && num[k]==vvi.back()[2] && num[l] == vvi.back()[3]){
                                continue; //if the obtained 4 elements are the same as previous one continue to next
                            }
                            vector<int> vi={num[i], num[j], num[k], num[l]};
                            vvi.push_back(vi);
                        } // if k>j
                        
                    }//for it
                }//if
            }// forj
        }//for i
        return vvi;
    }
  };
 