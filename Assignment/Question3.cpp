#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Ask the user to enter a string
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Create an empty stack to hold the first half of the string
    stack<char> stk;

    // Get the length of the string
    int n = str.length();

    // Push the first half of the string onto the stack
    for (int i = 0; i < n/2; i++) {
        stk.push(str[i]);
    }

    // Iterate over the second half of the string and compare each character with the popped character
    for (int i = (n+1)/2; i < n; i++) {
        // Pop a character from the stack
        char ch = stk.top();
        stk.pop();

        // Compare the popped character with the corresponding character in the second half of the string
        if (str[i] != ch) {
            // If the characters are not equal, the string is not a palindrome
            cout << "Not a palindrome" << endl;
            return 0;
        }
    }

    // If we have successfully popped all the characters from the stack and compared them with the corresponding characters 
    //in the second half of the string, the string is a palindrome
    cout << "Palindrome" << endl;
    return 0;
}
