#include <iostream>
#include <vector>
#include <limits>

using namespace std;
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);

    cout << "\nSorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
