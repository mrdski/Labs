#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Arm{
    string name;
    int power = 0;
    double consumption;
};
struct Ship{
    string name;
    string clas;
    int length;
    int shield;
    float warp;
    int armCount;
    vector<Arm> arms;
    int power;
    int totalP = 0;
};

int main()
{
//    cout << "Which file(s) to open?\n";
//    cout << "1. friendlyships.shp" << endl;
//    cout << "2. enemyships.shp" << endl;
//    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    ifstream file;
    ifstream file2;
    string fileName;

    if(option == 1){
        fileName = "friendlyships.shp";
        file.open(fileName, ios::binary);
    }
    else if(option == 2){
        fileName = "enemyships.shp";
        file.open(fileName, ios::binary);
    }
    else{
        fileName = "friendlyships.shp";
        file.open(fileName, ios::binary);
        fileName = "enemyships.shp";
        file2.open(fileName);
    }
    /* Load files here */

//    int numShips;
    vector<Ship> ships;
    vector<Arm> arms;

    if(option == 1 || option == 2){
        int value;
        int nameL;
        int clasL;
        int armC;
        file.read((char*)&value, 4);
//        numShips = value;
        for(int i = 0; i < value; i++){
            Ship ship;
            file.read((char*)&nameL, sizeof (nameL));
            char* buffer = new char[nameL];
            file.read(buffer, nameL);
            ship.name = buffer;
            delete[] buffer;
            file.read((char*)&clasL, sizeof(clasL));
            buffer = new char[clasL];
            file.read(buffer, clasL);
            string buffer3 = buffer;
            delete[] buffer;
            ship.clas = buffer3;
            short l;
            file.read((char*)&l, 2);
            ship.length = l;
            int s;
            file.read((char*)&s, 4);
            ship.shield = s;
            float w;
            file.read((char*)&w, 4);
            ship.warp = w;
            int fC;
            file.read((char*)&fC, 4);
            ship.armCount = fC;
            if(fC > 0){
                for(int i = 0; i < fC; i++){
                    Arm arm;
                    file.read((char*)&armC, 4);
                    buffer = new char[armC];
                    file.read(buffer, armC);
                    string armN = buffer;
                    delete[] buffer;
                    arm.name = armN;
                    int power;
                    file.read((char*)&power, 4);
                    arm.power = power;
                    float consum;
                    file.read((char*)&consum, 4);
                    arm.consumption = consum;
                    ship.arms.push_back(arm);
                }
            }
            ships.push_back(ship);
        }
    }
    else{
        int value;
        int nameL;
        int clasL;
        int armC;
        file.read((char*)&value, 4);
//        numShips = value;
        for(int i = 0; i < value; i++){
            Ship ship;
            file.read((char*)&nameL, sizeof (nameL));
            char* buffer = new char[nameL];
            file.read(buffer, nameL);
            ship.name = buffer;
            delete[] buffer;
            file.read((char*)&clasL, sizeof(clasL));
            buffer = new char[clasL];
            file.read(buffer, clasL);
            string buffer3 = buffer;
            delete[] buffer;
            ship.clas = buffer3;
            short l;
            file.read((char*)&l, 2);
            ship.length = l;
            int s;
            file.read((char*)&s, 4);
            ship.shield = s;
            float w;
            file.read((char*)&w, 4);
            ship.warp = w;
            int fC;
            file.read((char*)&fC, 4);
            ship.armCount = fC;
            if(fC > 0){
                for(int i = 0; i < fC; i++){
                    Arm arm;
                    file.read((char*)&armC, 4);
                    buffer = new char[armC];
                    file.read(buffer, armC);
                    string armN = buffer;
                    delete[] buffer;
                    arm.name = armN;
                    int power;
                    file.read((char*)&power, 4);
                    arm.power = power;
                    float consum;
                    file.read((char*)&consum, 4);
                    arm.consumption = consum;
                    ship.arms.push_back(arm);
                }
            }
            ships.push_back(ship);
        }
        file2.read((char*)&value, 4);
//        numShips = value;
        for(int i = 0; i < value; i++){
            Ship ship;
            file2.read((char*)&nameL, sizeof (nameL));
            char* buffer = new char[nameL];
            file2.read(buffer, nameL);
            ship.name = buffer;
            delete[] buffer;
            file2.read((char*)&clasL, sizeof(clasL));
            buffer = new char[clasL];
            file2.read(buffer, clasL);
            string buffer3 = buffer;
            delete[] buffer;
            ship.clas = buffer3;
            short l;
            file2.read((char*)&l, 2);
            ship.length = l;
            int s;
            file2.read((char*)&s, 4);
            ship.shield = s;
            float w;
            file2.read((char*)&w, 4);
            ship.warp = w;
            int fC;
            file2.read((char*)&fC, 4);
            ship.armCount = fC;
            if(fC > 0){
                for(int i = 0; i < fC; i++){
                    Arm arm;
                    file2.read((char*)&armC, 4);
                    buffer = new char[armC];
                    file2.read(buffer, armC);
                    string armN = buffer;
                    delete[] buffer;
                    arm.name = armN;
                    int power;
                    file2.read((char*)&power, 4);
                    arm.power = power;
                    float consum;
                    file2.read((char*)&consum, 4);
                    arm.consumption = consum;
                    ship.arms.push_back(arm);
                }
            }
            ships.push_back(ship);
        }
    }
//    cout << "1. Print all ships" << endl;
//    cout << "2. Starship with the strongest weapon" << endl;
//    cout << "3. Strongest starship overall" << endl;
//    cout << "4. Weakest ship (ignoring unarmed)" << endl;
//    cout << "5. Unarmed ships" << endl;

    cin >> option;

    /* Work your magic here */

    if(option == 1){
        for(unsigned int i = 0; i < ships.size(); i++){
            cout<<"Name: "<<ships[i].name<<endl;
            cout<<"Class: "<<ships[i].clas<<endl;
            cout<<"Length: "<<ships[i].length<<endl;
            cout<<"Shield capacity: "<<ships[i].shield<<endl;
            cout<<"Maximum Warp: "<<ships[i].warp<<endl;
            cout<<"Armaments: "<<endl;
            if(ships[i].arms.size()==0){
                cout<<"Unarmed"<<endl;
            }
            else{
                int totalF = 0;
                for(unsigned int j = 0; j < ships[i].arms.size(); j++){
                    cout<<ships[i].arms[j].name<<", "<<ships[i].arms[j].power<<", "<<ships[i].arms[j].consumption<<endl;
                    totalF += ships[i].arms[j].power;
                }
                cout<<endl<<"Total firepower: "<<totalF<<endl<<endl;
            }
        }
    }
    else if(option == 2){
        Ship ship;
        int topP = 0;
        for(unsigned int i = 0; i < ships.size(); i++){
            for(unsigned int j = 0; j < ships[i].arms.size(); j++){
                if(ships[i].arms[j].power > topP){
                    topP = ships[i].arms[j].power;
                    ship = ships[i];
                }
            }
        }
        cout<<"Name: "<<ship.name<<endl;
        cout<<"Class: "<<ship.clas<<endl;
        cout<<"Length: "<<ship.length<<endl;
        cout<<"Shield capacity: "<<ship.shield<<endl;
        cout<<"Maximum Warp: "<<ship.warp<<endl;
        cout<<"Armaments: "<<endl;
        if(ship.arms.size()==0){
            cout<<"Unarmed"<<endl;
        }
        else{
            int totalF = 0;
            for(unsigned int j = 0; j < ship.arms.size(); j++){
                cout<<ship.arms[j].name<<", "<<ship.arms[j].power<<", "<<ship.arms[j].consumption<<endl;
                totalF += ship.arms[j].power;
            }
            cout<<endl<<"Total firepower: "<<totalF<<endl<<endl;
        }
    }
    else if(option == 3){
        Ship ship = ships[0];
        for(unsigned int i = 0; i < ships.size(); i++){
            int totalF = 0;
            for(unsigned int j = 0; j < ships[i].arms.size(); j++){
                totalF += ships[i].arms[j].power;
            }
            ships[i].totalP = totalF;
        }
        for(unsigned int i = 1; i < ships.size(); i++){
            if(ships[i].totalP>ship.totalP){
                ship = ships[i];
            }
        }
        cout<<"Name: "<<ship.name<<endl;
        cout<<"Class: "<<ship.clas<<endl;
        cout<<"Length: "<<ship.length<<endl;
        cout<<"Shield capacity: "<<ship.shield<<endl;
        cout<<"Maximum Warp: "<<ship.warp<<endl;
        cout<<"Armaments: "<<endl;
        if(ship.arms.size()==0){
            cout<<"Unarmed"<<endl;
        }
        else{
            int totalF = 0;
            for(unsigned int j = 0; j < ship.arms.size(); j++){
                cout<<ship.arms[j].name<<", "<<ship.arms[j].power<<", "<<ship.arms[j].consumption<<endl;
                totalF += ship.arms[j].power;
            }
            cout<<endl<<"Total firepower: "<<totalF<<endl<<endl;
        }
    }
    else if(option == 4){
        Ship ship;
        for(unsigned int i = 0; i < ships.size(); i++){
            int totalF = 0;
            for(unsigned int j = 0; j < ships[i].arms.size(); j++){
                totalF += ships[i].arms[j].power;
            }
            ships[i].totalP = totalF;
            if(totalF>0){
                ship = ships[i];
            }
        }
        for(unsigned int i = 0; i < ships.size(); i++){
            if(ship.totalP>ships[i].totalP && !ships[i].arms.empty()){
                ship = ships[i];
            }
        }
        cout<<"Name: "<<ship.name<<endl;
        cout<<"Class: "<<ship.clas<<endl;
        cout<<"Length: "<<ship.length<<endl;
        cout<<"Shield capacity: "<<ship.shield<<endl;
        cout<<"Maximum Warp: "<<ship.warp<<endl;
        cout<<"Armaments: "<<endl;
        if(ship.arms.size()==0){
            cout<<"Unarmed"<<endl;
        }
        else{
            int totalF = 0;
            for(unsigned int j = 0; j < ship.arms.size(); j++){
                cout<<ship.arms[j].name<<", "<<ship.arms[j].power<<", "<<ship.arms[j].consumption<<endl;
                totalF += ship.arms[j].power;
            }
            cout<<endl<<"Total firepower: "<<totalF<<endl<<endl;
        }
    }
    else{
        for(unsigned int i = 0; i < ships.size(); i++){
            if(ships[i].arms.empty()){
                cout<<"Name: "<<ships[i].name<<endl;
                cout<<"Class: "<<ships[i].clas<<endl;
                cout<<"Length: "<<ships[i].length<<endl;
                cout<<"Shield capacity: "<<ships[i].shield<<endl;
                cout<<"Maximum Warp: "<<ships[i].warp<<endl;
                cout<<"Armaments: "<<endl;
                cout<<"Unarmed"<<endl<<endl;
            }
        }
    }

    return 0;
}
//
//#include <iomanip>
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <sstream>
//
//
//using namespace std;
//
//int main()
//{
//    cout << std::fixed << setprecision(2);
////    cout << "Which file(s) to open?\n";
////    cout << "1. lego1.csv" << endl;
////    cout << "2. lego2.csv" << endl;
////    cout << "3. lego3.csv" << endl;
////    cout << "4. All 3 files" << endl;
//    int option;
//    cin >> option;
//    ifstream file;
//    string fileName;
//    int track;
//    if(option == 1){
//        fileName = "lego1.csv";
//        track = 1;
//    }
//    else if(option == 2){
//        fileName = "lego2.csv";
//        track = 2;
//    }
//    else if(option == 3){
//        fileName = "lego3.csv";
//        track = 3;
//    }
//    else{
//        fileName = "lego1.csv";
//        track = 1;
//    }
//
//    /*======= Load data from file(s) =======*/
//    string line;
//    int setCount = 0;
//    if(option == 1 || option == 2 || option == 3){
//        setCount--;
//        file.open(fileName);
//        while(getline(file, line)){
//            setCount++;
//        }
//    }
//    else{
//        for(int i = 1; i <= 3; i++){
//            setCount--;
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            while(getline(file, line)){
//                setCount++;
//            }
//        }
//    }
//
////        cout << "1. Most Expensive set" << endl;
////        cout << "2. Largest piece count" << endl;
////        cout << "3. Search for set name containing..." << endl;
////        cout << "4. Search themes..." << endl;
////        cout << "5. Part count information" << endl;
////        cout << "6. Price information" << endl;
////        cout << "7. Minifigure information" << endl;
////        cout << "8. If you bought one of everything..." << endl;
////        cout << "0. Exit" << endl;
//
//    int choice;
//    cin >> choice;
//    cin.get();  // Clear newline character for any later input
//
//    /*======= Print out how many sets were loaded =======*/
//    cout <<"Total number of sets: "<<setCount <<endl<<endl;
//    /*======= Based on the choice, execute the appropriate task and show the results =======*/
//
//    string tSetNum;
//    string tTheme;
//    string tName;
//    string tMiniFigures;
//    string tPar;
//    string tPrice;
//    if(choice == 1){
//        string setNum;
//        string theme;
//        string name;
//        int parts = 0;
//        int miniFigures;
//        double price = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                string value;
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                if(stod(tPrice) > price){
//                    price = stod(tPrice);
//                    setNum = tSetNum;
//                    theme = tTheme;
//                    name = tName;
//                    miniFigures = stoi(tMiniFigures);
//                    parts = stoi(tPar);
//                }
//            }
//        }
//        cout<<"The most expensive set is: "<<endl;
//        cout<<"Name: " << name <<endl;
//        cout<<"Number: " << setNum<< endl;
//        cout<<"Theme: "<< theme<<endl;
//        cout<<"Price: $" << price<<endl;
//        cout<<"Minifigures: "<<miniFigures<<endl;
//        cout<<"Piece count: " <<parts<<endl;
//    }
//    else if(choice == 2){
//        string setNum;
//        string theme;
//        string name;
//        int parts = 0;
//        int miniFig;
//        double price = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                if(stoi(tPar) > parts){
//                    price = stod(tPrice);
//                    setNum = tSetNum;
//                    theme = tTheme;
//                    miniFig = stoi(tMiniFigures);
//                    name = tName;
//                    parts = stoi(tPar);
//                }
//            }
//        }
//        cout<<"The set with the highest parts count: "<<endl;
//        cout<<"Name: " << name <<endl;
//        cout<<"Number: " << setNum<< endl;
//        cout<<"Theme: "<< theme<<endl;
//        cout<<"Price: $" << price<<endl;
//        cout<<"Minifigures: "<<miniFig;
//        cout<<"Piece count: " <<parts<<endl;
//    }
//    else if(choice == 3){
//        string input;
//        getline(cin,input);
//        int c = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                string value;
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                if (tName.find(input) != string::npos) {
//                    if (c == 0) {
//                        cout << "Sets matching \"" << input << "\":" << endl;
//                    }
//                    cout << tSetNum << " " << tName << " $" << stod(tPrice) << endl;
//                    c++;
//                }
//            }
//        }
//        if(c==0){
//            cout<<"No sets found matching that search term"<<endl;
//        }
//    }
//    else if(choice == 4){
//        string input;
//        getline(cin,input);
//        int c = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                string value;
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                if (tTheme.find(input) != string::npos) {
//                    if (c == 0) {
//                        cout << "Sets matching \"" << input << "\":" << endl;
//                    }
//                    cout << tSetNum << " " << tName << " $" << stod(tPrice) << endl;
//                    c++;
//                }
//            }
//        }
//        if(c == 0){
//            cout<<"No sets found matching that search term"<<endl;
//        }
//    }
//    else if(choice == 5){
//        int totalParts = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                totalParts += stoi(tPar);
//            }
//        }
//        cout<<"Average part count for "<<setCount<< " sets: "<<totalParts/setCount<<endl;
//    }
//    else if(choice == 6){
//        string minSetNum;
//        string minTheme;
//        string minName;
//        int minPar;
//        int minFig;
//        double minPrice = 0;
//        string maxSetNum;
//        string maxTheme;
//        string maxName;
//        int maxPar;
//        int maxFig;
//        double maxPrice;
//        double total = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                if(minPrice == 0){
//                    minPrice = stod(tPrice);
//                    minSetNum = tSetNum;
//                    minFig = stoi(tMiniFigures);
//                    minTheme = tTheme;
//                    minName = tName;
//                    minFig = stoi(tMiniFigures);
//                    minPar = stoi(tPar);
//                    maxPrice = stod(tPrice);
//                    maxSetNum = tSetNum;
//                    maxTheme = tTheme;
//                    maxFig = stoi(tMiniFigures);
//                    maxName = tName;
//                    maxPar = stoi(tPar);
//                }
//                if(stod(tPrice) < minPrice){
//                    minPrice = stod(tPrice);
//                    minSetNum = tSetNum;
//                    minFig = stoi(tMiniFigures);
//                    minTheme = tTheme;
//                    minName = tName;
//                    minPar = stoi(tPar);
//                }
//                if(stod(tPrice) > maxPrice){
//                    maxPrice = stod(tPrice);
//                    maxSetNum = tSetNum;
//                    maxTheme = tTheme;
//                    maxFig = stoi(tMiniFigures);
//                    maxName = tName;
//                    maxPar = stoi(tPar);
//                }
//                total += stod(tPrice);
//            }
//        }
//        cout<<"Average price for "<<setCount<<" sets: $"<<total/setCount<<endl<<endl;
//        cout<<"Least expensive set: "<<endl;
//        cout<<"Name: " << minName <<endl;
//        cout<<"Number: " << minSetNum<< endl;
//        cout<<"Theme: "<< minTheme<<endl;
//        cout<<"Price: $" << minPrice<<endl;
//        cout<<"Minifigures: "<<minFig<<endl;
//        cout<<"Piece count: " <<minPar<<endl<<endl;
//        cout<<"Most expensive set: "<<endl;
//        cout<<"Name: " << maxName <<endl;
//        cout<<"Number: " << maxSetNum<< endl;
//        cout<<"Theme: "<< maxTheme<<endl;
//        cout<<"Price: $" << maxPrice<<endl;
//        cout<<"Minifigures: "<<maxFig<<endl;
//        cout<<"Piece count: " <<maxPar<<endl;
//    }
//    else if(choice == 7){
//        string maxSetNum;
//        string maxTheme;
//        string maxName;
//        int maxMini = 0;
//        int maxPar;
//        double maxPrice;
//        int total = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                if(stoi(tMiniFigures) > maxMini){
//                    maxPrice = stod(tPrice);
//                    maxSetNum = tSetNum;
//                    maxTheme = tTheme;
//                    maxName = tName;
//                    maxMini = stoi(tMiniFigures);
//                    maxPar = stoi(tPar);
//                }
//                total += stoi(tMiniFigures);
//            }
//        }
//        cout<<"Average number of minifigures: "<<total/setCount<<endl<<endl;
//        cout<<"Set with the most minifigures: "<<endl;
//        cout<<"Name: " << maxName <<endl;
//        cout<<"Number: " << maxSetNum<< endl;
//        cout<<"Theme: "<< maxTheme<<endl;
//        cout<<"Price: $" << maxPrice<<endl;
//        cout<<"Minifigures: "<<maxMini<<endl;
//        cout<<"Piece count: " <<maxPar<<endl<<endl;
//    }
//    else if(choice == 8){
//        int figures = 0;
//        int part = 0;
//        double totalPrice = 0;
//        for(int i = track; i <= option; i++){
//            file.close();
//            fileName = "lego"+to_string(i)+".csv";
//            file.open(fileName);
//            getline(file, line);
//            while(getline(file, line)){
//                stringstream str(line);
//                getline(str, tSetNum, ',');
//                getline(str, tTheme, ',');
//                getline(str, tName, ',');
//                getline(str, tMiniFigures, ',');
//                getline(str, tPar, ',');
//                getline(str, tPrice);
//                figures += stoi(tMiniFigures);
//                part += stoi(tPar);
//                totalPrice += stod(tPrice);
//            }
//        }
//        cout<<"If you bought one of everything..."<<endl;
//        cout<<"It would cost: $"<<totalPrice<<endl;
//        cout<<"You would have "<<part<<" pieces in your collection"<<endl;
//        cout<<"You would have an army of "<<figures<<" minifigures!"<<endl;
//    }
//    return 0;
//}
//
//
