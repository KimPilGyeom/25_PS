#include <iostream>

using namespace std;

void processNumbers(int* arr, int n, int* sum, int* max) {
    *sum = 0;
    *max = arr[0];

    for (int i = 0; i < n; i++) {
        *sum += arr[i];
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* numbers = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> *(numbers + i);
    }

    int total, maximum;

    processNumbers(numbers, n, &total, &maximum);

    cout << total << " " << maximum << endl;

    delete[] numbers;

    return 0;
}