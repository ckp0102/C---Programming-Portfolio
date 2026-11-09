
# C++ Programming Skills Portfolio

## Introduction
This portfolio contains three C++ programming challenges. The projects include a CO2 Calculator, a Joke Generator and a Book Manager. Each challenge uses different programming techniques such as functions, loops, classes and file handling. The programs were developed and tested using Visual Studio Code.
## Challenge 1 - CO2 Calculator

### How the program works
The purpose of my program is to estimate the amount of carbon dioxide produced during a car journey. It calculates emissions based on the distance travelled and whether the car uses petrol or diesel.
The user needs to enter the distance travelled in miles and select the fuel type, petrol or diesel. The program checks the input and asks the user to try again if the distance or fuel type is invalid.
### Functions and calculations
The getDistance() function asks the user to enter the journey distance and returns it as a double.
The getFuelType() function asks the user to enter petrol or diesel and returns the selected fuel as a string.
Both functions use loops to check the input.
The function first calculates the fuel consumption using 9.66 litres per 100 miles.
It then multiplies the litres used by the appropriate CO₂ emission factor.
- Petrol uses 2.31 kg CO₂ per litre
- Diesel uses 2.68 kg CO₂ per litre
For example, a 100-mile journey using petrol produces an estimated 22.31 kg of CO₂.
The program uses cout to display the estimated CO₂ emissions in kilograms. It uses fixed and setprecision(2) to show the result with two decimal places.
For example:
Estimated CO2 emissions: 22.31 kg
### Testing and problems solved
I tested the calculator using both petrol and diesel. For 100 miles, the program calculated 22.31 kg of CO2 for petrol and 25.89 kg for diesel. I also tested negative distances, zero and invalid fuel types.
During development, I placed a function call in the wrong location, which caused a compilation error. After correcting the code, the program compiled and worked successfully.
## Challenge 2 - Alexa Joke Generator

### How the program works
This program allows the user to request a random joke by typing "Alexa, tell me a joke". The program reads jokes from a text file and selects one randomly. It displays the first part of the joke and waits for the user to press Enter before showing the punchline. The user can request another joke or type "quit" to close the program.
### File handling and random selection
I used ifstream to open and read the randomJokes.txt file. Each joke is stored as a string inside a vector, which allows the program to work with multiple jokes.
The program uses rand() to select a random joke from the vector. It uses find('?') to locate the question mark separating the setup from the punchline. The substr() function then separates the two parts.
A while loop keeps the program running until the user decides to quit.
### Testing and problems solved
I compiled and tested the program using the VS Code terminal. I entered the required command and checked that the program displayed a random joke.
I also tested pressing Enter to reveal the punchline. The program successfully read the text file and displayed the joke.
During testing, I noticed that one special character from the joke dataset did not display correctly in the terminal. This appeared to be related to character encoding.
## Challenge 3 - Book Manager

### How the program works
The Book Manager is a simple library management program written in C++. It reads information about ten books from bookData.txt.
The program has a menu that allows the user to view all books, search for a specific book using its ID, borrow a book, return a book or exit.
Each book contains a title, author, number of pages, ID and borrowing status.
### Classes and file handling
I used a Book class to organise the information about each book. The class contains attributes for the title, author, pages, ID and borrowing status.
A constructor initialises the attributes when a new book object is created.
The program uses ifstream to read the book data from the text file and stringstream to separate the information using commas.
All the book objects are stored in a vector<Book>.
I used a string for the book ID so that values such as 001 and 002 keep their leading zeros.
### Borrowing and returning books
I extended the program by adding borrowing and returning functionality.
When a user chooses to borrow a book, the program searches for its ID and checks whether the book is available. If it is available, the program changes its borrowing status.
The return option works in a similar way. It checks whether the book is currently borrowed before changing its status to available.
The program uses ofstream to save the updated information to bookData.txt. This allows the borrowing status to remain saved after the program closes.
### Testing and problems solved
When I first ran the Book Manager, the program displayed an error involving stoi(). After checking the text file, I found an empty line at the beginning of the dataset.
I removed the empty line and ran the program again. It successfully displayed all ten books.
I then tested the menu by viewing all books and searching for The Hobbit using ID 008.
I also tested borrowing book 002, checking its new status and returning it. After restarting the program, I confirmed that the book was available again.
This helped me understand how file handling, classes and updating data work together in a C++ program.
## Reflection
These three challenges helped me develop my understanding of C++ programming. I practised using functions, loops, classes, vectors and file handling.
I encountered errors during development and learned how to identify and correct them. Testing the programs helped me understand how the code works and why input validation is important.
I also gained experience using the VS Code terminal to compile and run C++ programs. I would like to improve my ability to write and debug code more independently.
## AI Acknowledgement
I acknowledge the use of ChatGPT to help develop the documentation structure and identify improvements in writing style.
## References
OpenAI (2026) ChatGPT [Large language model]. Available at: https://chatgpt.com/ (Accessed: 9 November 2026). 
Microsoft (n.d.) Classes and Structs (C++). Microsoft Learn. Available at: https://learn.microsoft.com/en-us/cpp/cpp/classes-and-structs-cpp (Accessed: 9 November 2026).
cppreference.com (n.d.) Standard library header <fstream>. Available at: https://en.cppreference.com/cpp/header/fstream (Accessed: 9 November 2026).