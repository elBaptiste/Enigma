#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Encrypt.h"
#include "Enigma.h"

int main() {
    std::cout << "-------------------------"<<std::endl;
    std::cout<<"Clefs de cryptage :"<<std::endl;
    std::vector<std::string> tab_clefs;
    for (int i=0; i <= 100; i++) {
        Enigma::generateKey(53);
        tab_clefs.push_back(Enigma::generateKey(53));
        std::cout<<tab_clefs.at(i)<<std::endl;
    }
    std::cout<<"--------------------"<<std::endl;
    std::cout<<"Message a crypter :"<<std::endl;
    std::string fichier = "C:/Users/bapti/CLionProjects/Enigma/texte.txt" ;
    //std::string fichier = "C:/Users/augus/CLionProjects/Enigma/texte.txt" ;
    std::string texte_a_lire = read(fichier);
    std::cout<<texte_a_lire<<std::endl;
    std::cout << "-------------------------"<<std::endl;


    Enigma enigma = Enigma();
    std::cout<<"Message crypte :"<<std::endl;
    std::string texteencr = enigma.encod(texte_a_lire, tab_clefs);
    std::cout<<texteencr<<std::endl;
    std::cout << "-------------------------"<<std::endl;
    std::cout<<"Message decrypte :"<<std::endl;
    std::string textefinal = enigma.decod(texteencr,tab_clefs);
    std::cout<<textefinal<<std::endl;
    std::cout << "-------------------------"<<std::endl;
    return 0;
}
