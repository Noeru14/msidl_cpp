#ifndef BASE_H
#define BASE_H
#include <string>
#include <iostream>

using namespace std;

class Base{

protected:
    // nom de l'objet multimédia
    string objectName;
    // chemin complet permettant d'accéder à l'objet multimédia
    string pathName;

public:
    // const
    Base(){}
    Base(string obj, string pat);

    // get & set
    virtual string getObjectName() const;
    virtual string getPathName() const;
    virtual void setObjectName(string obj);
    virtual void setPathName(string pat);

    // dest
    virtual ~Base();

    // affichage des valeurs d'instance
    virtual void print(ostream& os);

    // jouer l'objet (méthode abstraite)
    virtual void play() = 0;
};

#endif // BASE_H
