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

std::string Enigma::encod(std::string message, std::string tab_clefs[3]) {
    std::string message_code ="";
    for (int i = 0; i < message.size() ; i++) {
            message_code.push_back(tab_clefs[i%3][getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
    }
    return message_code;
}

std::string Enigma::decod(std::string message, std::string tab_clefs[3]){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string message_decode ="";
    int num_car_decode = 0;
    for (int i = 0; i < message.size() ; i++){
        for (int j = 0; j < 53; j++) {
                if (message[i]==tab_clefs[i%3][j]) {
                    num_car_decode = j;
                    break;

            }
        }
        message_decode.push_back(alphabet[num_car_decode]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere décodé
    }
    return message_decode;
}
