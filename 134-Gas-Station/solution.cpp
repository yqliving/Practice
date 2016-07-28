/*The idea is to keep track of how much gas we are carrying as we enter each city. When a complete circuit is made, if the amount we're carrying is less than 0, making a circuit without running out of gas is impossible (the route takes more gas than it provides overall). However, if the carry is nonnegative at the end, the route is possible, so we just need to know where to start: we should start where the carry amount was at a minimum, because it will never be less than that on the rest of the route.*/

/*class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int carry = 0;
        pair<size_t, int> city_carry(0, 0);
        for (size_t i = 1; i < gas.size(); ++i) {
            carry += gas[i - 1] - cost[i - 1];
            if (carry < city_carry.second) {
                city_carry = {i, carry};
            }
        }
        carry += gas[gas.size()-1] - cost[gas.size()-1];
        return carry >= 0 ? city_carry.first : -1;
    }
};

//====================
/*I have thought for a long time and got two ideas:

If car starts at A and can not reach B. Any station between A and B
can not reach B.(B is the first station that A can not reach.)
If the total number of gas is bigger than the total number of cost. There must be a solution.
(Should I prove them?)
Here is my solution based on those ideas:
// 相当于找最大子序列
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++) 
            if((tank=tank+gas[i]-cost[i])<0) {
                start = i+1;
                total += tank;
                tank=0;
            }
        return (total + tank < 0) ? -1 : start;
    }
};