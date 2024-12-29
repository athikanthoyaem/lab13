#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;

}

void stat(const double arr[], int n, double result[]) {
    double sum = 0.0;
    double sum_sq = 0.0;
    double harmonic_sum = 0.0;
    double product = 1.0;
    double max_val = arr[0];
    double min_val = arr[0];

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        sum_sq += arr[i] * arr[i];
        harmonic_sum += 1.0 / arr[i];
        product *= arr[i];
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }

    result[0] = sum / n;
    result[1] = sqrt((sum_sq / n) - (result[0] * result[0]));
    result[2] = pow(product, 1.0 / n);
    result[3] = n / harmonic_sum;
    result[4] = max_val;
    result[5] = min_val;
}

