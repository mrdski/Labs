#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}
void RollDice(int numberOfRolls, int numberOfSides)
{
    map<int, int> roll;
    for(int i = 1; i <= numberOfSides;i++){
        roll[i] = 0;
    }
    for (int i = 0; i < numberOfRolls; i++)
    {
        int r = Random(1, numberOfSides);
        roll[r] = roll[r] + 1;
    }
    map<int, int>::iterator iter;
    for (iter = roll.begin(); iter != roll.end(); iter++)
        cout << iter->first << ": " << iter->second << endl;
}
class StateInfo{
    string state;
    int pCI;
    int pop;
    int mHI;
    int numH;
public:
    StateInfo(string stat, int pC, int po, int mH, int num){
        state = stat;
        pop = po;
        mHI = mH;
        numH = num;
        pCI = pC;
    };
    void print(){
        cout<<state<<endl<<"Population: "<<pop<<endl<<"Per Capita Income: "<<pCI<<endl<<"Median HouseholdIncome: "<<mHI<<endl<<"Number of Households: "<<numH<<endl;
    }

};
int main()
{
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1)
    {
        int randomSeed;
        int numR;
        int numS;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);
        cout << "Number of times to roll the die: ";
        cin >> numR;
        cout << "Number of sides on this die: ";
        cin >> numS;
        RollDice(numR, numS);
    }
    else if (option == 2)
    {
        map<string, StateInfo> stateI;
        string state;
        int pCI;
        int pop;
        int mHI;
        int numH;
        ifstream file("states.csv");
        string l;
        getline(file,l);
        while (getline(file, l)) {
            stringstream stream(l);
            string s;
            while (getline(stream, s, ',')) {
                state = s;
                getline(stream, s, ',');
                pCI = stoi(s);
                getline(stream, s, ',');
                pop = stoi(s);
                getline(stream, s, ',');
                mHI = stoi(s);
                getline(stream, s, ',');
                numH = stoi(s);
                StateInfo s(state, pCI, pop, mHI, numH);
                stateI.emplace(state, s);
            }

        }
        int c;
        cout << "1. Print all states" << endl;
        cout << "2. Search for a state" << endl;
        cin >> c;
        if (c == 1) {
            map<string, StateInfo>::iterator iter;
            for (iter = stateI.begin(); iter != stateI.end(); iter++)
                iter->second.print();
        }
        if (c == 2) {
            string search;
            cin >> search;
            if(stateI.find(search)==stateI.end()){
                cout<<"No match found for "<<search<<endl;
            }
            else{
                stateI.find(search)->second.print();
            }

        }
    }

    return 0;
}
