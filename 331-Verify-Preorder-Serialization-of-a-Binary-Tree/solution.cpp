/*The capacity is the number of node that can be put in the tree. The initial value is 1, which means there can be a root.

When adding a node, capacity--;

When adding a non-NULL node, it means we obtains two more leafs, then capacity +=2.

The final capacity should be equal to 0 */

class Solution {
public:
bool isValidSerialization(string preorder) {
    if (preorder.empty()) return false;
    preorder += ',';
    int idx=0;
    int capacity=1;
    for (idx=0;idx<preorder.size();idx++){
        if (preorder[idx]!=',') continue;
        capacity--;
        if (capacity<0) return false;
        if (preorder[idx-1]!='#') capacity+=2;
    }
    return capacity==0;
}
};