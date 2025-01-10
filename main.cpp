#include <fstream>
#include <iostream>
#include <string>
#include "Encrypt.h"
#include "Enigma.h"

int main() {
    std::string clef1, clef2, clef3;
    Enigma::generateKey(clef1,53);
    Enigma::generateKey(clef2,53);
    Enigma::generateKey(clef3,53);
    std::cout << clef1 << std::endl;
    std::cout << clef2 << std::endl;
    std::cout << clef3 << std::endl;
    std::string tab_clefs[3] = {clef1,clef2,clef3};
    std::string fichier = "C:/Users/bapti/CLionProjects/Enigma/texte.txt" ;
    //std::string fichier = "C:/Users/augus/CLionProjects/Enigma/texte.txt" ;
    std::string texte_a_lire = read(fichier);
    std::cout << texte_a_lire << std::endl;
    std::string texte_a_ecrire = write(fichier);

    Enigma enigma = Enigma();
    std::string texteencr = enigma.encod(texte_a_lire, tab_clefs);
    std::cout<<texteencr<<std::endl;
    std::cout << "-------------------------"<<std::endl;
    std::string textefinal = enigma.decod(texteencr,tab_clefs);
    std::cout<<textefinal;
    return 0;
}
