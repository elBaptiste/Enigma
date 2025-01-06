#include <fstream>
#include <iostream>
#include <string>
#include "Encrypt.h"
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
    //std::string fichier = "C:/Users/bapti/CLionProjects/Enigma/texte.txt" ;
    std::string fichier = "C:/Users/augus/CLionProjects/Enigma/texte.txt" ;
    std::string texte_a_lire = read(fichier);
    std::cout << "Contenu du fichier :" << std::endl;
    std::cout << texte_a_lire << std::endl;
    std::string texte_a_ecrire = write(fichier);

    Enigma enigma = Enigma();
    std::cout<< enigma.encod(texte_a_lire, clef);

    return 0;
}
