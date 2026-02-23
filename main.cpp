#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

struct Appliance
{
    string name;
    double watts;
    double hours;
};

vector<Appliance> appliances;
string FILE_NAME = "appliances.txt";

// ================= LOAD =================
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
        file.ignore();
        appliances.push_back(a);
    }

    file.close();
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

// ================= REGISTER =================
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

// ================= VIEW =================
void viewAppliances()
{
    if (appliances.empty())
    {
        cout << "No appliances registered.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < appliances.size(); i++)
    {
        double kwh = (appliances[i].watts / 1000) * appliances[i].hours;
        cout << i + 1 << ". "
             << appliances[i].name << " | "
             << appliances[i].watts << "W | "
             << appliances[i].hours << " hrs | "
             << kwh << " kWh/day\n";
    }
}

// ================= SEARCH =================
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
    cin >> tariff;
    cin.ignore();

    double totalKwh = 0;
    for (int i = 0; i < appliances.size(); i++)
    {
        double kwh = (appliances[i].watts / 1000) * appliances[i].hours;
        totalKwh += kwh;
    }

    cout << "\nTotal Daily Energy: " << totalKwh << " kWh\n";
    cout << "Daily Cost: " << totalKwh * tariff << endl;
    cout << "Estimated Monthly Cost (30 days): " << totalKwh * tariff * 30 << endl;

    // ============== SAVE BILL SUMMARY =================
    char choice;
    cout << "Save billing summary? (y/n): ";
    cin >> choice;
    cin.ignore();

    if (choice == 'y' || choice == 'Y')
    {
        ofstream file("billing_summary.txt", ios::app);
        time_t now = time(0);

        file << "\n========================================\n";
        file << "Billing Summary - " << ctime(&now);
        file << "----------------------------------------\n";

        for (int i = 0; i < appliances.size(); i++)
        {
            double kwh = (appliances[i].watts / 1000) * appliances[i].hours;
            file << appliances[i].name << " - "
                 << kwh << " kWh/day\n";
        }

        file << "\nTotal Daily Energy: " << totalKwh << " kWh\n";
        file << "Daily Cost: " << totalKwh * tariff << endl;
        file << "Monthly Cost (30 days): " << totalKwh * tariff * 30 << endl;
        file << "========================================\n";

        file.close();
        cout << "Billing summary saved successfully.\n";
    }
}

// ================= SAVE =================
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

// ================= MAIN =================
int main()
{
    loadFromFile();

    string input;

    while (true)
    {
        showMenu();
        getline(cin, input);

        if (input == "1")
            registerAppliance();
        else if (input == "2")
            viewAppliances();
        else if (input == "3")
            searchAppliance();
        else if (input == "4")
            calculateBill();
        else if (input == "5")
            saveToFile();
        else if (input == "6")
        {
            cout << "Goodbye!\n";
            break;
        }
        else
            cout << "Feature not implemented yet.\n";
    }

    return 0;
}
