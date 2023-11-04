#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "platform.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

    if (argc < 4 || (argc >= 2 && (string(argv[1]) == "/?" || string(argv[1]) == "-h" || string(argv[1]) == "--help"))) {
        cout << "========== Description ==========" << endl;
        cout << "Simulateur de plateforme" << endl << endl;
        cout << "========== Usage ==========" << endl;
        cout << argv[0] << " [/?] platorm_name platform_def_file [nb_cycle]" << endl << endl;
        cout << "/?\t\t\tAffiche l'aide" << endl;
        cout << "plateform_name\t\tNom de la plateforme" << endl;
        cout << "platform_def_file\tFichier de définition de la plateforme" << endl;
        cout << "nb_cycle\t\tNombre de cycle à simuler, 1 par défaut" << endl;
        return 0;
    }

    Platform platform(argv[1], argv[2]);

    platform.simulate(atoi(argv[3]));

    #ifdef DEBUG
    cout << "========== EXEC DONE ==========" << endl;
    #endif
    
    return 0;
}