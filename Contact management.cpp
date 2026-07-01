#include <iostream>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    Contact contacts[100];
    int count = 0, choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cout << "Enter Name: ";
            cin >> contacts[count].name;
            cout << "Enter Phone: ";
            cin >> contacts[count].phone;
            count++;
            cout << "Contact Added Successfully!\n";
            break;

        case 2:
            if(count == 0) {
                cout << "No Contacts Found!\n";
            } else {
                for(int i = 0; i < count; i++) {
                    cout << "\nName: " << contacts[i].name;
                    cout << "\nPhone: " << contacts[i].phone << endl;
                }
            }
            break;

        case 3: {
            string search;
            cout << "Enter Name to Search: ";
            cin >> search;
            bool found = false;

            for(int i = 0; i < count; i++) {
                if(contacts[i].name == search) {
                    cout << "Name: " << contacts[i].name << endl;
                    cout << "Phone: " << contacts[i].phone << endl;
                    found = true;
                }
            }

            if(!found)
                cout << "Contact Not Found!\n";
            break;
        }

        case 4: {
            string del;
            cout << "Enter Name to Delete: ";
            cin >> del;

            for(int i = 0; i < count; i++) {
                if(contacts[i].name == del) {
                    for(int j = i; j < count - 1; j++)
                        contacts[j] = contacts[j + 1];

                    count--;
                    cout << "Contact Deleted Successfully!\n";
                    break;
                }
            }
            break;
        }

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
