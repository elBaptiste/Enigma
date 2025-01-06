//
// Created by augus on 20/12/2024.
//
#include <iostream>
#include <vector>
#include "Encrypt.h"

#ifndef ENIGMA_H
#define ENIGMA_H



class Enigma : public Encrypt{
private :
public :
std::string encod()override;
std::string decod()override;
};


#endif //ENIGMA_H


