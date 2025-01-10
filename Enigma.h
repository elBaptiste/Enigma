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
static std::string generateKey(int length);
static int getPlaceAlphabet(char lettre);
std::string encod(std::string message, std::vector<std::string> tab_clefs)override;
std::string decod(std::string message, std::vector<std::string> tab_clefs)override;



};


#endif //ENIGMA_H


