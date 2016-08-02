/*THE KEY POINTS

idx is some index of BIT. r is a position in idx of the last digit 1 (from left to right) in binary notation. tree[idx] is sum of frequencies from index (idx – 2^r + 1) to index idx (look at the Table 1.1 for clarification). We also write that idx is responsible for indexes from (idx - 2^r + 1) to idx (note that responsibility is the key in our algorithm and is the way of manipulating the tree).

FOR EXAMPLE

Suppose we are looking for cumulative frequency of index 13 (for the first 13 elements). In binary notation, 13 is equal to 1101. Accordingly, we will calculate

  c[1101] = tree[1101] + tree[1100] + tree[1000] 
HOW TO GET THE FINAL LAST SET BIT

There are times when we need to get just the last digit from a binary number, so we need an efficient way to do that. Let num be the integer whose last digit we want to isolate. In binary notation num can be represented as a1b, where a represents binary digits before the last digit and b represents zeroes after the last digit.

 num=a1b

-num= (a1b)¯ + 1 = a¯0b¯ + 1

-num = (a1b)¯ + 1 = a¯0b¯ + 1 = a¯0(0…0)¯ + 1 = a¯0(1…1) + 1 = a¯1(0…0) = a¯1b.
b consists of all zeroes, so b¯ consists of all ones. Finally we have

so the last set bit  :  00..1...00 = num & -num
Key ideas -1-
get-function-details

getSum(index): Returns sum of arr[0..index]

// Returns sum of arr[0..index] using BITree[0..n].  It assumes that

// BITree[] is constructed for given array arr[0..n-1]

 1) Initialize sum as 0 and index as index+1.

 2) Do following while index is greater than 0.

  ...a) Add BITree[index] to sum

  ...b) Go to parent of BITree[index].  Parent can be obtained by removing

         the last set bit from index, i.e., index = index - (index & (-index))

 3) Return sum.
Key ideas -2- update-value-function

   update(index, val): Updates BIT for operation arr[index] += val

   // Note that arr[] is not changed here.  It changes

  // only BI Tree for the already made change in arr[].

   1) Initialize index as index+1.

   2) Do following while index is smaller than or equal to n.

      ...a) Add value to BITree[index]

      ...b) Go to parent of BITree[index].  Parent can be obtained by removing

             the last set bit from index, i.e., index = index + (index & (-index))
*/
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sz = nums.size();
        num = vector<int>(sz+1, 0);
        sum = vector<int>(sz+1, 0);
        for(int i=0; i<sz; i++) {
            update(i, nums[i]);
        }
        
    }

    void update(int idx, int val) {
        int oldv = num[idx+1];
        for(int i = idx+1; i<=sz; i+= (i&-i)) {
            sum[i] = sum[i] - oldv + val;
        }
        num[idx+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
    
    int getSum(int idx) {
        int ret = 0;
        for(int i=idx; i>0; i-=(i&-i)) {
            ret += sum[i];
        }
        return ret;
    }
private :
    int sz;
    vector<int> num;
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);