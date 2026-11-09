
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    vector<string> jokes;
    string line;

    // Open the jokes file
    ifstream file("randomJokes.txt");

    if (!file.is_open()) {
        cout << "Error: Cannot open randomJokes.txt\n";
        return 1;
    }

    // Read jokes from the file
    while (getline(file, line)) {
        if (line.find('?') != string::npos) {
            jokes.push_back(line);
        }
    }

    file.close();

    if (jokes.empty()) {
        cout << "No jokes found.\n";
        return 1;
    }

    // Set up random joke selection
    srand(time(0));

    string command;

    while (true) {
        cout << "\nType 'Alexa, tell me a joke' or 'quit': ";
        getline(cin, command);

        if (command == "quit") {
            cout << "Goodbye!\n";
            break;
        }

        if (command == "Alexa, tell me a joke") {
            int index = rand() % jokes.size();
            string joke = jokes[index];

            size_t position = joke.find('?');

            // Display the joke setup
            cout << joke.substr(0, position + 1) << "\n";

            cout << "Press Enter for the punchline...";
            getline(cin, command);

            // Display the punchline
            cout << joke.substr(position + 1) << "\n";
        } else {
            cout << "Please use the correct command.\n";
        }
    }

    return 0;
}
