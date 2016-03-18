#ifndef XMAPS_H
#define XMAPS_H

#include <string>
#include <map>
#include <memory>
#include <sstream>

#include "Base.h"
#include "Photo.h"
#include "Video.h"
#include "Groupe.h"
#include "Film.h"
#include "TCPServer.h"

using namespace std;

const int DEFAULT_PORT = 3331;

typedef shared_ptr<Photo> spPhoto;
typedef shared_ptr<Video> spVideo;
typedef shared_ptr<Film> spFilm;
typedef shared_ptr<Base> spBase;
typedef shared_ptr<Groupe> spGroupe;

class XMaps{

protected:
    map <string, spBase> baseMap;
    map <string, spGroupe> groupeMap;

public:
    XMaps(){}

    spPhoto addPhoto(string key);
    spVideo addVideo(string key);
    spFilm addFilm(string key);
    spGroupe addGroupeMap(string key);

    void removeBase(string key);
    void removeGroupe(string key);

    void searchBase(string key, ostream& os);
    void searchGroupe(string key, ostream& os);

    void playBase(string key);

    string find(string key);

    bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response);
};

#endif // XMAPS_H
