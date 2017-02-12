#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T> // Swap two elements
void Swap(T &a, T &b) {
	T middle(a);
	a = b;
	b = middle;
}

//Input parameters is positions of first element and after the last element
template <typename T1>
void Bubble_Sort(T1 iterBegin, T1 iterEnd) {
	if (iterBegin > iterEnd) {
		std::cout << "Iteration begin point must be lower than end point";
		return;
	}
	if (iterBegin == iterEnd) {
		std::cout << "There is no range to sort";
		return;
	}
	bool exit = true; //Bool type as indicator of sort finish
	for (auto i = iterBegin; i != (iterEnd - 1); i++) {
		exit = true;
		for (auto j = iterBegin; j < (iterEnd - i + iterBegin - 1); j++) {
			if (*j > *(j + 1)) {
				Swap(*j, *(j + 1));
				exit = false;
			}
		}
		if (exit)
			break;
	}

}

//Same input parameters as Bubble Sort
template <typename T>
void Input_Sort(T iterBegin, T iterEnd) {
	if (iterBegin > iterEnd) {
		std::cout << "Iteration begin point must be lower than end point";
		return;
	}
	if (iterBegin == iterEnd) {
		std::cout << "There is no range to sort";
		return;
	}
	for (auto i = iterBegin; i != iterEnd - 1; i++) {
		for (auto j = i + 1; j != iterEnd; j++) {
			if (*i > *j)
				Swap(*i, *j);
		}
	}
}

//Same input parameters as Bubble Sort
template <typename T>
void Shake_Sort(T iterBegin, T iterEnd) {
	if (iterBegin > iterEnd) {
		std::cout << "Iteration begin point must be lower than end point";
		return;
	}
	if (iterBegin == iterEnd) {
		std::cout << "There is no range to sort";
		return;
	}
	for (auto left_index = iterBegin, rigth_index = iterEnd - 1; left_index < rigth_index;) {
		for (auto index = left_index; index < rigth_index; index++) {
			if (*index > *(index + 1)) {
				Swap(*index, *(index + 1));
			}
		}
		--rigth_index;
		for (auto index = rigth_index; index > left_index; index--) {
			if (*index < *(index - 1)) {
				Swap(*index, *(index - 1));
			}
		}
		++left_index;
	}
}

template <typename T> 
void Sift_Down(T & a, int treeIndex, int sizeOfCont) {
	int iMax = treeIndex;
	while (true) {
		if (((2 * treeIndex + 1) < sizeOfCont) && (a[2 * treeIndex + 1] > a[iMax]))
			iMax = 2 * treeIndex + 1;
		if (((2 * treeIndex + 2) < sizeOfCont) && (a[2 * treeIndex + 2] > a[iMax]))
			iMax = 2 * treeIndex + 2;
		if (iMax == treeIndex)
			break;
		Swap(a[treeIndex], a[iMax]);
		treeIndex = iMax;
	}
}
//HeapSort without any additions
template <typename T>
void Heap_Sort(T & cont, int sizeOfCont) {
	for (int i = (sizeOfCont / 2 - 1); i >= 0; i--)
		Sift_Down(cont, i, sizeOfCont);

	while (sizeOfCont > 1) {
		--sizeOfCont;
		Swap(cont[0], cont[sizeOfCont]);
		Sift_Down(cont, 0, sizeOfCont);
	}
}
