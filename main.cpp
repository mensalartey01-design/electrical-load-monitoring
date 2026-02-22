#include <iostream>
using namespace std;

void showMenu()
{
    cout << "\n===== Electrical Load Monitoring System =====\n";
    cout << "1. Register Appliance\n";
    cout << "2. View Appliances\n";
    cout << "3. Search Appliance\n";
    cout << "4. Calculate Bill\n";
    cout << "5. Save Appliances\n";
    cout << "6. Exit\n";
    cout << "Choose option: ";
}

int main()
{
    string input;

    while (true)
    {
        showMenu();
        getline(cin, input);

        if (input == "6")
        {
            cout << "Goodbye!\n";
            break;
        }
        else
        {
            cout << "Feature not implemented yet.\n";
        }
    }

    return 0;
}