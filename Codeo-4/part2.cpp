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
    int totalCards = 0;
    int card = 0;
    //change amount according to number of winning numbers
    vector<int> x(10,1);

    //file manipulation
    ifstream file;
    string line;
    file.open("input2.txt");
    while (getline(file, line)){
        x.push_back(1);
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

        auto start = x.begin() + card + 1;
        auto end = min(start + matches, x.end());
        transform(start, end, start, [&x, card](int n) { return n + x[card]; });
        totalCards += x[card];
        card++;
    }
    file.close();

    cout << totalCards << endl;
    return 0;
}