#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

int main()
{
    cout << std::fixed << setprecision(2);
//    cout << "Which file(s) to open?\n";
//    cout << "1. lego1.csv" << endl;
//    cout << "2. lego2.csv" << endl;
//    cout << "3. lego3.csv" << endl;
//    cout << "4. All 3 files" << endl;
    int option;
    cin >> option;
    ifstream file;
    string fileName;
    int track;
    if(option == 1){
        fileName = "lego1.csv";
        track = 1;
    }
    else if(option == 2){
        fileName = "lego2.csv";
        track = 2;
    }
    else if(option == 3){
        fileName = "lego3.csv";
        track = 3;
    }
    else{
        fileName = "lego1.csv";
        track = 1;
    }

    /*======= Load data from file(s) =======*/
    string line;
    int setCount = 0;
    if(option == 1 || option == 2 || option == 3){
        setCount--;
        file.open(fileName);
        while(getline(file, line)){
            setCount++;
        }
    }
    else{
        for(int i = 1; i <= 3; i++){
            setCount--;
            file.close();
            fileName = "lego"+to_string(i)+".csv";
            file.open(fileName);
            while(getline(file, line)){
                setCount++;
            }
        }
    }

//        cout << "1. Most Expensive set" << endl;
//        cout << "2. Largest piece count" << endl;
//        cout << "3. Search for set name containing..." << endl;
//        cout << "4. Search themes..." << endl;
//        cout << "5. Part count information" << endl;
//        cout << "6. Price information" << endl;
//        cout << "7. Minifigure information" << endl;
//        cout << "8. If you bought one of everything..." << endl;
//        cout << "0. Exit" << endl;

        int choice;
        cin >> choice;
        cin.get();  // Clear newline character for any later input

        /*======= Print out how many sets were loaded =======*/
        cout <<"Total number of sets: "<<setCount <<endl<<endl;
        /*======= Based on the choice, execute the appropriate task and show the results =======*/

        string tSetNum;
        string tTheme;
        string tName;
        string tMiniFigures;
        string tPar;
        string tPrice;
        if(choice == 1){
            string setNum;
            string theme;
            string name;
            int parts = 0;
            int miniFigures;
            double price = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        string value;
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                            if(stod(tPrice) > price){
                                price = stod(tPrice);
                                setNum = tSetNum;
                                theme = tTheme;
                                name = tName;
                                miniFigures = stoi(tMiniFigures);
                                parts = stoi(tPar);
                            }
                    }
                }
            cout<<"The most expensive set is: "<<endl;
            cout<<"Name: " << name <<endl;
            cout<<"Number: " << setNum<< endl;
            cout<<"Theme: "<< theme<<endl;
            cout<<"Price: $" << price<<endl;
            cout<<"Minifigures: "<<miniFigures<<endl;
            cout<<"Piece count: " <<parts<<endl;
        }
        else if(choice == 2){
            string setNum;
            string theme;
            string name;
            int parts = 0;
            int miniFig;
            double price = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                        if(stoi(tPar) > parts){
                            price = stod(tPrice);
                            setNum = tSetNum;
                            theme = tTheme;
                            miniFig = stoi(tMiniFigures);
                            name = tName;
                            parts = stoi(tPar);
                        }
                    }
                }
            cout<<"The set with the highest parts count: "<<endl;
            cout<<"Name: " << name <<endl;
            cout<<"Number: " << setNum<< endl;
            cout<<"Theme: "<< theme<<endl;
            cout<<"Price: $" << price<<endl;
            cout<<"Minifigures: "<<miniFig;
            cout<<"Piece count: " <<parts<<endl;
        }
        else if(choice == 3){
            string input;
            getline(cin,input);
            int c = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        string value;
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                            if (tName.find(input) != string::npos) {
                                if (c == 0) {
                                    cout << "Sets matching \"" << input << "\":" << endl;
                                }
                                cout << tSetNum << " " << tName << " $" << stod(tPrice) << endl;
                                c++;
                            }
                        }
                    }
            if(c==0){
                cout<<"No sets found matching that search term"<<endl;
            }
        }
        else if(choice == 4){
            string input;
            getline(cin,input);
            int c = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        string value;
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                            if (tTheme.find(input) != string::npos) {
                                if (c == 0) {
                                    cout << "Sets matching \"" << input << "\":" << endl;
                                }
                                cout << tSetNum << " " << tName << " $" << stod(tPrice) << endl;
                                c++;
                            }
                        }
                    }
            if(c == 0){
                cout<<"No sets found matching that search term"<<endl;
            }
        }
        else if(choice == 5){
            int totalParts = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                        totalParts += stoi(tPar);
                    }
                }
            cout<<"Average part count for "<<setCount<< " sets: "<<totalParts/setCount<<endl;
        }
        else if(choice == 6){
            string minSetNum;
            string minTheme;
            string minName;
            int minPar;
            int minFig;
            double minPrice = 0;
            string maxSetNum;
            string maxTheme;
            string maxName;
            int maxPar;
            int maxFig;
            double maxPrice;
            double total = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                        if(minPrice == 0){
                            minPrice = stod(tPrice);
                            minSetNum = tSetNum;
                            minFig = stoi(tMiniFigures);
                            minTheme = tTheme;
                            minName = tName;
                            minFig = stoi(tMiniFigures);
                            minPar = stoi(tPar);
                            maxPrice = stod(tPrice);
                            maxSetNum = tSetNum;
                            maxTheme = tTheme;
                            maxFig = stoi(tMiniFigures);
                            maxName = tName;
                            maxPar = stoi(tPar);
                        }
                        if(stod(tPrice) < minPrice){
                            minPrice = stod(tPrice);
                            minSetNum = tSetNum;
                            minFig = stoi(tMiniFigures);
                            minTheme = tTheme;
                            minName = tName;
                            minPar = stoi(tPar);
                        }
                        if(stod(tPrice) > maxPrice){
                            maxPrice = stod(tPrice);
                            maxSetNum = tSetNum;
                            maxTheme = tTheme;
                            maxFig = stoi(tMiniFigures);
                            maxName = tName;
                            maxPar = stoi(tPar);
                        }
                        total += stod(tPrice);
                    }
                }
            cout<<"Average price for "<<setCount<<" sets: $"<<total/setCount<<endl<<endl;
            cout<<"Least expensive set: "<<endl;
            cout<<"Name: " << minName <<endl;
            cout<<"Number: " << minSetNum<< endl;
            cout<<"Theme: "<< minTheme<<endl;
            cout<<"Price: $" << minPrice<<endl;
            cout<<"Minifigures: "<<minFig<<endl;
            cout<<"Piece count: " <<minPar<<endl<<endl;
            cout<<"Most expensive set: "<<endl;
            cout<<"Name: " << maxName <<endl;
            cout<<"Number: " << maxSetNum<< endl;
            cout<<"Theme: "<< maxTheme<<endl;
            cout<<"Price: $" << maxPrice<<endl;
            cout<<"Minifigures: "<<maxFig<<endl;
            cout<<"Piece count: " <<maxPar<<endl;
        }
        else if(choice == 7){
            string maxSetNum;
            string maxTheme;
            string maxName;
            int maxMini = 0;
            int maxPar;
            double maxPrice;
            int total = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                        if(stoi(tMiniFigures) > maxMini){
                            maxPrice = stod(tPrice);
                            maxSetNum = tSetNum;
                            maxTheme = tTheme;
                            maxName = tName;
                            maxMini = stoi(tMiniFigures);
                            maxPar = stoi(tPar);
                        }
                        total += stoi(tMiniFigures);
                    }
                }
            cout<<"Average number of minifigures: "<<total/setCount<<endl<<endl;
            cout<<"Set with the most minifigures: "<<endl;
            cout<<"Name: " << maxName <<endl;
            cout<<"Number: " << maxSetNum<< endl;
            cout<<"Theme: "<< maxTheme<<endl;
            cout<<"Price: $" << maxPrice<<endl;
            cout<<"Minifigures: "<<maxMini<<endl;
            cout<<"Piece count: " <<maxPar<<endl<<endl;
        }
        else if(choice == 8){
            int figures = 0;
            int part = 0;
            double totalPrice = 0;
                for(int i = track; i <= option; i++){
                    file.close();
                    fileName = "lego"+to_string(i)+".csv";
                    file.open(fileName);
                    getline(file, line);
                    while(getline(file, line)){
                        stringstream str(line);
                        getline(str, tSetNum, ',');
                        getline(str, tTheme, ',');
                        getline(str, tName, ',');
                        getline(str, tMiniFigures, ',');
                        getline(str, tPar, ',');
                        getline(str, tPrice);
                        figures += stoi(tMiniFigures);
                        part += stoi(tPar);
                        totalPrice += stod(tPrice);
                    }
                }
            cout<<"If you bought one of everything..."<<endl;
            cout<<"It would cost: $"<<totalPrice<<endl;
            cout<<"You would have "<<part<<" pieces in your collection"<<endl;
            cout<<"You would have an army of "<<figures<<" minifigures!"<<endl;
        }
    return 0;
}


