#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    string title;
    string oneHeader;
    string twoHeader;
    int num = 1;
    vector<string> authors(num);
    vector<int> numBooks(num);


    cout << "Enter a title for the data:"<<endl;
    getline(cin, title);
    cout << "You entered: "<<title<<endl<< "Enter the column 1 header:"<<endl;
    getline(cin, oneHeader);
    cout << "You entered: "<< oneHeader<<endl<< "Enter the column 2 header:"<<endl;
    getline(cin, twoHeader);
    cout<<"You entered: " <<twoHeader<<endl;
    bool end = false;
    while(end==false){
        string newInput;
        string preComma;
        string postComma;
        int numberPostComma;
        bool error = false;
        cout<<"Enter a data point (-1 to stop input):"<<endl;
        getline(cin, newInput);
        if(newInput == "-1"){
            end = true;
            cout<<endl;
            break;
        }
        for(int i = 0; i < (int)newInput.size(); i++){
            if(newInput.at(i) == ','){
                preComma = newInput.substr(0,i);
                postComma = newInput.substr(i+2, newInput.size()-i+1);
                for(int j = 0; j < (int)postComma.size(); j++){
                    if(postComma.at(j) == ','){
                        cout<<"Error: Too many commas in input."<<endl;
                        error = true;
                        break;
                    }
                }
                break;
            }
            else if(i == (int)newInput.size()-1){
                error = true;
                cout<<"Error: No comma in string."<<endl;
            }
        }
        if(error == true){
            continue;
        }
        try{
            numberPostComma = stoi(postComma);
        }
        catch(invalid_argument){
            error = true;
            cout<<"Error: Comma not followed by an integer."<<endl;
        }
        if(error == true){
            continue;
        }
        cout<<"Data string: "<<preComma<<endl;
        cout<<"Data integer: "<<numberPostComma<<endl;
        authors.resize(num);
        numBooks.resize(num);
        authors.at(num-1) = preComma;
        numBooks.at(num-1) = numberPostComma;
        num++;
    }
    cout<<setw(33)<<title<<endl;
    cout<<oneHeader<<setw(20-oneHeader.size()+1)<<"|"<<setw(23)<<twoHeader<<endl;
    cout<<"--------------------------------------------"<<endl;
    for(int i = 0; i < (int)authors.size(); i++){
        cout<<authors.at(i)<<setw(20-authors.at(i).size()+1)<<"|"<<setw(23)<<numBooks.at(i)<<endl;
    }
    cout<<endl;
    for(int i = 0; i < (int)authors.size(); i++){
        cout<<setw(20)<<authors.at(i)<<" ";
        for(int j = 0; j < numBooks.at(i); j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
