#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <set>

using namespace std;

class HangmanGame {
private:
    vector<string> words = {
        "COMPUTER", "PROGRAMMING", "HANGMAN", "KEYBOARD", "MONITOR",
        "SOFTWARE", "HARDWARE", "INTERNET", "ALGORITHM", "FUNCTION",
        "VARIABLE", "DATABASE", "NETWORK", "SECURITY", "WEBSITE",
        "BROWSER", "DOWNLOAD", "UPLOAD", "ARTIFICIAL", "INTELLIGENCE",
        "MACHINE", "LEARNING", "SCIENCE", "TECHNOLOGY", "DEVELOPER"
    };
    
    string currentWord;
    set<char> guessedLetters;
    int wrongGuesses;
    static const int MAX_TRIALS = 10;

public:
    HangmanGame() {
        srand(time(0));
        wrongGuesses = 0;
    }

    void displayHangman(int wrong) {
        vector<string> stages = {
            "\n   --------\n   |      |\n   |      \n   |    \n   |      \n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |    \n   |      \n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |      |\n   |      \n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\n   |      \n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\\\n   |      \n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\\\n   |     /\n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\\\n   |     / \\\n   |     \n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\\\n   |     / \\\n   |    RIP\n   -\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\\\n   |     / \\\n   |   GAME\n   -  OVER\n",
            "\n   --------\n   |      |\n   |      O\n   |     /|\\\n   |     / \\\n   |    YOU\n   -  LOSE!\n"
        };
        
        if (wrong < stages.size()) {
            cout << stages[wrong];
        } else {
            cout << stages.back();
        }
    }

    string getRandomWord() {
        int index = rand() % words.size();
        return words[index];
    }

    string displayWord() {
        string display = "";
        for (char c : currentWord) {
            if (guessedLetters.find(c) != guessedLetters.end()) {
                display += c;
                display += " ";
            } else {
                display += "_ ";
            }
        }
        return display;
    }

    void displayGameState() {
        displayHangman(wrongGuesses);
        cout << "\nWord: " << displayWord() << endl;
        
        cout << "Guessed letters: ";
        if (guessedLetters.empty()) {
            cout << "None";
        } else {
            bool first = true;
            for (char c : guessedLetters) {
                if (!first) cout << ", ";
                cout << c;
                first = false;
            }
        }
        cout << endl;
        
        cout << "Wrong guesses: " << wrongGuesses << "/" << MAX_TRIALS << endl;
        cout << "Remaining trials: " << (MAX_TRIALS - wrongGuesses) << endl;
    }

    bool isWordComplete() {
        for (char c : currentWord) {
            if (guessedLetters.find(c) == guessedLetters.end()) {
                return false;
            }
        }
        return true;
    }

    char getPlayerGuess() {
        char guess;
        while (true) {
            cout << "\n" << string(30, '-') << endl;
            cout << "Enter a letter: ";
            cin >> guess;
            guess = toupper(guess);
            
            if (!isalpha(guess)) {
                cout << "❌ Please enter a letter only!" << endl;
                continue;
            }
            
            if (guessedLetters.find(guess) != guessedLetters.end()) {
                cout << "❌ You already guessed '" << guess << "'. Try a different letter!" << endl;
                continue;
            }
            
            return guess;
        }
    }

    void playGame() {
        cout << string(50, '=') << endl;
        cout << "🎮 WELCOME TO HANGMAN GAME! 🎮" << endl;
        cout << string(50, '=') << endl;
        cout << "You have " << MAX_TRIALS << " trials to guess the word!" << endl;
        cout << "Good luck! 🍀\n" << endl;
        
        currentWord = getRandomWord();
        guessedLetters.clear();
        wrongGuesses = 0;
        
        cout << "Word to guess: " << displayWord() << endl;
        cout << "Word length: " << currentWord.length() << " letters\n" << endl;
        
        while (wrongGuesses < MAX_TRIALS) {
            displayGameState();
            
            if (isWordComplete()) {
                cout << "\n🎉 CONGRATULATIONS! YOU WON! 🎉" << endl;
                cout << "The word was: " << currentWord << endl;
                cout << "You guessed it with " << (MAX_TRIALS - wrongGuesses) << " trials remaining!" << endl;
                return;
            }
            
            char guess = getPlayerGuess();
            guessedLetters.insert(guess);
            
            if (currentWord.find(guess) != string::npos) {
                cout << "✅ Great! '" << guess << "' is in the word!" << endl;
                
                // Count occurrences
                int count = 0;
                for (char c : currentWord) {
                    if (c == guess) count++;
                }
                if (count > 1) {
                    cout << "'" << guess << "' appears " << count << " times in the word!" << endl;
                }
            } else {
                wrongGuesses++;
                cout << "❌ Sorry, '" << guess << "' is not in the word." << endl;
                cout << "Wrong guess #" << wrongGuesses << endl;
            }
            
            cout << "\n" << string(50, '=') << endl;
        }
        
        // Game over - player lost
        displayHangman(wrongGuesses);
        cout << "\n💀 GAME OVER! 💀" << endl;
        cout << "You've used all " << MAX_TRIALS << " trials!" << endl;
        cout << "The word was: " << currentWord << endl;
        cout << "Better luck next time! 🎯" << endl;
    }

    bool askPlayAgain() {
        char choice;
        cout << "\n" << string(50, '=') << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return (tolower(choice) == 'y');
    }
};

int main() {
    HangmanGame game;
    
    do {
        game.playGame();
    } while (game.askPlayAgain());
    
    cout << "Thanks for playing Hangman! Goodbye! 👋" << endl;
    
    return 0;
}