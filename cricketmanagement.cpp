#include <iostream> 
#include <fstream> 
#include <string>
using namespace std;

const int SIZE = 100; 
int playercount = 0; 

string name[SIZE], surname[SIZE], role[SIZE], btype[SIZE], medical[SIZE]; 
int age[SIZE], match[SIZE], run[SIZE], wicket[SIZE], salary[SIZE];
float avg[SIZE], strikeRate[SIZE], bavg[SIZE], bonus[SIZE], eco[SIZE], fine[SIZE];

void login() 
{ 
    string user;
    int pass;
    
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%        CRICKET TEAM MANAGEMENT SYSTEM           %%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "              Login to proceed further!              " << endl;
    
    while(true) {
        cout << "\nEnter Username: ";
        getline(cin, user); 
        cout << "Enter Password: ";
        cin >> pass;
        cin.ignore();
        
        if(user == "mohsin naqvi" && pass == 248) {
            cout << "\nLogin Successful!\n" << endl;
            break;
        } else {
            cout << "\nWRONG USERNAME OR PASSWORD!\n" << endl;
        }
    }
}

void showMenu() 
{ 
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%%        CRICKET TEAM MANAGEMENT SYSTEM           %%" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "1. T20 Series dates" << endl;
    cout << "2. Add player's details" << endl;
    cout << "3. Add performance details" << endl;
    cout << "4. View all players" << endl;
    cout << "5. View Rankings" << endl;
    cout << "6. Bonus details" << endl;
    cout << "7. Fee deduction & fines" << endl;
    cout << "8. Save data to file" << endl;
    cout << "9. Selection status" << endl;
    cout << "10. Exit" << endl;
    cout << "Select option: ";
}

void showSeriesDates()
{ 
    cout << "\nPakistan vs. England (T20I): 20 Jan 2025 to 5 Feb 2025 - Karachi" << endl; 
    cout << "Pakistan vs. Australia (T20I): 15 Feb 2025 to 1 Mar 2025 - Perth" << endl; 
}

void inputPlayers()
{ 
    if (playercount >= SIZE) { 
        cout << "\nLimit Reached!" << endl;
        return;
    } 

    cout << "\nEnter details for Player " << playercount + 1 << ":" << endl;
    cout << "Name: ";
    cin >> name[playercount]; 
    cout << "Surname: ";
    cin >> surname[playercount];
    cout << "Enter the role (batsman/bowler): ";
    cin >> role[playercount];
    cout << "Total matches played: ";
    cin >> match[playercount];
    cout << "Age: "; 
    cin >> age[playercount];
    cout << "Medical Condition (fit/unfit): ";
    cin >> medical[playercount];

    playercount++;
    cout << "Player added successfully!" << endl;
}

void inputPerformance() 
{ 
    if (playercount == 0) { 
        cout << "\nNo record found!" << endl;
        return; 
    }

    cout << "\nEnter Performance details:" << endl;
    for (int i = 0; i < playercount; i++) { 
        cout << "\nEnter performance details of " << name[i] << ":" << endl;
        
        if (role[i] == "bowler") {
            cout << "Enter the bowling format (spin/fast/mediumpacer): ";
            cin >> btype[i]; 
            cout << "Enter total wickets taken: ";
            cin >> wicket[i];
            cout << "Bowling Average speed (km/h): "; 
            cin >> bavg[i];
            cout << "Economy Rate: "; 
            cin >> eco[i];

            if (btype[i] == "fast" && bavg[i] >= 145 && eco[i] <= 6)
                salary[i] = 400000;
            else if (btype[i] == "fast" && bavg[i] >= 138.5 && eco[i] <= 9)
                salary[i] = 200000;
            else if (btype[i] == "mediumpacer" && bavg[i] >= 105 && eco[i] <= 6)
                salary[i] = 400000;
            else if (btype[i] == "mediumpacer" && bavg[i] >= 80.5 && eco[i] <= 9)
                salary[i] = 200000;
            else if (btype[i] == "spin" && eco[i] <= 6)
                salary[i] = 400000;
            else if (btype[i] == "spin" && eco[i] <= 10)
                salary[i] = 200000;
            else
                salary[i] = 100000;
        } else {
            cout << "Enter total runs scored: ";
            cin >> run[i];
            cout << "Average Run Rate: ";
            cin >> avg[i];
            cout << "Strike Rate: ";
            cin >> strikeRate[i];

            if (avg[i] >= 50 && strikeRate[i] >= 170)
                salary[i] = 400000;
            else if (avg[i] >= 30 && strikeRate[i] >= 120)
                salary[i] = 200000;
            else
                salary[i] = 100000;
        }
    }
}

void viewPlayers() 
{
    if (playercount == 0) {
        cout << "\nNo record found!" << endl;
        return;
    }
    
    for (int i = 0; i < playercount; i++) { 
        cout << "\n-----------------------------------" << endl;
        cout << "Player " << (i + 1) << ": " << name[i] << " " << surname[i] << endl;
        cout << "Role: " << role[i] << endl; 
        cout << "Age: " << age[i] << endl;
        cout << "Total matches played: " << match[i] << endl;
        cout << "Medical: " << medical[i] << endl; 

        if (role[i] == "bowler") {
            cout << "Total wickets taken: " << wicket[i] << endl;
            cout << "Bowling style: " << btype[i] << endl; 
            cout << "Average speed: " << bavg[i] << endl; 
            cout << "Economy Rate: " << eco[i] << endl; 
        } else {
            cout << "Total runs scored: " << run[i] << endl;
            cout << "Average: " << avg[i] << endl; 
            cout << "Strike Rate: " << strikeRate[i] << endl;
        } 
        cout << "Salary: Rs. " << salary[i] << endl;
    } 
}

