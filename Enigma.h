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
};



#endif //ENIGMA_H


std::string generateKey() {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string clef;
    int dejafait [26];
    for (int i = 0; i < 26; i++) {
        dejafait[i]=-1;
    }
    bool done = false;
    int choix;
    int pb;
    for (int i = 0; i < 26; i++) {
        while (not done) {
            choix=rand()%26;
            pb = 0;
            for (int j = 0; j < i; j++) {
                if (choix==dejafait[j]) {
                    pb = 1;
                }
            }
            if (pb==0) {
                done = true;
            }
        }
        clef.push_back(alphabet[choix]);
    }
    return clef;
}