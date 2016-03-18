#ifndef GROUPE_H
#define GROUPE_H
#include <string>
#include <list>
#include <memory>
#include <iostream>
#include "Base.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

typedef shared_ptr<Photo> spPhoto;
typedef shared_ptr<Video> spVideo;
typedef shared_ptr<Film> spFilm;
typedef shared_ptr<Base> spBase;

class Groupe : public list<spBase>{

protected :
    string name;

public :
    // const
    Groupe(){
        spPhoto testP (new Photo("/testpic.png", "/cal/homes/wung/inf224"));
        spVideo testV (new Video("/testvid.avi", "/cal/homes/wung/inf224"));

        addBase(testP);
        addBase(testV);
    }

    Groupe(string _name);

    // dest
    virtual ~Groupe(){}

    /*
    virtual ~Groupe(){
        list<Base*>::iterator it;

        for (it = this->begin() ; it != this->end() ; ++it) {
             delete (*it);
        }
    }
    */

    // set & get
    virtual string getName() const {return name;}

    // affichage
    virtual void print(ostream& os);

    virtual void addBase(spBase b);
    virtual void removeBase(spBase b);
};

#endif // GROUPE_H
