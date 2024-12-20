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

};



#endif //ENCRYPT_H
