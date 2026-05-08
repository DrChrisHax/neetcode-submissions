class Solution {
public:
    bool isValid(string str) {
        std::stack<char> s;

        for (const auto c : str) {

            switch(c) {
                case '(':
                case '{':
                case '[':
                    s.push(c);
                    break;

                case ')':
                    if (!s.empty() && s.top() == '(') { s.pop(); } 
                    else { return false; }
                    break;
                
                case ']' :
                    if (!s.empty() && s.top() == '[') { s.pop(); }
                    else { return false; }
                    break;

                case '}':
                    if (!s.empty() && s.top() == '{') { s.pop(); }
                    else { return false; }
                    break;
            }
        }

        return s.empty();
    }
};
