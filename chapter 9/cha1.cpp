#include <iostream>

using namespace std;

int main() {
    const int rows = 10;
    
    // Hi?n th? "Pattern A" v� "Pattern B"
    cout << "Pattern A";
    for (int m = 0; m < (rows - 1); ++m) {
        cout << " ";
    }
    cout << "Pattern B\n";

    // Hi?n th? Pattern A v� Pattern B tr�n c�ng m?t h�ng
    for (int i = 0; i < rows; ++i) {
        // Hi?n th? Pattern A
        for (int j = 0; j <= i; ++j) {
            cout << "+";
        }

        // Hi?n th? kho?ng tr?ng gi?a Pattern A v� Pattern B
        for (int k = 0; k < (rows - i )  k++) {
            cout << " ";
        }

        // Hi?n th? Pattern B
        for (int l = 0; l <= rows - i; ++l) {
            cout << "+";
        }

        cout << endl;
    }
    return 0;
}

