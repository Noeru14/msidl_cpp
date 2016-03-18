#ifndef PHOTO_H
#define PHOTO_H
#include "Base.h"
#include <string>
#include <cstring>

using namespace std;

class Photo : public Base{

protected:
    // width
    float wid;
    // heigth
    float hei;

public:
    // const
    Photo(){
        objectName = "/testpic.png";
        pathName = "/cal/homes/wung/inf224";
        wid = 0;
        hei = 0;
    }

    Photo(string obj, string pat, float _wid = 0, float _hei = 0):Base(obj, pat){
        objectName = obj;
        pathName = pat;
        wid = _wid;
        hei = _hei;
    }

    // get & set
    float getWid() const{
        return wid;
    }

    float getHei() const{
        return hei;
    }

    void setWid(float wi){
        wid = wi;
    }

    void setHei(float he){
        hei = he;
    }

    // dest
    virtual ~Photo(){
        cout << "Photo deleted" << endl;
    }

    // affichage
    virtual void print(ostream& os) override{

        os << "*** PHOTO ***" << endl;
        os << "Object name : " << getObjectName() << " ; Path name : " << getPathName() << endl;
        os << "Width: " << getWid() << " ; Heigth: " << getHei() << endl;
    }

    // jouer l'objet
    virtual void play() override{
        string argSys = "imagej "+getPathName()+getObjectName()+" &";
        system(argSys.c_str());
    }
};

#endif // PHOTO_H
