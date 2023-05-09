#include <iostream>
#include <string>

using namespace std;

int main() {
    // Define the DFA's states
    enum State { START, FIRST_ZERO, SECOND_ZERO, THIRD_ZERO, ACCEPT };
    State currentState = START;

    // Read in the input string
    string input;
    cout << "Enter a string of 0s and 1s: ";
    cin >> input;

    // Process each character in the input string
    for (char c : input) {
        switch (currentState) {
            case START:
                // If the current state is START and the current character is 0,
                // transition to the FIRST_ZERO state. Otherwise, stay in the START state.
                if (c == '0') {
                    currentState = FIRST_ZERO;
                }
                break;
            case FIRST_ZERO:
                // If the current state is FIRST_ZERO and the current character is 0,
                // transition to the SECOND_ZERO state. Otherwise, go back to the START state.
                if (c == '0') {
                    currentState = SECOND_ZERO;
                } else {
                    currentState = START;
                }
                break;
            case SECOND_ZERO:
                // If the current state is SECOND_ZERO and the current character is 0,
                // transition to the THIRD_ZERO state. Otherwise, go back to the START state.
                if (c == '0') {
                    currentState = THIRD_ZERO;
                } else {
                    currentState = START;
                }
                break;
            case THIRD_ZERO:
                // If the current state is THIRD_ZERO and the current character is 0,
                // stay in the THIRD_ZERO state. If the current character is 1,
                // transition to the ACCEPT state. Otherwise, go back to the START state.
                if (c == '0') {
                    currentState = THIRD_ZERO;
                } else if (c == '1') {
                    currentState = ACCEPT;
                } else {
                    currentState = START;
                }
                break;
            case ACCEPT:
                // If the current state is ACCEPT and the current character is not 1,
                // go back to the START state. Otherwise, stay in the ACCEPT state.
                if (c != '1') {
                    currentState = START;
                }
                break;
        }
    }

    // Output whether the input string was accepted or rejected
    if (currentState == ACCEPT) {
        cout << "Input string accepted" << endl;
    } else {
        cout << "Input string rejected" << endl;
    }

    return 0;
}
