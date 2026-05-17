class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quicksort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            quicksort(nums, low, pivot - 1);
            quicksort(nums, pivot + 1, high); 
        }
    }

    int partition(std::vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[++i], nums[high]);
        return i;
    }


};