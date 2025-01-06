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
     virtual std::string encod();
     virtual std::string decod();
     std::string read();
     std::string write();
//test
};

std::string read(const std::string& fichier_lecture);
std::string write(const std::string& fichier_ecriture);



#endif //ENCRYPT_H
