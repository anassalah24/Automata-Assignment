#include <iostream>
#include <string>

using namespace std;

// DFA states
enum class State {
    EVEN_ZEROS_EVEN_ONES, // Even number of 0s and even number of 1s seen so far
    ODD_ZEROS_EVEN_ONES,  // Odd number of 0s and even number of 1s seen so far
    EVEN_ZEROS_ODD_ONES,  // Even number of 0s and odd number of 1s seen so far
    ODD_ZEROS_ODD_ONES    // Odd number of 0s and odd number of 1s seen so far
};

// DFA transition function
State transition(State current_state, char input) {
    switch (current_state) {
        case State::EVEN_ZEROS_EVEN_ONES:
            if (input == '0') {
                return State::ODD_ZEROS_EVEN_ONES;
            } else {
                return State::EVEN_ZEROS_ODD_ONES;
            }
        case State::ODD_ZEROS_EVEN_ONES:
            if (input == '0') {
                return State::EVEN_ZEROS_EVEN_ONES;
            } else {
                return State::ODD_ZEROS_ODD_ONES;
            }
        case State::EVEN_ZEROS_ODD_ONES:
            if (input == '0') {
                return State::ODD_ZEROS_ODD_ONES;
            } else {
                return State::EVEN_ZEROS_EVEN_ONES;
            }
        case State::ODD_ZEROS_ODD_ONES:
            if (input == '0') {
                return State::EVEN_ZEROS_ODD_ONES;
            } else {
                return State::ODD_ZEROS_EVEN_ONES;
            }
    }
}

// DFA accepts if it ends in EVEN_ZEROS_EVEN_ONES and number of 0s and 1s seen so far is even
bool accepts(string input) {
    State current_state = State::EVEN_ZEROS_EVEN_ONES; // Start in the initial state
    int num_zeros = 0, num_ones = 0; // Keep track of number of 0s and 1s seen so far
    for (char c : input) {
        current_state = transition(current_state, c); // Update state based on input
        if (c == '0') {
            num_zeros++; // Increment num_zeros if input is '0'
        } else {
            num_ones++; // Increment num_ones if input is '1'
        }
    }
    return current_state == State::EVEN_ZEROS_EVEN_ONES && num_zeros % 2 == 0 && num_ones % 2 == 0;
    // Return true only if the DFA ends in the accepting state AND number of 0s and 1s seen so far is even
}

int main() {
    string input;
    cout << "Enter a string of 0s and 1s: ";
    cin >> input;
    if (accepts(input)) {
        cout << "Accepted!" << endl;
    } else {
        cout << "Rejected!" << endl;
    }
    return 0;
}
