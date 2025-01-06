#include <fstream>
#include <iostream>
#include <string>
#include "Encrypt.h"
#include "Enigma.h"

int main() {
    std::string clef1 = Enigma::generateKey();
    std::string clef2 = Enigma::generateKey();
    std::string clef3 = Enigma::generateKey();
    std::string fichier = "C:/Users/bapti/CLionProjects/Enigma/texte.txt" ;
    //std::string fichier = "C:/Users/augus/CLionProjects/Enigma/texte.txt" ;
    std::string texte_a_lire = read(fichier);
    std::cout << "Contenu du fichier :" << std::endl;
    std::cout << texte_a_lire << std::endl;
    std::string texte_a_ecrire = write(fichier);

    Enigma enigma = Enigma();
    std::string texteencr = enigma.encod(texte_a_lire, clef1,clef2, clef3);
    std::cout<<texteencr;
    std::string textefinal = enigma.decod(texteencr,clef1,clef2,clef3);
    std::cout<<"\n\n\n"<<textefinal;
    return 0;
}
