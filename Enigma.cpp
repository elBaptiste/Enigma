//
// Created by augus on 20/12/2024.
//

#include "Enigma.h"
#include <random>
#include <algorithm>


std::string Enigma::generateKey(int length) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(alphabet.begin(), alphabet.end(), gen);
    std::string key = alphabet.substr(0, length);
    return key;
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

std::string Enigma::encod(std::string message, std::vector<std::string> tab_clefs) {
    std::string message_code ="";
    int size = tab_clefs.size();
    for (int i = 0; i < message.size() ; i++) {
            message_code.push_back(tab_clefs[i%size][getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
    }
    return message_code;
}

std::string Enigma::decod(std::string message, std::vector<std::string> tab_clefs){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string message_decode ="";
    int num_car_decode = 0;
    int size = tab_clefs.size();
    for (auto i = 0; i < message.size() ; i++){
        for (int j = 0; j < 53; j++) {
                if (message[i]==tab_clefs[i%size][j]) {
                    num_car_decode = j;
                    break;

            }
        }
        message_decode.push_back(alphabet[num_car_decode]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere décodé
    }
    return message_decode;
}
