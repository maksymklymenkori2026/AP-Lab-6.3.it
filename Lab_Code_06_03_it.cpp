// Lab 6.3.it
// Variant 13

#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

double ToDouble(double x)
    { return x; }
double ToDouble(const string s)
    { return stod(s); }

// повертає чи масив впорядкрваний НЕ за зростанням
template <typename T>
T Ordered(T* a, const int n)
{
    for (int i = 0; i < n-1; i++)
        if (ToDouble(a[i]) < ToDouble(a[i + 1]))
            return static_cast<T>(false);
    return static_cast<T>(true);
}
bool Ordered(int* a, const int n)
{
    for (int i = 0; i < n-1; i++)
        if (ToDouble(a[i]) < ToDouble(a[i + 1]))
            return true;
    return false;
}

template <typename T>
T Print(T* a, const int n)
{
    for(int i = 0; i < n; i++)
        cout << setw(6) << a[i];
    cout << endl << endl;

    return a[0];
}
void Print(int* a, const int n)
{
    for(int i = 0; i < n; i++)
        cout << setw(6) << a[i];
    cout << endl << endl;
}

template <typename T>
T Create(T* a, const int n) {
    for(int i = 0; i < n; i++)
        a[i] = (i+1)*1.1;
    return a[0];
}

void Create(int* a, const int n) {
    for(int i = 0; i < n; i++)
        a[i] = (i+1)*1.1;
}

int main()
{
    const int n = 10;
    int a[n];
    double b[n];

    Create(a, n);
    Create(b, n);

    bool r1 = Ordered(a, n);
    cout << "Ordered(a, n) = " << r1 << endl;
    Print(a, n);

    bool r2 = Ordered<int>(a, n);
    cout << "Ordered<int>(a, n) = " << r2 << endl;
    Print(a, n);
    
    bool r3 = Ordered<double>(b, n);
    cout << "Ordered<double>(b, n) = " << r3 << endl;
    Print(b, n);

    return 0;
}