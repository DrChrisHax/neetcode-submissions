class Solution {
public:

	bool isValidSudoku(std::vector<std::vector<char>>& board) {

        std::unordered_map<int, std::unordered_set<char>> rows_;
	    std::unordered_map<int, std::unordered_set<char>> cols_;
	    std::map<std::pair<int, int>, std::unordered_set<char>> squares_;

		for (int r = 0; r < 9; ++r) {
			for (int c = 0; c < 9; ++c) {
				if (board[r][c] == '.') continue;

				pair<int, int> squareKey = {r / 3, c / 3};

				char val = board[r][c];

				if (rows_[r].count(val) || 
				    cols_[c].count(val) ||
				    squares_[squareKey].count(val)) return false;

				rows_[r].insert(val);
				cols_[c].insert(val);
				squares_[squareKey].insert(val);
			}
		}
		return true;
	}
};

