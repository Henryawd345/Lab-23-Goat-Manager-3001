#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits> 
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
int N_NAMES = 0;
int N_COLORS = 0;


int select_goat(list<Goat> &trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> &trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (N_NAMES < SZ_NAMES && (fin >> names[N_NAMES])) N_NAMES++;
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (N_COLORS < SZ_COLORS && (fin1 >> colors[N_COLORS])) N_COLORS++;
    fin1.close();

    list<Goat> trip;

    while (true){
        int choice = main_menu();

        switch (choice) {
            case 1:

            cout << "\n[Add goat]\n";
                break;
            case 2:
                cout << "\n[Delete goat]\n";
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                cout << "\nGoodbye! Thanks for using GOAT MANAGER 3001.\n";
                return 0;

        }
    }
}

int main_menu() {
    cout << "\n*** GOAT MANAGER 3001 ***\n"
         << "[1] Add a goat\n"
         << "[2] Delete a goat\n"
         << "[3] List goats\n"
         << "[4] Quit\n"
         << "Choice --> ";

        int choice;

        while (!(cin >> choice) || choice < 1 || choice > 4){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number between 1 and 4: ";
        }
    return choice;
}

void display_trip(list<Goat> &trip){
    cout << "\nCurrent Trip (" << trip.size() << " goat" 
        << (trip.size() == 1 ? "" : "s") << "):\n";
    
    if (trip.empty()) {
        cout << "  (empty)\n";
        return;
    }


    cout << left << setw(5)  << "#"
         << left << setw(16) << "Name"
         << left << setw(8)  << "Age"
         << left << setw(12) << "Color" << "\n";
    cout << string(40, '-') << "\n";

    int idx = 1;
    for (const auto& g : trip) {
        cout << left << setw(5)  << idx++
             << left << setw(16) << g.get_name()
             << left << setw(8)  << g.get_age()
             << left << setw(12) << g.get_color()
             << "\n";
    }
}

int select_goat(list<Goat> &trip) {
    if (trip.empty()) {
        cout << "\nNo goats to select.\n";
        return -1;
    }

    cout << "\n";
    int i = 1;
    for (const auto& g : trip) {
        cout << "[" << i << "] "
             << g.get_name() << " ("
             << g.get_age()  << ", "
             << g.get_color() << ")\n";
        i++;
    }
    cout << "Select #: ";

    int pick;
    
}

void delete_goat (list<Goat> &trip){


}