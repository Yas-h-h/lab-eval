#include <iostream>
#include <vector>
using namespace std;
void printPolynomial(const vector<int>& coefficients) {
    int degree = coefficients.size() - 1;

    if (degree < 0) {
        cout << "0\n";
        return;
    }

    bool first = true;
    for (int i = degree; i >= 0; --i) {
        int coef = coefficients[i];
        if (coef == 0) continue;

        if (!first) {
            if (coef > 0) cout << " + ";
            else cout << " - ";
        } else {
            if (coef < 0) {
                cout << "-";
                coef = -coef;
            }
            first = false;
        }

        if (i == 0 || coef != 1) cout << coef;

        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
    }

    cout << endl;
}

vector<int> calculateDerivative(const vector<int>& coefficients) {
    int degree = coefficients.size() - 1;
    if (degree == 0) return {}; // Derivative of a constant is 0

    vector<int> derivative(degree);
    for (int i = 1; i <= degree; ++i) {
        derivative[i - 1] = coefficients[i] * i;
    }
    return derivative;
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial (0-5): ";
    cin >> degree;

    if (degree < 0 || degree > 5) {
        cerr << "Degree out of range!" << std::endl;
        return 1;
    }

    vector<int> coefficients(degree + 1);

    cout << "Enter the coefficients from the highest degree to the constant term:\n";
    for (int i = degree; i >= 0; --i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    cout << "Original polynomial: ";
    printPolynomial(coefficients);

    vector<int> derivative = calculateDerivative(coefficients);
    cout << "Derivative polynomial: ";
    printPolynomial(derivative);

    return 0;
}
