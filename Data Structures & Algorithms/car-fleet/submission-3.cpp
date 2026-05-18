class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        auto n = position.size();
        
        std::vector<std::pair<int, int>> cars(n);

        for (auto i{0uz}; i < n; ++i){
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.rbegin(), cars.rend());

        std::vector<double> time;

        for (auto& car : cars) {
            time.push_back(static_cast<double>(target - car.first) / car.second);

            if (time.size() >= 2 && time.back() <= time[time.size() - 2]) {
                time.pop_back();
            }
        }

        return time.size();
    }
};
