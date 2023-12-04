// Written by Nile Barfield for 2023 codeo 12/1 challenge last edited 12/3/2023
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int concatNum(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    string s = s1 + s2;
    return stoi(s);
}

int main()
{
    int sum = 0;
    vector<vector<int>> vec;
    vector<int> newNum;
    string line;
    ifstream file;
    int column = 0;

    // file manipulation and storage of nums
    file.open("TestCase1.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            vec.push_back(vector<int>());
            for (int i = 0; i < line.length(); i++)
            {
                if (isdigit(line[i]))
                {
                    vec[column].push_back(line[i] - 48);
                    break;
                }
            }
            for (int i = line.length(); i > 0; i--)
            {
                if (isdigit(line[i]))
                {
                    vec[column].push_back(line[i] - 48);
                    break;
                }
            }
            column++;
        }
    }
    file.close();

    // concatonating the numbers in each row
    for (int i = 0; i < vec.size(); i++)
    {
        int a = vec[i][0];
        int b = vec[i][1];
        newNum.push_back(concatNum(a, b));
    }

    // adding up the new numbers from each row
    for (int i = 0; i < newNum.size(); i++)
    {
        sum += newNum[i];
    }

    // printing
    cout << sum << endl;

    return 0;
}