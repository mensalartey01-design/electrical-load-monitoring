#include <iostream>
#include <vector>
using namespace std;

struct Appliance
{
    string name;
    double watts;
    double hours;
};

vector<Appliance> appliances;

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

void registerAppliance()
{
    Appliance a;

    cout << "Enter appliance name: ";
    getline(cin, a.name);

    cout << "Enter power (watts): ";
    cin >> a.watts;

    cout << "Enter hours used per day: ";
    cin >> a.hours;
    cin.ignore();

    appliances.push_back(a);

    cout << "Appliance added successfully.\n";
}

int main()
{
    string input;

    while (true)
    {
        showMenu();
        getline(cin, input);

        if (input == "1")
        {
            registerAppliance();
        }
        else if (input == "6")
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