#ifndef FILM_H
#define FILM_H
#include "Video.h"

using namespace std;

class Film: public Video {

private:
    // tableau de durées
    int* tab;
    int size;

public:
    // const
    Film(){
        objectName = "/testvid.avi";
        pathName = "/cal/homes/wung/inf224";
        duree = 1;
        size = 1;
        // int* tab = new int[1];
    }

    Film(string _obj, string _pat, int _duree, int* tab_, int taille):Video(_obj, _pat, _duree){
        objectName = _obj;
        pathName = _pat;
        duree = _duree;

        tab = new int[size = taille];
        for(int i =0; i< taille; ++i)
            tab[i] = tab_[i];
    }

    Film(const Film& from):Video(from){
        objectName = from.objectName;
        pathName = from.pathName;
        duree = from.duree;
        size = from.size;

        if(from.tab){
            tab = new int[size = from.size];
            for(int i =0; i< from.size; ++i)
                tab[i] = from.tab[i];
        }
        else tab = NULL;
    }

    // get & set
        // tableau de durées
    virtual int* getTab() const {return tab;}
        // nb de chapitres
    virtual int getNbChap() const {return size;}

        // "modifieur"
    virtual void setChap(int* tab_, int size_);

    // affichage
    virtual void print(ostream& os);

    // dest
    virtual ~Film();
};

#endif // FILM_H
