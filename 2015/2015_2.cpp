#include<iostream>
#include<string>
using namespace std;

class BigInteger {
private:
    string bigNum;

public:
    BigInteger() {
        bigNum = "";
    }

    BigInteger(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                for (int j = i; j < s.size(); j++) {
                    s[j] = s[j + 1];
                }
                i--;
                s[s.size() - 1] = '\0';
            }
        }
        bigNum = s;
    }

    friend istream& operator>>(istream& in, BigInteger& obj) {
        getline(in, obj.bigNum);
        return in;
    }

    bool operator==(const BigInteger& bNum) const {
        return (bigNum == bNum.bigNum);
    }
};

int main() {
    BigInteger n1("1234567891011");
    BigInteger n2;
    cout << "Input an integer = ";
    cin >> n2;

    if (n1 == n2) {
        cout << "Equal.\n";
    } else {
        cout << "Not equal.\n";
    }

    return 0;
}