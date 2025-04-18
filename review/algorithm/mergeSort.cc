#include <iostream>

#define ARR_LEN(arr) (sizeof(arr)/sizeof(arr[0]))
#define SWAP(arr,i,j) {\
		int tmp = arr[i];\
		arr[i] = arr[j];\
		arr[j] = tmp;\
	}

template<class T>
void print(T arr[], int len) {
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

static void merge(int* arr, int left, int mid, int right, int* tmp) {
	// 穿针引线
	int tmpIdx = left, leftIdx = left, rightIdx = mid + 1;
	for (; leftIdx <= mid && rightIdx <= right;) {
		if (arr[leftIdx] < arr[rightIdx]) {
			tmp[tmpIdx++] = arr[leftIdx++];
		}
		else {
			tmp[tmpIdx++] = arr[rightIdx++];
		}
	}//
	while ( rightIdx <= right) {
		tmp[tmpIdx++] = arr[rightIdx++];
	}
	while (leftIdx <= mid) {
		tmp[tmpIdx++] = arr[leftIdx++];
	}
	for (int i = left; i <= right ; ++i) {
		arr[i] = tmp[i];
	}
}
void divide_merge(int arr[], int left, int right, int* tmp) {
	if (left >= right) {// 递归出口
		return ;
	}
	int mid = left + ((right - left) >> 1);
	divide_merge(arr, left, mid, tmp);
	divide_merge(arr, mid + 1, right, tmp);

	merge(arr, left, mid ,right ,tmp);
}
void merge_sort(int* arr, int arr_size) {
	int* tmp = new int[arr_size]();
	divide_merge(arr, 0,arr_size - 1, tmp);
	delete[]tmp;
}

int main() {

	int arr[] = { 8, 3, 2, 6, 9, 7, 1, 0, 4, 5 };
	int arr_size = ARR_LEN(arr);

	merge_sort(arr, arr_size);
	print(arr, arr_size);

	return 0;
}
