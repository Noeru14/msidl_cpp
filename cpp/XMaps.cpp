#include "XMaps.h"

spPhoto XMaps::addPhoto(string key){
    spPhoto p (new Photo());
    baseMap[key] = p;

    return p;
}

spVideo XMaps::addVideo(string key){
    spVideo v (new Video());
    baseMap[key] = v;

    return v;
}

spFilm XMaps::addFilm(string key){
    spFilm f (new Film());
    baseMap[key] = f;

    return f;
}

spGroupe XMaps::addGroupeMap(string key){
    spGroupe g (new Groupe());
    groupeMap[key] = g;

    return g;
}

void XMaps::removeBase(string key){
    baseMap.erase(key);
}

void XMaps::removeGroupe(string key){
    groupeMap.erase(key);
}

void XMaps::searchBase(string key, ostream& os){
    map <string, spBase>:: iterator it = baseMap.find(key);
    if(it != baseMap.end())
        it->second->print(os);
}

void XMaps::searchGroupe(string key, ostream& os){
    map <string, spGroupe>:: iterator it = groupeMap.find(key);
    if(it != groupeMap.end())
        it->second->print(os);
}

void XMaps::playBase(string key){
    map <string, spBase>:: iterator it = baseMap.find(key);
    if(it != baseMap.end())
        it->second->play();
}

string XMaps::find(string key){
    // string ret = baseMap.find(key);
    string ret = "test";

    return ret;
}

bool XMaps::processRequest(TCPServer::Cnx& cnx, const string& request, string& response){

  // mettre cette variable à true si la commande modifie les donnees du programme
  bool changeData = false;
  if (request == "delMedias" || request == "delGroups") changeData = true;

  // suivant le cas on bloque le verrou en mode WRITE ou en mode READ
  TCPServer::Lock lock(cnx, changeData);

  cerr << "request: '" << request << "'" << endl;

  stringstream myRequest;
  myRequest << request;

  string requestX;
  string requestY;

  myRequest >> requestX >> requestY;

  stringstream myResponse;

  switch(request[0]){

    // display
    case '1': case 'D': case 'd':
        // xmapsOne->searchBase(requestY, myResponse);
        searchBase(requestY, myResponse);
        response = myResponse.str();

        break;

    // play
    case '2': case 'P': case 'p':
        playBase(requestY);
        break;

    // add photo
    case '3': case 'H': case 'h':
        addPhoto(requestY);
        break;

    // add video
    case '4': case 'V': case 'v':
        addVideo(requestY);
        break;

    // remove
    case '5': case 'R': case 'r':
        removeBase(requestY);
        break;

    // default
    default:
        response = "Commande inconnue...";
  }

  // simule un traitement long (décommenter pour tester le verrou)
  // if (changeData) sleep(10); else sleep(5);

  response.append("FIN");

  cerr << "response: '" << response << "'" << endl;

  // renvoyer false pour clore la connexion avec le client
  return true;
}
