class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        auto n = temperatures.size();
        std::vector<int>res(n);
        std::stack<std::pair<int, int>> stack; //temp, index

        for (auto i{0uz}; i < n; ++i) {
            int temperature = temperatures[i];

            while (!stack.empty() && stack.top().first < temperature) {
                auto [temp, index] = stack.top();
                stack.pop();
                res[index] = i - index;
            }
            stack.push({temperature, i});
        }
        return res;

    }
};
