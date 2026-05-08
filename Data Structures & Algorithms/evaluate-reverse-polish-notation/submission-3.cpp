#include <cstring>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        std::stack<int> s;
        
        for (const string& token : tokens) {

            if (token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/") {

                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();

                switch (token[0]) {
                    case '+':
                        s.push(second + first);
                        break;
                    case '-':
                        s.push(second - first);
                        break;
                    case '*':
                        s.push(second * first);
                        break;
                    case '/':
                        s.push(second / first);
                        break;
                } 
            } else {
                s.push(std::stoi(token));
            }
        }

        return s.top();
    }
};
