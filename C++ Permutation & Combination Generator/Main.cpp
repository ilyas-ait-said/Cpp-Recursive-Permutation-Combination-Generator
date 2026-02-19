#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void CheckIntInput(int& choice)
{
    while (cin.fail()) {
        cout << "Invalid input..." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Please try again :";
        cin >> choice;
    }
}
void permute(vector<int>& arr, int start , ofstream& file)
{
    if (start == arr.size() - 1)
    {
        for (int i = 0; i < arr.size(); i++) {
            file << arr[i] << " ";
        }
        file << endl;
        return;
    } 
    for (int i = start; i < arr.size();i++) {
        swap(arr[start], arr[i]);
        permute(arr, start + 1, file);
        swap(arr[start], arr[i]);
    }
}
void GeneratCombinations(vector<int>& curr_combinations, int AddDigits, ofstream& DigitsFile) {
    
    if (AddDigits == 0) {
        for (int i = 0; i < curr_combinations.size(); i++) {
            int digits = curr_combinations[i];
            DigitsFile << digits;
        }
        DigitsFile << endl;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        curr_combinations.push_back(i);
        GeneratCombinations(curr_combinations, AddDigits - 1, DigitsFile);
        curr_combinations.pop_back();
    }
}
int main()
{
    while (true) {
        cout << "--Select which technology do you want--\n" <<
            "1.Permutations\n" <<
            "2.Combinations\n" <<
            "3.Exit\n" <<
            "Choose a number :";
        int select;
        
        cin >> select;
        CheckIntInput(select);
        if (select == 1) {
            ofstream file("Permutations.txt");
            if (!file) {
                cout << "Error opening file.\nPlease check the disk space || Directory permissions...\n";
                continue;  
            }
            int n;
            cout << "How many numbers? ";
            cin >> n;
            CheckIntInput(n);
            if (n <= 0 || n > 6) {
                cout << "Input too large or a negative number. Please choose between 0 and 6." << endl;
                continue;
            }
            else {
                vector<int> arr;
                for (int i = 0; i < n; i++) {
                    cout << "what is the number " << i + 1 << " :";
                    int num;
                    cin >> num;
                    CheckIntInput(num);
                    arr.push_back(num);
                }
                file << "Permutations:" << endl;
                permute(arr, 0, file);
                file.close();
                cout << "Permutations saved, Check the [Permutations.txt] inside the directory" << endl;
            }
            
        }
        else if (select == 2) {
            ofstream DigitsFile("Digits.txt");
            if (!DigitsFile) {
                cout << "Error opening file.\nPlease check the disk space || Directory permissions...\n";
                continue; 
            }
            int AddDigits;
            bool CheckNum = true;
            while (CheckNum){
                
                cout << "How many digits(the big number you choose the more time it takes to generate)? ";
                cin >> AddDigits;
                CheckIntInput(AddDigits);
                if (AddDigits < 0 || AddDigits > 6) {
                    cout << "Input too large. Please choose between 0 and 6." << endl;
                    continue;
                }
                else {
                    vector<int> curr_combination;
                    GeneratCombinations(curr_combination, AddDigits, DigitsFile);
                    cout << "Combinations saved, Check the [Digits.txt] inside the directory" << endl;
                    CheckNum = false;
                }
            }
        }
        else if (select == 3) {
            cout << "Exiting the program...\n";
            break;
        }
        else {
            cout << "Please choose only the appeard numbers..."<<endl;
        }
    }
    return 0;
}