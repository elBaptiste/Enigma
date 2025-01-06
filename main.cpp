#include <fstream>
#include <iostream>
#include <string>
#include "Encrypt.h"
#include "Enigma.h"

int main() {
    std::string fichier = "C:/Users/bapti/CLionProjects/Enigma/texte.txt" ;
    std::string texte_a_lire = read(fichier);
    std::cout << "Contenu du fichier :" << std::endl;
    std::cout << texte_a_lire << std::endl;
    std::string texte_a_ecrire = write(fichier);

    return 0;
}
