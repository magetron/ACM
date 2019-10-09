class MyStack {
public:
    queue<int> q;

	/** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
		q.push(x);
		for (int i = 0; i < q.size() - 1; i++) {
			int val = q.front();
			q.pop();
			q.push(val);
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int val = q.front();
		q.pop();
		return val;
    }
    
    /** Get the top element. */
    int top() {
		return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return q.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
