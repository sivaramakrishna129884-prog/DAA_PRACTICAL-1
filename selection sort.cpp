#include <iostream>
#include <vector>
#include <limits> 

using namespace std;
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        while (!(cin >> arr[i])) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    selectionSort(arr);
    cout << "Sorted array (ascending order): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
