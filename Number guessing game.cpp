#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int guess;

    cout << "===== NUMBER GUESSING GAME =====\n";
    cout << "Guess a number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > randomNumber)
            cout << "Too High! Try Again.\n";
        else if (guess < randomNumber)
            cout << "Too Low! Try Again.\n";
        else
            cout << "Congratulations! You guessed the correct number.\n";

    } while (guess != randomNumber);

    return 0;
}
