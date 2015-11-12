class Queue {
public:
    stack<int> stack1, stack2;
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!stack1.empty()){
            int i = stack1.top();
            stack1.pop();
            stack2.push(i);
        }
        stack2.pop();
        while(!stack2.empty()){
            int i = stack2.top();
            stack2.pop();
            stack1.push(i);
        }
    }

    // Get the front element.
    int peek(void) {
        while(!stack1.empty()){
            int i = stack1.top();
            stack1.pop();
            stack2.push(i);
        }
        int result = stack2.top();
        while(!stack2.empty()){
            int i = stack2.top();
            stack2.pop();
            stack1.push(i);
        }
        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stack1.empty();
    }
};