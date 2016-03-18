#include "Groupe.h"
#include <string>
#include <iostream>
#include <list>

Groupe::Groupe(string _name){
    name = _name;
}

void Groupe::print(ostream& os){
    os << "Group name : "<< getName() << endl;

    for(list<spBase>::iterator it = this->begin(); it != this->end() ; ++it)
        (*it)->print(cout);
}

void Groupe::addBase(spBase b){
    this->push_back(b);
}

void Groupe::removeBase(spBase b){
    this->remove(b);
}
