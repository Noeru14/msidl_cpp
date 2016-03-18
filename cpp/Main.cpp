#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"
#include "XMaps.h"

#include <list>
#include <memory>

using namespace std;

typedef shared_ptr<Base> spBase;
typedef shared_ptr<Photo> spPhoto;
typedef shared_ptr<Video> spVideo;
typedef shared_ptr<Film> spFilm;
typedef shared_ptr<Groupe> spGroupe;

int main(int argc, char* argv[]){
    /*
    //
    Base* b = new Base("te", "st");
    b->print(cout);
    */

    // étape 4 : photos et vidéos
    // Photo* p = new Photo("/testpic.png", "/cal/homes/wung/inf224");
    //p->play();

    // Video* v = new Video("/testvid.avi", "/cal/homes/wung/inf224");
    // v->play();

    /*
    // étape 5 : traitement générique
    Base* tab[] = {p, v};
    for(auto it : tab) it->play();
    */

    /*
    // étape 6 : films et tableaux
    int* tab = new int[4];
    tab[0] = 4;
    tab[1] = 2;
    tab[2] = 8;
    tab[3] = 1;

    Film* f = new Film(tab, 4);
    int test = f->getNbChap();

    cout << test;
    f->print(cout);

    int* tab1 = new int[3];
    tab1[0] = 1;
    tab1[1] = 2;
    tab1[2] = 3;
    f->setChap(tab1, 3);

    test = f->getNbChap();
    cout << test;

    f->print(cout);

    delete [] tab;
    */

    /*
    // étape 7 : destruction et copie des objets
    int* tab = new int[4];
    tab[0] = 4;
    tab[1] = 2;
    tab[2] = 8;
    tab[3] = 1;
    Film* f = new Film("/testvid.avi", "/cal/homes/wung/inf224", 1, tab, 4);

    Film fcopyOne = *f;
    Film fcopyTwo = *f;

    delete f;

    // f->print(cout);
    fcopyOne.print(cout);
    */

    /*
    // étape 8 : créer des groupes
    Groupe* testGroup = new Groupe("testG");
    Groupe* testGroupA = new Groupe("testA");
    Groupe* testGroupB = new Groupe("testB");

    // Photo* p = new Photo("/testpic.png", "/cal/homes/wung/inf224");
    // Video* v = new Video("/testvid.avi", "/cal/homes/wung/inf224");

    Photo* p = new Photo("/testpic.png", "/cal/homes/wung/inf224");

    Video* v = new Video("/testvid.avi", "/cal/homes/wung/inf224");
    Video* vA = new Video("vA.test", "vAtestPath");
    Video* vB = new Video("vB.test", "vBtestPath");

    int* tab = new int[4];
    tab[0] = 4;
    tab[1] = 2;
    tab[2] = 8;
    tab[3] = 1;
    Film* f = new Film("/testvid.avi", "/cal/homes/wung/inf224", 1, tab, 4);

    testGroup->addBase(p);
    testGroup->addBase(v);
    testGroup->addBase(f);

    testGroupA->addBase(p);
    testGroupA->addBase(vA);

    testGroupB->addBase(p);
    testGroupB->addBase(vB);

    // testGroup->print();
    delete testGroup;

    testGroupA->print();
    testGroupB->print();
    */

    /*
    // étape 9 : gestion automatique de la mémoire
    Groupe* testGroup = new Groupe("testG");
    Groupe* testGroupA = new Groupe("testA");
    Groupe* testGroupB = new Groupe("testB");

    spPhoto p (new Photo("/testpic.png", "/cal/homes/wung/inf224"));

    spVideo v (new Video("/testvid.avi", "/cal/homes/wung/inf224"));
    // spVideo vA (new Video("vA.test", "vAtestPath"));
    spVideo vB (new Video("vB.test", "vBtestPath"));

    int* tab = new int[4];
    tab[0] = 4;
    tab[1] = 2;
    tab[2] = 8;
    tab[3] = 1;
    spFilm f (new Film("/testvid.avi", "/cal/homes/wung/inf224", 1, tab, 4));

    testGroup->addBase(p);
    testGroup->addBase(v);
    testGroup->addBase(f);

    testGroupA->addBase(p);
    testGroupA->addBase(f);

    testGroupB->addBase(p);
    testGroupB->addBase(vB);

    // testGroup->print();

    testGroupA->print();
    testGroupB->print();

    // delete testGroup; // l'objet v est supprimé, rien ne pointe sur lui
    // delete testGroupA; // f est supprimé
    // delete testGroupB; // p et vB sont supprimés

    // testGroup->removeBase(v); // v est supprimé
    */

    /*
    // étape 10 : gestion cohérente des données
    XMaps* xmapsOne = new XMaps();
    XMaps* xmapsTwo = new XMaps();

    spPhoto pOne = xmapsOne->addPhoto("photo1");
    spPhoto pTwo = xmapsOne->addPhoto("photo2");
    spVideo vOne = xmapsOne->addVideo("video1");
    spFilm fOne = xmapsOne->addFilm("film1");

    // xmapsOne->searchBase("photo1");

    spGroupe gOne = xmapsOne->addGroupeMap("groupe1");

    xmapsOne->searchGroupe("groupe1");

    xmapsOne->removeBase("photo2");

    //xmapsOne->playBase("photo1");
    */

    // étape 11 : client / serveur
    TCPServer * server = new TCPServer();
    XMaps* app = new XMaps();

    spPhoto pOne = app->addPhoto("photo1");
    spPhoto pTwo = app->addPhoto("photo2");
    spVideo vOne = app->addVideo("video1");
    spVideo vTwo = app->addVideo("video2");
    spFilm fOne = app->addFilm("film1");
    spFilm fTwo = app->addFilm("film2");

    server->setCallback(app, &XMaps::processRequest);

    int port = (argc >= 2) ? atoi(argv[1]) : DEFAULT_PORT;
    cout << "Starting Server on port " << port << endl;
    int status = server->run(port);

    if (status < 0) {
      cerr << "Could not start Server on port " << port << endl;
      return 1;
    }

    else return 0;
}


