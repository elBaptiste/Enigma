//
// Created by augus on 20/12/2024.
//

#include "Encrypt.h"
std::string Encrypt::encod(std::string message, std::string tab_clefs[3]) {
    return "rien";
};
#include <fstream>
#include <iostream>
#include <string>



std::string read(const std::string& fichier_lecture) {
    std::ifstream fichier(fichier_lecture);
    if (!fichier.is_open()) {
        std::cout << "Erreur d'ouverture du fichier" << std::endl;
        return"";
    }
    std::string ligne;
    std::string texte;
    while (std::getline(fichier, ligne)) {
        texte+=ligne;
    }
    fichier.close();
    return texte;

}

std::string write(const std::string& fichier_ecriture) {
    std::ofstream fichier(fichier_ecriture, std::ios::app);
    if (!fichier) {
        std::cout << "Impossible d'ouvrir le fichier pour l'écriture." << std::endl;
        return "";
    }
    std::string texte;
    std::cout << "Entrez le texte a ajouter au fichier : ";
    std::getline(std::cin, texte);
    fichier << texte << std::endl;
    return texte;
}


std::string Encrypt::decod(std::string message, std::string tab_clefs[3]) {
    return "rien";
};