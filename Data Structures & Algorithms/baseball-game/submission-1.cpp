class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (const string& operation : operations) {
            if (operation == "+") {
                int last = st.top();
                st.pop();

                int secondLast = st.top();

                st.push(last);
                st.push(last + secondLast);
            }
            else if (operation == "D") {
                st.push(2 * st.top());
            }
            else if (operation == "C") {
                st.pop();
            }
            else {
                st.push(stoi(operation));
            }
        }

        int total = 0;

        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};