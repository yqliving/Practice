/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<pair<vector<NestedInteger>*, int> > s;  
    //嵌套类（Nested Class）是在类中定义的类。以下把拥有内嵌类的类称为外部类。
    vector<NestedInteger>* v;
    int i;
    NestedIterator(vector<NestedInteger> &nestedList) {
        i = 0;
        v = &nestedList;
    }

    int next() {
        return (*v)[i++].getInteger();
    }

    bool hasNext() {
        while(1) {
            if(v->size() <= i) {
                if(s.empty()) return false;
                i = s.top().second;
                v = s.top().first;
                s.pop();
            }else { //v->size() > i
                if(!(*v)[i].isInteger()){ // nested list,
                    s.push(make_pair(v, i+1)); // then save current state  //!!!!!!!! make_pair
                    v = &((*v)[i].getList()); // and go deeper
                    i = 0;
                }else{
                    return true;
                }
            }
        }
    }
};
// 嵌套类可以随意访问外部类的任何数据属性，而外部类访问嵌套类就只能遵守访问修饰符。从这个角度看，嵌套类是外部类的补充，通过嵌套类可以获取更好的封装性，增加外部类的可维护性和可读性。      从程序结构看，嵌套类在逻辑上更加接近使用类。可以更有效地表示类与类之间的紧密程度。为类管理提供除命名空间外的另一种方法。

// std::pair主要的作用是将两个数据组合成一个数据，两个数据可以是同一类型或者不同类型。例如std::pair<int,float> 或者 std：：pair<double,double>等。pair实质上是一个结构体，其主要的两个成员变量是first和second，这两个变量可以直接使用。
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/*
class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

int next() {
    int result = nodes.top().getInteger();
    nodes.pop();
    return result;
}

bool hasNext() {
    while(!nodes.empty()) {
        NestedInteger curr = nodes.top();
        if(curr.isInteger()) {
            return true;
        }
        
        nodes.pop();
        vector<NestedInteger>& adjs = curr.getList();
        int size = adjs.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(adjs[i]);
        }
    }
    
    return false;
    }
};
//The same idea as a DFS, the only tricky part probably is you have to find a value node to claim there is next. And to do that, you have to look through all the nodes in the worst case in the entire graph. So you just keep going until you find a value node; if you can't, there is no next.
