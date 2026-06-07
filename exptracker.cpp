#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Expense {
    string name;
    float amount;
};

int main() {
    vector<Expense> expenses;
    int choice;

    do {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Show Total Expense\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Expense e;
                cout << "Enter expense name: ";
                cin.ignore();
                getline(cin, e.name);

                cout << "Enter amount: ";
                cin >> e.amount;

                expenses.push_back(e);
                cout << "Expense added successfully!\n";
                break;
            }

            case 2: {
                if (expenses.empty()) {
                    cout << "No expenses recorded.\n";
                } else {
                    cout << "\nExpenses:\n";
                    for (int i = 0; i < expenses.size(); i++) {
                        cout << i + 1 << ". "
                             << expenses[i].name
                             << " - Rs. " << expenses[i].amount << endl;
                    }
                }
                break;
            }

            case 3: {
                float total = 0;
                for (auto e : expenses) {
                    total += e.amount;
                }
                cout << "Total Expense: Rs. " << total << endl;
                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
