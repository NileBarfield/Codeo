// Written by Nile Barfield for 2023 codeo 12/2 challenge last edited 12/16/2023
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <cmath>
using namespace std;

int main()
{
    int totalPoints = 0;
    int card = 0;

    //file manipulation
    ifstream file;
    string line;
    file.open("input2.txt");
    while (getline(file, line)){
        int matches = 0;
        string num;
        vector<std::string> winning;
        istringstream lstream(line);
        getline(lstream, num, ':');
        while (getline(lstream, num, ' ')){
            if (num.empty()){
                continue;
            }
            if (find(winning.begin(), winning.end(), num) != winning.end()){
                matches += 1;
            }
            else if (winning.size() < 10){
                winning.push_back(num);
            }
        }
        card++;
        totalPoints += pow(2, matches-1);
    }
    file.close();

    cout << totalPoints << endl;
    return 0;
}