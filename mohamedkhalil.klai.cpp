#include<iostream>
#include<vector>
using namespace std;

/* Classe tache  */
enum Type { DEV, TEST };
enum specialite { MOBILE, BACKEND, FRONTEND };

class tache {
private:
    string codeP;
    Type type;
    int quantite;
    specialite spectache;

public:
    tache(string cp, Type tp, specialite spt, int q);
    friend bool operator==(const tache& T1, const tache& T2) {
        return ((T1.codeP == T2.codeP) && (T1.type == T2.type) && (T1.spectache == T2.spectache));
    }
    specialite getTacheSpecialite() const;
    int getQuantite() const;
    void setQuantite(int quant);
};

tache::tache(string cp, Type tp, specialite spt, int q) {
    codeP = cp;
    type = tp;
    spectache = spt;
    quantite = q;
}

specialite tache::getTacheSpecialite() const {
    return spectache;
}

int tache::getQuantite() const {
    return quantite;
}

void tache::setQuantite(int quant) {
    quantite = quant;
}

/******** Classe projet ****************/
class projet {
private:
    string nomClient;
    string codeProjet;
    vector<tache> tachesRestantes;

public:
    projet(string n, string cpr);
    vector<tache> getTachesIncompletes() const;
    void updateTaches(tache tacheEffect);
};

projet::projet(string n, string cpr) {
    nomClient = n;
    codeProjet = cpr;
}

vector<tache> projet::getTachesIncompletes() const {
    vector<tache> TachesIncompletes;
    for (vector<tache>::const_iterator it = tachesRestantes.begin(); it != tachesRestantes.end(); it++) {
        if (it->getQuantite() > 0) {
            TachesIncompletes.push_back(*it);
        }
    }
    return TachesIncompletes;
}

void projet::updateTaches(tache tacheEffect) {
    for (vector<tache>::iterator it = tachesRestantes.begin(); it != tachesRestantes.end(); it++) {
        if (*it == tacheEffect) {
            it->setQuantite(it->getQuantite() - tacheEffect.getQuantite());
            break;
        }
    }
}

/***** Classe employe *****/
class employe {
private:
    int cin;
    enum specialite { MOBILE, BACKEND, FRONTEND };
    specialite specemploye;
    int capaciteMax;
    int capaciteRestante;
    vector<tache> tachesAffect;
    vector<tache> tachesRest;
public:
    employe(int c, specialite sp, int cm, int cr);
    bool estDisponible() const;
    int getCapaciteRestante() const;
    specialite getEmployeSpecialite() const;
    tache choisirTache(vector<tache> t) const;
    vector<tache> retournerTravailFini();
    void ajouterTache(tache t);
};

employe::employe(int c, specialite sp, int cm, int cr) {
    cin = c;
    specemploye = sp;
    capaciteMax = cm;
    capaciteRestante = cr;
}

bool employe::estDisponible() const {
    return (capaciteRestante > 0);
}

specialite employe::getEmployeSpecialite()const {
    return specemploye;
}

int employe::getCapaciteRestante() const {
    return capaciteRestante;
}

tache employe::choisirTache(vector<tache> T) const {
    for (auto i = T.begin(); i != T.end(); i++) {
        if ((i->getTacheSpecialite() == getEmployeSpecialite()) && (i->getQuantite() <= getCapaciteRestante())) {
            return *i;
        }
        else if (i->getQuantite() == 0) {
            return *i;
        }
    }
    return tache(); 
}

vector<tache> employe::retournerTravailFini() {
    vector<tache> travailFini;
    for (auto i = tachesAffect.begin(); i != tachesAffect.end(); i++) {
        if (i->getQuantite() == 0) {
            travailFini.push_back(*i);
        }
    }
    tachesAffect.erase(remove_if(tachesAffect.begin(), tachesAffect.end(), [](tache t) { return t.getQuantite() == 0; }), tachesAffect.end());
    return travailFini;
}

void employe::ajouterTache(tache t) {
    tachesAffect.push_back(t);
    tachesRest.push_back(t);
    capaciteRestante -= t.getQuantite();
}

class entreprise {
private:
    string nom;
    vector<projet> projets;
    vector<employe> employes;

public:
    entreprise(string nm);
    vector<tache> getTachesIncompletes() const;
    void distribuerTravail();
    vector<tache> collecterTravailFini();
};

entreprise::entreprise(string n) {
    nom = n;
}

vector<tache> entreprise::getTachesIncompletes() const {
    vector<tache> tachesIncompletes;
    for (auto i = projets.begin(); i != projets.end(); i++) {
        vector<tache> tachesProjet = i->getTachesIncompletes();
        tachesIncompletes.insert(tachesIncompletes.end(), tachesProjet.begin(), tachesProjet.end());
    }
    return tachesIncompletes;
}

void entreprise::distribuerTravail() {
    vector<tache> tachesNonCompletes = getTachesIncompletes();
    for (auto i = tachesNonCompletes.begin(); i != tachesNonCompletes.end(); i++) {
        for (auto j = employes.begin(); j != employes.end(); j++) {
            if (j->estDisponible()) {
                j->ajouterTache(*i);
                break; 
            }
        }
    }
}

vector<tache> entreprise::collecterTravailFini() {
    vector<tache> travauxFinis;
    for (auto i = employes.begin(); i != employes.end(); i++) {
        vector<tache> travauxEmploye = i->retournerTravailFini();
        travauxFinis.insert(travauxFinis.end(), travauxEmploye.begin(), travauxEmploye.end());
    }
    return travauxFinis;
}
