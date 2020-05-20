#include <iostream>
#include <string>
#include <map>

using namespace std;

int ConvertToModernNumber(string userNumerals); //converts roman numerals to modern numbers
string ConvertToRomanNumerals(int num); //converts modern numbers to roman numerals

int main() {
    string userOption;
    bool continueLoop = true;
    int modernYear;
    string userRomanNumerals;

    //loop to check what the user wants to convert
    cout << "Do you want to convert a roman numeral or a modern year?" << endl;
    while (continueLoop) {
        getline(cin, userOption);

        if (userOption == "modern year") {

            cout << "Please enter modern year: " << endl;
            cin >> modernYear;

            cout << "Roman Numerals: " << ConvertToRomanNumerals(modernYear) << endl;

            //allows the user to choose to enter another option without exiting the program
            cout << endl;
            cout << "Do you want to check another number? Enter Y or N" << endl;
            cin >> userOption;
            if (userOption == "Y") {
                continueLoop = true;
            }
            else {
                continueLoop = false;
            }
        }
        else if (userOption == "roman numeral") {

            cout << "Please enter the roman numerals: " << endl;
            cin >> userRomanNumerals;

            cout << "Modern Numbers: " << ConvertToModernNumber(userRomanNumerals) << endl;

            //allows the user to choose to enter another option without exiting the program
            cout << endl;
            cout << "Do you want to check another number? Enter Y or N" << endl;
            cin >> userOption;
            if (userOption == "Y") {
                continueLoop = true;
            }
            else {
                continueLoop = false;
            }
        } else {
            cout << R"(Please enter "modern year" or "roman numeral" only: )" << endl;
            continueLoop = true;
        }
    }

    return 0;
}

int ConvertToModernNumber(string userNumerals) {   //converts roman numerals to modern numbers
    map<char , int> romNum;
    romNum.insert(pair<char , int>('M', 1000));
    romNum.insert(pair<char , int>('D', 500));
    romNum.insert(pair<char , int>('C', 100));
    romNum.insert(pair<char , int>('L', 50));
    romNum.insert(pair<char , int>('X', 10));
    romNum.insert(pair<char , int>('V', 5));
    romNum.insert(pair<char , int>('I', 1));

    int sum = 0;

    for (int i = 0; i < userNumerals.size(); ++i) {
        if (romNum[userNumerals[i + 1]] > romNum[userNumerals[i]]){   //subtraction notation
            int difference = 0;
            difference = romNum[userNumerals[i + 1]] - romNum[userNumerals[i]];
            sum = sum + difference;
            i++;
        }
        else {   //normal addition of roman numerals
            sum = sum + romNum[userNumerals[i]];
        }
    }
    return sum;
}

string ConvertToRomanNumerals(int num){ //converts modern numbers to roman numerals
    string romanNumerals;

    if (num >= 1000) {
        int value = num / 1000;
        for (int i = 0; i < value; ++i) {
            romanNumerals += "M";
        }
        num = num % 1000;
    }

    if (num >= 900) {
        romanNumerals += "CM";
        num = num % 900;
    }
    else if (num >= 500) {
        int value = num / 500;
        for (int i = 0; i < value; ++i) {
            romanNumerals += "D";
        }
        num = num % 500;
    }

    if (num >= 400) {
        romanNumerals += "CD";
        num = num % 400;
    }
    else if (num >= 100) {
        int value = num / 100;
        for (int i = 0; i < value; ++i){
            romanNumerals += "C";
        }
        num = num % 100;
    }

    if (num >= 90) {
        romanNumerals += "XC";
        num = num % 90;
    }
    else if (num >= 50) {
        int value = num / 50;
        for (int i = 0; i < value; ++i) {
            romanNumerals += "L";
        }
        num = num % 50;
    }

    if (num >= 40) {
        romanNumerals += "XL";
        num = num % 40;
    }
    else if (num >= 10) {
        int value = num / 10;
        for (int i = 0; i < value; ++i) {
            romanNumerals += "X";
        }
        num = num % 10;
    }

    if (num >= 9) {
        romanNumerals += "IX";
        num = num % 9;
    }
    else if (num >= 5) {
        int value = num / 5;
        for (int i = 0; i < value; ++i) {
            romanNumerals += "V";
        }
        num = num % 5;
    }

    if (num >= 4) {
        romanNumerals += "IV";
        num = num % 4;
    }
    else if (num >= 1) {
        int value = num / 1;
        for (int i = 0; i < value; ++i) {
            romanNumerals += "I";
        }
    }

    return romanNumerals;
}