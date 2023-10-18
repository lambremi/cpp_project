// #include <iostream>
// #include "platform.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(/*int argc, char const *argv[]*/) {

    string def_file = "../data/platform.txt";
    vector<string*> paths;

    ifstream file(def_file);

    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de définition " << def_file << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        cout << line << endl;
    }

    // cout << "ouvert" << endl;

    
    // file.read((char*)&line, sizeof(line));

    // cout << "lu" << endl;

    // cout << line << endl;

    // cout << "fin" << endl;

    return 0;
}