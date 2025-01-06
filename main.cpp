#include <fstream>
#include <iostream>
#include <string>
#include "Enigma.h"



int main() {
    /*
    std::cout << "Hello World!\n";

    std::ifstream fichier { "C:/Users/bapti/CLionProjects/Enigma/texte.txt" };

    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier texte.txt" << std::endl;
        return 1;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::cout << ligne << std::endl;}
    */

    std::string clef = Enigma::generateKey();
    std::cout << clef << std::endl;
    return 0;
}
