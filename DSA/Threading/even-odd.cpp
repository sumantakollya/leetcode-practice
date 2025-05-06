#include <bits/stdc++.h>
#include <mutex>
#include <thread>

using namespace std;

int max_number;
int counter = 0;
mutex mtx;

void print_even() {
    while (true) {
        mtx.lock(); // Lock the mutex
        if (counter >= max_number) {
            mtx.unlock(); // Unlock the mutex before breaking
            break; // Exit if the counter has reached or exceeded max_number
        }
        if (counter % 2 == 0) {
            cout << counter << " ";
            counter++;
        }
        mtx.unlock(); // Unlock the mutex
    }
}

void print_odd() {
    while (true) {
        mtx.lock(); // Lock the mutex
        if (counter >= max_number) {
            mtx.unlock(); // Unlock the mutex before breaking
            break; // Exit if the counter has reached or exceeded max_number
        }
        if (counter % 2 != 0) {
            cout << counter << " ";
            counter++;
        }
        mtx.unlock(); // Unlock the mutex
    }
}

int main() {
    cout << "Enter max number: " << endl;
    cin >> max_number;

    thread t1 = thread(print_even);
    thread t2 = thread(print_odd);

    t1.join();
    t2.join();

    cout << endl;

    return 0;
}
