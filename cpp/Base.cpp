#include "Base.h"
#include <iostream>

Base::Base(string obj, string pat){
    objectName = obj;
    pathName = pat;
}

string Base::getObjectName() const{
    return objectName;
}

string Base::getPathName() const{
    return pathName;
}

void Base::setObjectName(string obj){
    objectName = obj;
}

void Base::setPathName(string pat){
    pathName = pat;
}

void Base::print(ostream& os){
    os << "Object name : " << getObjectName() << " ; Path name : " << getPathName() << endl;
}

Base::~Base(){

}

void Base::play(){

}
