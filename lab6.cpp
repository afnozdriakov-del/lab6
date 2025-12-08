#include <iostream>
using namespace std;

const int MAXN = 50;

// ---------------- ФУНКЦІЇ ДЛЯ МАСИВІВ ----------------

// введення масиву
void inputArray(double a[], int &N) {
    cout << "Введіть розмір масиву (2..50): ";
    cin >> N;
    cout << "Введіть " << N << " елементів масиву через пробіл: ";
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
}

// виведення масиву
void printArray(double a[], int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// підрахунок кількості зростаючих ділянок
int countIncreasingSegments(double a[], int N) {
    int count_segments = 0;
    bool growing = false;

    for (int i = 0; i < N - 1; i++) {
        if (a[i] < a[i + 1]) {
            if (!growing) {
                count_segments++;
                growing = true;
            }
        } else {
            growing = false;
        }
    }
    return count_segments;
}

// видалення елемента за номером K
void deleteElement(double a[], int &N, int K) {
    int idx = K - 1;
    for (int i = idx; i < N - 1; i++) {
        a[i] = a[i + 1];
    }
    N--;
}



// ---------------- ЗАВДАННЯ ARRAY 37 ----------------
void Array_37() {
    double a[MAXN];
    int N;

    inputArray(a, N);    // введення
    cout << "Введений масив: ";
    printArray(a, N);    // виведення

    int result = countIncreasingSegments(a, N);
    cout << "Кількість зростаючих ділянок у масиві: " << result << endl;
    cout << "(Цифра означає кількість послідовностей елементів, де кожний наступний більший за попередній)\n";
}



// ---------------- ЗАВДАННЯ ARRAY 90 ----------------
void Array_90() {
    double a[MAXN];
    int N, K;

    inputArray(a, N);  // введення масиву
    cout << "Введіть номер елемента K для видалення (1 ≤ K ≤ " << N << "): ";
    cin >> K;

    cout << "Початковий масив: ";
    printArray(a, N);  // вивести початковий масив

    deleteElement(a, N, K);

    cout << "Масив після видалення " << K << "-го елемента: ";
    printArray(a, N);  // вивести змінений масив
}



// ---------------- ГОЛОВНЕ МЕНЮ ----------------
int main() {
    int choice;

    do {
        cout << "\nОберіть завдання:\n";
        cout << "1 - Array 37 (підрахунок зростаючих ділянок у масиві)\n";
        cout << "2 - Array 90 (видалення елемента K з масиву)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {

            case 1:
                Array_37();
                break;

            case 2:
                Array_90();
                break;

            case 0:
                cout << "Програма завершена.\n";
                break;

            default:
                cout << "Невірний вибір! Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    return 0;
}

