class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack_int_input.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        inputOutputSync();
        stack_int_output.pop();
    }

    // Get the front element.
    int peek(void) {
        inputOutputSync();
        return stack_int_output.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (stack_int_input.empty() && stack_int_output.empty());
    }
private:
    stack<int> stack_int_input, stack_int_output;
    void inputOutputSync () {
        if (!stack_int_output.empty()) return;
        while (!stack_int_input.empty()) {
            stack_int_output.push(stack_int_input.top());
            stack_int_input.pop();
        }
    }
};
