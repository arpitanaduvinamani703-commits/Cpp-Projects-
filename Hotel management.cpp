#include <iostream>
using namespace std;

struct Customer {
    int roomNo;
    string name;
    int age;
    string phone;
};

int main() {
    Customer c[100];
    int count = 0;
    int choice;

    do {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Delete Customer\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Room Number: ";
            cin >> c[count].roomNo;

            cout << "Customer Name: ";
            cin.ignore();
            getline(cin, c[count].name);

            cout << "Age: ";
            cin >> c[count].age;

            cout << "Phone Number: ";
            cin >> c[count].phone;

            count++;
            cout << "Customer Added Successfully!\n";
            break;

        case 2:
            if(count==0){
                cout<<"No Customer Records Found!\n";
            }
            else{
                for(int i=0;i<count;i++){
                    cout<<"\nRoom No : "<<c[i].roomNo;
                    cout<<"\nName : "<<c[i].name;
                    cout<<"\nAge : "<<c[i].age;
                    cout<<"\nPhone : "<<c[i].phone<<endl;
                }
            }
            break;

        case 5:
            cout<<"Thank You!";
            break;

        default:
            cout<<"Invalid Choice!";
        }

    } while(choice!=5);

    return 0;
}
