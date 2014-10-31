
namespace kc{
	bool binary_search(const int arr[], const size_t size, const int val) {
		if (size == 1) {
			return (arr[0] == val);
		}
		size_t i = size/2;

		if (arr[i] == val){
			return true;
		}
		else if (arr[i] > val) {
			return binary_search(arr, i, val);
		}
		else {
			return binary_search(arr + i + 1, size - i - 1, val);
		}
	}

	int find_min_rotated_array(const int arr[], const size_t size) {
		// { 3, 4, 5, 6, 7, 1, 2 }
		// { 5, 6, 1, 2, 3, 4, 5}
		// { 5, 6, 1, 2 }
		// { 5, 6, 1 }
		// { 6, 1 }

		if (size == 1) {
			return arr[0];
		}
		else if (size == 2) {
			return (arr[0] < arr[1] ? arr[0] : arr[1]);			
		}

		size_t i = size / 2;

		if (arr[0] < arr[i]) {
			//check right side
			return find_min_rotated_array(arr + i, size - i);
		}
		else {
			//check left side
			return find_min_rotated_array(arr, i + 1);
		}
	}

}
