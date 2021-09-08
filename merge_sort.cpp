#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> arr) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
}

vector<int> merge(vector<int> &left, vector<int> &right) {
	vector<int> result;
	while (left.size() > 0 && right.size() > 0) {
		int l_start = left[0];
		int r_start = right[0];
		if (l_start > r_start) {
			result.insert(result.end(), r_start);
			right.erase(right.begin());
		} else {
			result.insert(result.end(), l_start);
			left.erase(left.begin());
		}
	}
	result.insert(result.end(), left.begin(), left.end());
	result.insert(result.end(), right.begin(), right.end());
	return result;
}

vector<int> merge_sort(vector<int> &arr) {
	if (arr.size() == 1) return arr;

	int midpoint = (int) arr.size() / 2;
	vector<int> left_arr, right_arr, new_left, new_right, new_arr;
	new_left.assign(arr.begin(), arr.begin() + midpoint);
	new_right.assign(arr.begin() + midpoint, arr.end()); 
	left_arr = merge_sort(new_left);
	right_arr = merge_sort(new_right);
	return merge(left_arr, right_arr);
}

int main() {

	vector<int> test_arr, final_arr;
	test_arr = {4, 3355, 45, 678, 5, 6, 66, 33, 7, 8, 5, 561, 4646 };
	print_arr(test_arr);
	final_arr = merge_sort(test_arr);
	print_arr(final_arr);
	return 0;
}
