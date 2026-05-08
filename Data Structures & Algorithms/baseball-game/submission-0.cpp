class Solution {
public:
    int calPoints(vector<string>& operations) {

        std::stack<int> record;
        
        for (const auto& s : operations) {

            switch (s[0]) {
                case '+':
                {
                    int first = record.top();
                    record.pop();
                    int second = record.top();
                    record.push(first);
                    record.push(first + second);
                    break;
                }
                case 'D':
                {
                    record.push(record.top() * 2);
                    break;
                }
                case 'C':
                {
                    record.pop();
                    break;
                }
                default:
                {
                    int val = std::stoi(s);
                    record.push(val);
                    break;
                }
            }
        }

        int sum = 0;
        while (!record.empty()) {
            sum += record.top();
            record.pop();
        }

        return sum;

    }
};