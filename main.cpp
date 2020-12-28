#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int args, char* argv[]) {

    // read names from file
    vector<string> names;

    string name;
    ifstream file;
    file.open(argv[1]);

    while(getline(file, name)){
        names.push_back(name);
    }

    return 0;
}
