//
// Created by augus on 20/12/2024.
//
#include <iostream>
#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <vector>

class Encrypt {
protected:
     std::string _plain;
     std:: string _cipher;


public :
     std::string plain();
     std::string cipher();
     virtual std::string encod(std::string message, std::vector<std::string> tab_clefs);
     virtual std::string decod(std::string message, std::vector<std::string> tab_clefs);

};

std::string read(const std::string& fichier_lecture);
std::string write(const std::string& fichier_ecriture);



#endif //ENCRYPT_H
