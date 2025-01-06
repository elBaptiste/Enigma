//
// Created by augus on 20/12/2024.
//

#include "Enigma.h"
#include <random>
#include <ctime>



std::string Enigma::generateKey() {
    std::srand(std::time(0));
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int choix = -1;
    char temp = 'a';
    for (int i = 0; i < 26; i++) {
        choix=rand()%26;
        temp = alphabet[i];
        alphabet[i] = alphabet[choix];
        alphabet[choix] = temp;
    }
    return alphabet;
}

int Enigma::getPlaceAlphabet(char lettre) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++) {
        if (lettre==alphabet[i]) {
            return i;
        }
    }
    return -1;
}

std::string Enigma::encod(std::string message, std::string clef1){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string nouveaumessage ="";
    char charAAjouter = 'a';
    for (int i = 0; i < message.size() ; i++) {
        if (message[i] != ' '){
            nouveaumessage.push_back(clef1[Enigma::getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
        }
    }
    return nouveaumessage;
}

std::string Enigma::decod(std::string message, std::string clef1){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string nouveaumessage ="";
    char charAAjouter = 'a';
    int num_car_decode = 0;
    for (int i = 0; i < message.size() ; i++) {
        for (int j = 0; j < 26; j++) {
            if (message[i]==alphabet[j]) {
                num_car_decode = j;
                break;
            }
        }
        nouveaumessage.push_back(alphabet[num_car_decode]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere décodé
    }
    return nouveaumessage;
}