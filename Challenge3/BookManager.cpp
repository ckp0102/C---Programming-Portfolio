
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Store information about a book
class Book {
public:
    string title, author, id;
    int pages;
    bool borrowed;

    Book(string t, string a, int p, string i, bool b)
        : title(t), author(a), pages(p), id(i), borrowed(b) {}

    void display() const {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Pages: " << pages
             << " | Status: "
             << (borrowed ? "Borrowed" : "Available") << "\n";
    }
};

// Find a book using its ID
Book* findBook(vector<Book>& books, string id) {
    for (Book& book : books) {
        if (book.id == id) {
            return &book;
        }
    }
    return nullptr;
}

// Save updated book records to the file
bool saveBooks(const vector<Book>& books) {
    ofstream file("bookData.txt");
    if (!file.is_open()) return false;

    for (const Book& book : books) {
        file << book.title << ","
             << book.author << ","
             << book.pages << ","
             << book.id << ","
             << (book.borrowed ? "true" : "false") << "\n";
    }

    file.close();
    return !file.fail();
}

int main() {
    vector<Book> books;
    ifstream file("bookData.txt");
    string line;

    if (!file.is_open()) {
        cout << "Error opening bookData.txt\n";
        return 1;
    }

    // Read book information
    while (getline(file, line)) {
        if (line.empty()) continue;

        string title, author, pages, id, status;
        stringstream ss(line);

        if (!getline(ss, title, ',') ||
            !getline(ss, author, ',') ||
            !getline(ss, pages, ',') ||
            !getline(ss, id, ',') ||
            !getline(ss, status)) {
            cout << "Skipping incomplete record.\n";
            continue;
        }

        if (status != "true" && status != "false") {
            cout << "Skipping invalid status.\n";
            continue;
        }

        try {
            books.emplace_back(title, author, stoi(pages),
                               id, status == "true");
        } catch (const exception&) {
            cout << "Skipping invalid book record.\n";
        }
    }

    file.close();
    string choice;

    // Main library menu
    while (true) {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. View all books\n";
        cout << "2. View individual book\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        getline(cin, choice);

        if (choice == "1") {
            for (const Book& book : books) {
                book.display();
            }
        }
        else if (choice == "2" || choice == "3" ||
                 choice == "4") {
            string id;
            cout << "Enter book ID: ";
            getline(cin, id);

            Book* book = findBook(books, id);

            if (book == nullptr) {
                cout << "Book not found.\n";
                continue;
            }

            if (choice == "2") {
                book->display();
                continue;
            }

            if (choice == "3" && book->borrowed) {
                cout << "Book is already borrowed.\n";
                continue;
            }

            if (choice == "4" && !book->borrowed) {
                cout << "Book is already available.\n";
                continue;
            }

            bool previousStatus = book->borrowed;
            book->borrowed = (choice == "3");

            if (saveBooks(books)) {
                cout << (choice == "3"
                         ? "Book borrowed successfully.\n"
                         : "Book returned successfully.\n");
            } else {
                book->borrowed = previousStatus;
                cout << "Error saving book changes.\n";
            }
        }
        else if (choice == "5") {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}


