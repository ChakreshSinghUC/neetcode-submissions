class MinStack {
private:
    stack<int> values;
    stack<int> minimums;

public:
    MinStack() {
    }

    void push(int val) {
        values.push(val);

        if (minimums.empty()) {
            minimums.push(val);
        } else {
            minimums.push(min(val, minimums.top()));
        }
    }

    void pop() {
        values.pop();
        minimums.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minimums.top();
    }
};