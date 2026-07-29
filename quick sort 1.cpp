#include <iostream>
#include <vector>
#include <limits>

using namespace std;
void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;     

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { 
            i++;
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);         
        quickSort(arr, pi + 1, high);        
    }
}
bool readInt(int &num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!readInt(n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        if (!readInt(arr[i])) {
            cout << "Invalid input. Please enter integers only.\n";
            return 1;
        }
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
