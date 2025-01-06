//
// Created by augus on 20/12/2024.
//

#include "Enigma.h"
#include <random>
#include <ctime>



std::string Enigma::generateKey() {
    std::srand(std::time(0));
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int choix = -1;
    char temp = 'a';
    for (int i = 0; i < 53; i++) {
        choix=rand()%53;
        temp = alphabet[i];
        alphabet[i] = alphabet[choix];
        alphabet[choix] = temp;
    }
    return alphabet;
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

std::string Enigma::encod(std::string message, std::string clef1){
    std::string nouveaumessage ="";
    for (int i = 0; i < message.size() ; i++) {
        nouveaumessage.push_back(clef1[Enigma::getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
    }
    return nouveaumessage;
}

std::string Enigma::decod(std::string message, std::string clef1){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string nouveaumessage ="";
    int num_car_decode = 0;
    for (int i = 0; i < message.size() ; i++) {
        for (int j = 0; j < 53; j++) {
            if (message[i]==clef1[j]) {
                num_car_decode = j;
                break;
            }
        }
        nouveaumessage.push_back(alphabet[num_car_decode]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere décodé
    }
    return nouveaumessage;
}
