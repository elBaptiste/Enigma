//
// Created by augus on 20/12/2024.
//
#include <iostream>
#ifndef ENCRYPT_H
#define ENCRYPT_H


class Encrypt {
protected:
     std::string _plain;
     std:: string _cipher;


public :
     std::string plain();
     std::string cipher();
     virtual std::string encod(std::string message, std::string clef1, std::string clef2, std::string clef3);
     virtual std::string decod(std::string message, std::string clef1, std::string clef2, std::string clef3);
     std::string read();
     std::string write();
//test
};

std::string read(const std::string& fichier_lecture);
std::string write(const std::string& fichier_ecriture);



#endif //ENCRYPT_H
