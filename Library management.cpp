#include <iostream>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool issued;
};

int main() {
    Book books[100];
    int count = 0, choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. View Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter Book ID: ";
            cin >> books[count].id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, books[count].title);

            cout << "Enter Author Name: ";
            getline(cin, books[count].author);

            books[count].issued = false;
            count++;
            cout << "Book Added Successfully!\n";
            break;

        case 2:
            if(count == 0) {
                cout << "No Books Available!\n";
            } else {
                for(int i = 0; i < count; i++) {
                    cout << "\nBook ID : " << books[i].id;
                    cout << "\nTitle   : " << books[i].title;
                    cout << "\nAuthor  : " << books[i].author;
                    cout << "\nStatus  : "
                         << (books[i].issued ? "Issued" : "Available")
                         << "\n";
                }
            }
            break;

        case 3: {
            int id;
            bool found = false;
            cout << "Enter Book ID: ";
            cin >> id;

            for(int i = 0; i < count; i++) {
                if(books[i].id == id) {
                    cout << "\nTitle: " << books[i].title;
                    cout << "\nAuthor: " << books[i].author;
                    cout << "\nStatus: "
                         << (books[i].issued ? "Issued" : "Available")
                         << "\n";
                    found = true;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";
            break;
        }

        case 4: {
            int id;
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            for(int i = 0; i < count; i++) {
                if(books[i].id == id && !books[i].issued) {
                    books[i].issued = true;
                    cout << "Book Issued Successfully!\n";
                }
            }
            break;
        }

        case 5: {
            int id;
            cout << "Enter Book ID to Return: ";
            cin >> id;

            for(int i = 0; i < count; i++) {
                if(books[i].id == id && books[i].issued) {
                    books[i].issued = false;
                    cout << "Book Returned Successfully!\n";
                }
            }
            break;
        }

        case 6:
            cout << "Thank You!";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while(choice != 6);

    return 0;
}
