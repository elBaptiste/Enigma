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
static std::string generateKey();
static int getPlaceAlphabet(char lettre);
std::string encod(std::string message, std::string clef1)override;
std::string decod(std::string message, std::string clef1)override;


};


#endif //ENIGMA_H


