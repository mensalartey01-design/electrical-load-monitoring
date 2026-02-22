#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

// ================= STRUCT =================
struct Appliance
{
    string name;
    double watts;
    double hours;
};

vector<Appliance> appliances;
string FILE_NAME = "appliances.txt";

// ================= LOAD FROM FILE =================
void loadFromFile()
{
    ifstream file(FILE_NAME);

    if (!file)
        return;

    Appliance a;

    while (getline(file, a.name, '|'))
    {
        file >> a.watts;
        file.ignore();
        file >> a.hours;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        appliances.push_back(a);
    }

    file.close();
}

// ================= SAVE TO FILE =================
void saveToFile()
{
    ofstream file(FILE_NAME);

    for (int i = 0; i < appliances.size(); i++)
    {
        file << appliances[i].name << "|"
             << appliances[i].watts << "|"
             << appliances[i].hours << endl;
    }

    file.close();
    cout << "Appliances saved successfully.\n";
}

// ================= REGISTER APPLIANCE =================
void registerAppliance()
{
    Appliance a;

    cout << "Enter appliance name: ";
    getline(cin, a.name);

    cout << "Enter power (watts): ";
    while (!(cin >> a.watts))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number: ";
    }

    cout << "Enter hours used per day: ";
    while (!(cin >> a.hours))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    appliances.push_back(a);

    cout << "Appliance added successfully.\n";
}

// ================= VIEW APPLIANCES =================
void viewAppliances()
{
    if (appliances.empty())
    {
        cout << "No appliances registered.\n";
        return;
    }

    cout << fixed << setprecision(2);

    cout << "\nNo  Name               Watts   Hours   kWh/day\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < appliances.size(); i++)
    {
        double kwh = (appliances[i].watts / 1000) * appliances[i].hours;

        cout << i + 1 << "   "
             << setw(18) << left << appliances[i].name
             << setw(8) << appliances[i].watts
             << setw(8) << appliances[i].hours
             << kwh << endl;
    }
}

// ================= SEARCH APPLIANCE =================
void searchAppliance()
{
    string name;

    cout << "Enter appliance name to search: ";
    getline(cin, name);

    bool found = false;

    for (int i = 0; i < appliances.size(); i++)
    {
        if (appliances[i].name == name)
        {
            double kwh = (appliances[i].watts / 1000) * appliances[i].hours;

            cout << appliances[i].name << " | "
                 << appliances[i].watts << "W | "
                 << appliances[i].hours << " hrs | "
                 << kwh << " kWh/day\n";

            found = true;
        }
    }

    if (!found)
        cout << "Appliance not found.\n";
}

// ================= CALCULATE BILL =================
void calculateBill()
{
    if (appliances.empty())
    {
        cout << "No appliances available.\n";
        return;
    }

    double tariff;

    cout << "Enter tariff per kWh: ";
    while (!(cin >> tariff))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double totalKwh = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < appliances.size(); i++)
    {
        double kwh = (appliances[i].watts / 1000) * appliances[i].hours;
        totalKwh += kwh;

        cout << appliances[i].name << " - "
             << kwh << " kWh/day\n";
    }

    double dailyCost = totalKwh * tariff;
    double monthlyCost = dailyCost * 30;

    cout << "\nTotal Daily Energy: " << totalKwh << " kWh\n";
    cout << "Daily Cost: " << dailyCost << endl;
    cout << "Estimated Monthly Cost (30 days): " << monthlyCost << endl;

    char choice;

    cout << "Save billing summary? (y/n): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 'y' || choice == 'Y')
    {
        ofstream file("billing_summary.txt", ios::app);

        time_t now = time(0);

        file << "\n----------------------------------------\n";
        file << "Billing Summary - " << ctime(&now);
        file << "----------------------------------------\n";

        for (int i = 0; i < appliances.size(); i++)
        {
            double kwh = (appliances[i].watts / 1000) * appliances[i].hours;

            file << appliances[i].name << " - "
                 << kwh << " kWh/day\n";
        }

        file << "\nTotal Daily Energy: " << totalKwh << " kWh\n";
        file << "Daily Cost: " << dailyCost << endl;
        file << "Monthly Cost (30 days): " << monthlyCost << endl;

        file.close();
        cout << "Billing summary saved successfully.\n";
    }
}

// ================= MENU =================
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

// ================= MAIN =================
int main()
{
    loadFromFile();

    int choice;

    while (true)
    {
        showMenu();

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
            registerAppliance();
        else if (choice == 2)
            viewAppliances();
        else if (choice == 3)
            searchAppliance();
        else if (choice == 4)
            calculateBill();
        else if (choice == 5)
            saveToFile();
        else if (choice == 6)
        {
            saveToFile();
            cout << "Goodbye!\n";
            break;
        }
        else
            cout << "Invalid option.\n";
    }

    return 0;
}