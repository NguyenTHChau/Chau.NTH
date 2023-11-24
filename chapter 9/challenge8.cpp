#include <iostream>
#include <algorithm>

using namespace std;

int findMode(const int* arr, int size) {
    if (size <= 0) {
        return -1;
    }

    int* sortedArr = new int[size];
    copy(arr, arr + size, sortedArr);
    sort(sortedArr, sortedArr + size);

    int mode = sortedArr[0];
    int currentCount = 1;

    int maxMode = mode;
    int maxCount = currentCount;

    for (int i = 1; i < size; ++i) {
        if (sortedArr[i] == sortedArr[i - 1]) {
            ++currentCount;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxMode = mode;
            }

            mode = sortedArr[i];
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxMode = mode;
    }

    delete[] sortedArr;

    return maxCount > 1 ? maxMode : -1;
}

int main() {
    const int size = 10;
    int arr[size] = {2, 3, 4, 2, 5, 6, 2, 4, 3, 6};

    int mode = findMode(arr, size);

    if (mode != -1) {
        cout << "Mode: " << mode << endl;
    } else {
        cout << "No mode found." << endl;
    }

    return 0;
}
