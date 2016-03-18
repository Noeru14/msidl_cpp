#ifndef VIDEO_H
#define VIDEO_H
#include "Base.h"
#include <string>
#include <cstring>

using namespace std;

class Video : public Base{

protected:
    unsigned int duree;

public:
    // const
    Video(){
        objectName = "/testvid.avi";
        pathName = "/cal/homes/wung/inf224";
        duree = 1;
    }

    Video(string obj, string pat, int _duree = 0):Base(obj, pat){
        objectName = "/testvid.avi";
        pathName = "/cal/homes/wung/inf224";
        duree = _duree;
    }

    // get & set
    unsigned int getDuree() const{
        return duree;
    }

    void setDuree(unsigned int dur){
        duree = dur;
    }

    // dest
    virtual ~Video(){
        cout << "Video deleted" << endl;
    }

    // affichage
    virtual void print(ostream& os) override{

        os << "*** VIDEO ***" << endl;
        os << "Object name : " << getObjectName() << " ; Path name : " << getPathName() << endl;
        os << "Duree : " << getDuree() << endl;
    }

    // jouer l'objet
    virtual void play() override{
        string argSys = "mpv "+getPathName()+getObjectName()+" &";
        system(argSys.c_str());
    }
};

#endif // VIDEO_H
