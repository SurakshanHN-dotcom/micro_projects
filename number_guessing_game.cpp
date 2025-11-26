#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Initialize random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int no_of_guesses = 0;
    int guessed_number;

    
    //cout << "Random Number: " << randomNumber << endl;

    do {
        cout << "Guess the number: ";
        cin >> guessed_number;

        if (guessed_number > randomNumber) {
            cout << "Lower number please!\n";
        }
        else if (guessed_number < randomNumber) {
            cout << "Higher number please!\n";
        }
        else {
            cout << "Congrats!!\n";
        }

        no_of_guesses++;

    } while (guessed_number != randomNumber);

    cout << "You guessed the number in " << no_of_guesses << " guesses.\n";

    return 0;
}
