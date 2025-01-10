//
// Created by augus on 20/12/2024.
//

#include "Enigma.h"
#include <random>
#include <algorithm>


void Enigma::generateKey(std::string& key, int length) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(alphabet.begin(), alphabet.end(), gen);
    key = alphabet.substr(0, length);
}

int Enigma::getPlaceAlphabet(char lettre) {
    std::string alphabet ="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 53; i++) {
        if (lettre==alphabet[i]) {
            return i;
        }
    }
    return -1;
}

std::string Enigma::encod(std::string message, std::string clef1, std::string clef2, std::string clef3) {
    std::string nouveaumessage ="";
    for (int i = 0; i < message.size() ; i++) {
        int cle_utilise = i%3;
        if (cle_utilise==1) {
            nouveaumessage.push_back(clef1[getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
        }
        else if (cle_utilise==2) {
            nouveaumessage.push_back(clef2[getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
        }
        else if (cle_utilise==3) {
            nouveaumessage.push_back(clef3[getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
        }
    }
    return nouveaumessage;
}

std::string Enigma::decod(std::string message, std::string clef1, std::string clef2, std::string clef3){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string nouveaumessage ="";
    int num_car_decode = 0;
    int clefautiliser = -1;
    for (int i = 0; i < message.size() ; i++) {
        clefautiliser=i%3;
        for (int j = 0; j < 53; j++) {
            if (clefautiliser==1) {
                if (message[i]==clef1[j]) {
                    num_car_decode = j;
                    break;
                }
            }
            if (clefautiliser==2) {
                if (message[i]==clef2[j]) {
                    num_car_decode = j;
                    break;
                }
            }
            if (clefautiliser==3) {
                if (message[i]==clef3[j]) {
                    num_car_decode = j;
                    break;
                }
            }
        }
        nouveaumessage.push_back(alphabet[num_car_decode]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere décodé
    }
    return nouveaumessage;
}
