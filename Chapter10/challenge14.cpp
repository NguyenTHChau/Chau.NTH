#include <iostream>
#include <cctype>

std::string convertToSentence(const std::string& input) {
    std::string result;
    bool newWord = true;

    for (char ch : input) {
        if (std::isupper(ch)) {
            if (!newWord) {
                result += ' ';
            }
            newWord = false;
        }

        result += std::tolower(ch);
    }

    return result;
}

int main() {
    std::string inputSentence;

    // Get the sentence from the user
    std::cout << "Enter a sentence with words run together: ";
    std::getline(std::cin, inputSentence);

    // Convert and print the sentence
    std::cout << "Converted sentence: " << convertToSentence(inputSentence) << std::endl;

    return 0;
}