void showRankings() {
    if (playercount == 0) {
        cout << "\nNo record found!" << endl;
        return;
    }

    cout << "\nBOWLER RANKINGS (By Economy - Lowest Best):" << endl;
    int bRank = 1;
    for (int i = 0; i < playercount; i++) {
        if (role[i] == "bowler") {
            cout << bRank++ << ". " << name[i] << " " << surname[i] << " - Eco: " << eco[i] << endl;
        }
    }

    cout << "\nBATSMAN RANKINGS (By Average & SR):" << endl;
    int batRank = 1;
    for (int i = 0; i < playercount; i++) {
        if (role[i] != "bowler") {
            cout << batRank++ << ". " << name[i] << " " << surname[i] << " - Avg: " << avg[i] << ", SR: " << strikeRate[i] << endl;
        }
    }
}

void calculateBonus() 
{ 
    if (playercount == 0) {
        cout << "\nNo record found!" << endl; 
        return;
    }
    
    for (int i = 0; i < playercount; i++) { 
        if ((role[i] == "bowler" && eco[i] <= 5.7) || (role[i] != "bowler" && avg[i] >= 50 && strikeRate[i] >= 170)) { 
            bonus[i] = salary[i] + (salary[i] * 0.10); 
            cout << name[i] << "'s salary with bonus: Rs. " << bonus[i] << endl;
        } else {
            cout << name[i] << " is not eligible for bonus." << endl;
        } 
    }
}

void calculateFine() 
{ 
    if (playercount == 0) { 
        cout << "\nNo record found!" << endl; 
        return; 
    }
    
    for (int i = 0; i < playercount; i++) { 
        if ((role[i] == "bowler" && eco[i] >= 12) || (role[i] != "bowler" && avg[i] < 30 && strikeRate[i] < 135)) { 
            fine[i] = salary[i] - (salary[i] * 0.10);
            cout << name[i] << "'s salary after fine: Rs. " << fine[i] << endl;
        } else {
            cout << name[i] << " is not fined." << endl; 
        } 
    } 
}

void saveToFile() 
{
    if (playercount == 0) { 
        cout << "\nNo record found!" << endl; 
        return; 
    } 
    
    ofstream file("players.txt", ios::app); 
    for (int i = 0; i < playercount; i++) { 
        file << "Player " << i + 1 << ":" << endl;
        file << "Name: " << name[i] << " " << surname[i] << endl;
        file << "Role: " << role[i] << endl;
        file << "Total matches played: " << match[i] << endl;
        file << "Age: " << age[i] << endl; 
        file << "Medical: " << medical[i] << endl; 
        
        if (role[i] == "bowler") {
            file << "Total wickets taken: " << wicket[i] << endl;
            file << "Bowling style: " << btype[i] << endl;
            file << "Average speed: " << bavg[i] << endl;
            file << "Economy Rate: " << eco[i] << endl; 
        } else {
            file << "Total runs scored: " << run[i] << endl;
            file << "Average Runrate: " << avg[i] << endl;
            file << "Strike Rate: " << strikeRate[i] << endl;
        } 
        file << "Salary: Rs. " << salary[i] << endl;
        file << "-----------------------------------\n";
    } 
    file.close(); 
    cout << "\nData saved to players.txt successfully!" << endl;
}

void selection() 
{
    if (playercount == 0) { 
        cout << "\nNo records found." << endl;
        return;
    } 
    
    for (int i = 0; i < playercount; i++) { 
        if ((role[i] != "bowler" && avg[i] >= 30 && strikeRate[i] >= 141.5 && medical[i] == "fit") || 
            (role[i] == "bowler" && eco[i] <= 11 && medical[i] == "fit")) { 
            cout << name[i] << " " << surname[i] << ": SELECTED!" << endl;
        } else {
            cout << name[i] << " " << surname[i] << ": Better Luck Next time!" << endl;
        }
    }
}

int main() 
{
    int opt;
    login(); 
    
    while (true) { 
        showMenu();
        cin >> opt;
        
        if (opt == 1)
            showSeriesDates();
        else if (opt == 2) 
            inputPlayers(); 
        else if (opt == 3) 
            inputPerformance(); 
        else if (opt == 4) 
            viewPlayers(); 
        else if (opt == 5)
            showRankings();
        else if (opt == 6) 
            calculateBonus(); 
        else if (opt == 7) 
            calculateFine(); 
        else if (opt == 8) 
            saveToFile(); 
        else if (opt == 9) 
            selection(); 
        else if (opt == 10) { 
            cout << "\nExiting System..." << endl;
            break; 
        } else { 
            cout << "\nInvalid choice." << endl;
        }
    }
    return 0; 
}