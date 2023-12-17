// Written by Nile Barfield for 2023 codeo 12/2 challenge last edited 12/16/2023
// bounds are red = 12, green = 13, blue = 14
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;

int calc(string line, int gameNum, bool possible){
    vector<int> max = {12, 13, 14};
    vector<regex> pattern = {regex("([0-9]+) red"), regex("([0-9]+) green"), regex("([0-9]+) blue")};

    for (int i = 0; i < pattern.size(); i++){
        sregex_iterator begin(line.begin(), line.end(), pattern[i]);
        sregex_iterator end;

        for (sregex_iterator x = begin; x != end; x++){
            int val = stoi((*x)[1]);
            if (val < max[i]){
                continue;
            }
            possible = false;
            if (possible == false){
                return 0;
            }
        }
    }
    cout << gameNum << " ";
    return gameNum;
}


int main()
{
    int sum = 0;
    int gameNum = 0;
    bool possible = true;
    vector<string> vec;

    //file manipulation
    ifstream file;
    string line;
    file.open("input1.txt");
    while (getline(file, line)){
        gameNum++;
        sum += calc(line, gameNum, possible);
    }
    file.close();

    cout << endl << sum << endl;

    return 0;
}