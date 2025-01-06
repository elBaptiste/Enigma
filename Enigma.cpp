//
// Created by augus on 20/12/2024.
//

#include "Enigma.h"
#include <random>
#include <ctime>



std::string Enigma::generateKey() {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string clef;
    bool done = false;
    int choix = 0;
    int deja_fait[26];
    for (int i = 0; i < 26; i++) { //initialisation de dejafait
        deja_fait[i]=-1;
    }

    for (int i = 0; i < 26; i++) {
        while (not done) {
            std::srand(std::time(0));
            choix=rand()%26;
            clef.push_back(alphabet[choix]);
        }
    }
    return clef;

    /*
    int dejafait [26];
    for (int i = 0; i < 26; i++) {
        dejafait[i]=-1;
    }
    bool done = false;
    int choix;
    int pb;
    for (int i = 0; i < 26; i++) {
        while (not done) {
            done = true;
            std::srand(std::time(0));
            choix=rand()%26;
            pb = 0;
            for (int j = 0; j < i; j++) {
                if (choix==dejafait[j]) {
                    pb = 1;
                }
            }
            if (pb==0) {
                done = true;
                dejafait[i] = choix;
            }
        }
        clef.push_back(alphabet[choix]);
    }
    return clef;*/
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
        nouveaumessage.push_back(clef1[Enigma::getPlaceAlphabet(message[i])]); // ligne pas belle pour dire qu on ajoute a la fin de nouveaumessage le caractere encodé
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