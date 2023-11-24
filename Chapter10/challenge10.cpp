#include <iostream>
#include <string>

using namespace std;

string replaceSubstring(const string& string1, const string& string2, const string& string3) {
    string result = string1;
    size_t pos = result.find(string2);

    while (pos != string::npos) {
        result.replace(pos, string2.length(), string3);
        pos = result.find(string2, pos + string3.length());
    }

    return result;
}

int main() {
    // Test the function
    string string1 = "the dog jumped over the fence";
    string string2 = "the";
    string string3 = "that";

    string result = replaceSubstring(string1, string2, string3);

    // Display the result
    cout << "Original string: " << string1 << endl;
    cout << "Substring to replace: " << string2 << endl;
    cout << "Replacement substring: " << string3 << endl;
    cout << "Result: " << result << endl;

    return 0;
}
