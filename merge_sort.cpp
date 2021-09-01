#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	while (left.size() > 0 && right.size() > 0) {
		int l_end = left[left.size()];
		int r_end = right[right.size()];
		cout << l_end << " | " << r_end << endl;
		if (l_end > r_end) {
			result.push_back(r_end);
			right.pop_back();
		} else {
			result.push_back(l_end);
			left.pop_back();
		}
	}

	result.insert(result.end(), left.begin(), left.end());
	result.insert(result.end(), right.begin(), right.end());

	return result;
}

vector<int> merge_sort(vector<int> arr) {
	if (arr.size() == 1) return arr;

	int midpoint = (int) arr.size() / 2;
	vector<int> left_arr, right_arr;
	vector::const_iterator itr_first = arr.begin();
	vector::const_iterator itr_middle = arr.begin() + midpoint;
	vector::const_iterator itr_last = arr.end();
	vector<int> new_left = newVec(itr_first, itr_middle);
	vector<int> new_right = newVec(itr_middle, itr_last); 
	vector<int> new_left(arr.begin(), arr.begin() + midpoint);
	vector<int> new_right(arr.begin() + midpoint, arr.begin()); 
	left_arr = merge_sort(new_left);
	right_arr = merge_sort(new_right);
	return merge(left_arr, right_arr);
}

void print_arr(vector<int> arr) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
}
int main() {

	vector<int> test_arr, final_arr;
	test_arr = {4, 3355, 45, 678, 5, 6, 66, 33, 7, 8, 5, 561, 4646 };
	print_arr(test_arr);
	final_arr = merge_sort(test_arr);
	print_arr(test_arr);
	return 0;
}
