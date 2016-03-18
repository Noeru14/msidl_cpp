#include "Film.h"
#include <iostream>

void Film::setChap(int* tab_, int size_){
    if (size != size_){
        delete[] tab;
        tab = new int[size = size_];
    }

    for(int i = 0 ; i < size ; ++i)
        tab[i] = tab_[i];
}

void Film::print(ostream& os){

    os << "*** FILM ***" << endl;
    os << "Object name : " << getObjectName() << " ; Path name : " << getPathName() << endl;
    os << "Duree totale : " << getDuree() << endl;

    for(int i = 0 ; i < size ; i++)
        os << "Durée chapitre " << i << " : " << this->tab[i] << endl;
}

Film::~Film(){
    delete[] tab; // détruit l'objet pointé
    tab = NULL; // tab ne pointe sur rien

    cout << "Film deleted" << endl;
}
