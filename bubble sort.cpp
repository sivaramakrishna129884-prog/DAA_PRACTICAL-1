#include <iostream>
#include <vector>
#include <limits> 

using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        while (!(cin >> arr[i])) {
            cout << "Invalid input. Enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

