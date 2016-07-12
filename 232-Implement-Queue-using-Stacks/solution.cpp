class Queue {
public:
stack<int> s;
stack<int> sub;

void aStackb(stack<int>& a, stack<int>& b)
{
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
}

// Push element x to the back of queue.
void push(int x) {
    aStackb(s, sub);
    s.push(x);
    aStackb(sub, s);
}

// Removes the element from in front of queue.
void pop(void) {
    s.pop();
}

// Get the front element.
int peek(void) {
    return s.top();
}

// Return whether the queue is empty.
bool empty(void) {
    return s.empty();
}
};

//Keep stack1 as the queue
//Use two Stacks: push new elements to stack1, and pop old elements from stack2; if stack2 become empty, pop all the elements in stack1 to stack2.