#include <bits/stdc++.h>

#include <map>

#include <vector>

using namespace std;

class Om;
class ListaOm;
class ListaAtelier;

class Atelier{
private:
    string NumeAtelier{};
    map<string, int> Coef{};
    map<string, int> Bonus{};
    int Prag{};
    int Pret{};
    int BaniAtelier{};
    int Puncte{};
    int NrObiecte{};
public:
    Atelier(){
        Puncte = 0;
        NrObiecte = 0;
    }
    void citesteAtelier(){
        cin >> NumeAtelier >> BaniAtelier >> Prag >> Pret;
        cin >> Coef["STR"] >> Coef["DEX"] >> Coef["INT"] >> Coef["CHR"];
        cin >> Bonus["STR"] >> Bonus["DEX"] >> Bonus["INT"] >> Bonus["CHR"];
    }
    void produceObiecte(){
        while (Puncte >= Prag){
            NrObiecte++;
            Puncte = Puncte - Prag;
        }

    }
    friend void lucreaza(Om&, Atelier&);
    friend void cumpara(ListaOm*, ListaAtelier*);
    friend void angajeaza(ListaOm*, ListaAtelier*);
    friend void productie(ListaAtelier*);
    friend class ListaAtelier;
};
class Om{
private:
    string NumeOm{};
    map <string, int> Atribute{};
    int BaniOm{};
    map <int, string> Preferinta{};
public:
    Om() {
        Atribute["STR"] = 1;
        Atribute["DEX"] = 1;
        Atribute["INT"] = 1;
        Atribute["CHR"] = 1;
        BaniOm = 0;
    }
    void citesteOm(){
        cin >> NumeOm >> Preferinta[1] >> Preferinta[2] >> Preferinta[3] >> Preferinta[4];
    }
    void getStats(){
        cout << NumeOm << " " << Atribute["STR"] << " " << Atribute["DEX"] << " " << Atribute["INT"] << " " << Atribute["CHR"] << " " << BaniOm;
        cout << endl;
    }
    friend void lucreaza(Om&, Atelier&);
    friend void cumpara(ListaOm*, ListaAtelier*);
    friend void angajeaza(ListaOm*, ListaAtelier*);
    friend class ListaOm;
    friend class ListaAtelier;
};
class ListaOm{
private:
    vector <Om*> Oameni{};
    int Size{};
public:
    ListaOm(int size){
        Size = size;
    }
    void creeazaListaOm(){
        for (int i = 0; i < Size; i++){
            Oameni.push_back(new Om);
            Oameni[i]->citesteOm();
        }
    }
    void sortareOameni(){
        Om *Temp;
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if (Oameni[i]->Atribute["CHR"] < Oameni[j]->Atribute["CHR"]){
                    Temp = Oameni[i];
                    Oameni[i] = Oameni[j];
                    Oameni[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ((Oameni[i]->Atribute["CHR"] == Oameni[j]->Atribute["CHR"]) && ((Oameni[i]->Atribute["STR"] + Oameni[i]->Atribute["DEX"] + Oameni[i]->Atribute["INT"] + Oameni[i]->Atribute["CHR"] ) < (Oameni[j]->Atribute["STR"] + Oameni[j]->Atribute["DEX"] + Oameni[j]->Atribute["INT"] + Oameni[j]->Atribute["CHR"]))){
                    Temp = Oameni[i];
                    Oameni[i] = Oameni[j];
                    Oameni[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ((Oameni[i]->Atribute["CHR"] == Oameni[j]->Atribute["CHR"]) && ((Oameni[i]->Atribute["STR"] + Oameni[i]->Atribute["DEX"] + Oameni[i]->Atribute["INT"] + Oameni[i]->Atribute["CHR"] ) == (Oameni[j]->Atribute["STR"] + Oameni[j]->Atribute["DEX"] + Oameni[j]->Atribute["INT"] + Oameni[j]->Atribute["CHR"]) ) && (Oameni[i]->NumeOm > Oameni[j]->NumeOm)){
                    Temp = Oameni[i];
                    Oameni[i] = Oameni[j];
                    Oameni[j] = Temp;
                }
            }
        }
    }
    void sortareFinala(){
        Om *Temp;
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if (Oameni[i]->BaniOm < Oameni[j]->BaniOm){
                    Temp = Oameni[i];
                    Oameni[i] = Oameni[j];
                    Oameni[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ((Oameni[i]->BaniOm == Oameni[j]->BaniOm) && (Oameni[i]->Atribute["STR"] + Oameni[i]->Atribute["DEX"] + Oameni[i]->Atribute["INT"] + Oameni[i]->Atribute["CHR"] < Oameni[j]->Atribute["STR"] + Oameni[j]->Atribute["DEX"] + Oameni[j]->Atribute["INT"] + Oameni[j]->Atribute["CHR"] )){
                    Temp = Oameni[i];
                    Oameni[i] = Oameni[j];
                    Oameni[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ((Oameni[i]->BaniOm == Oameni[j]->BaniOm) && (Oameni[i]->Atribute["STR"] + Oameni[i]->Atribute["DEX"] + Oameni[i]->Atribute["INT"] + Oameni[i]->Atribute["CHR"] == Oameni[j]->Atribute["STR"] + Oameni[j]->Atribute["DEX"] + Oameni[j]->Atribute["INT"] + Oameni[j]->Atribute["CHR"] ) && (Oameni[i]->NumeOm > Oameni[j]->NumeOm)){
                    Temp = Oameni[i];
                    Oameni[i] = Oameni[j];
                    Oameni[j] = Temp;
                }
            }
        }

    }
    void afisare(){
        for (int i = 0; i < Size; i++){
            Oameni[i]->getStats();
        }
    }
    friend void cumpara(ListaOm*, ListaAtelier*);
    friend void angajeaza(ListaOm*, ListaAtelier*);
};
class ListaAtelier{
private:
    vector <Atelier*> Ateliere{};
    int Size{};
public:
    ListaAtelier(int size){
        Size = size;
    }
    void creeazaListaAtelier(){
        for (int i = 0; i < Size; i++){
            Ateliere.push_back(new Atelier);
            Ateliere[i]->citesteAtelier();
        }
    }
    void sorteazaDupaPreferinta(Om om){
        Atelier* Temp;
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if (Ateliere[i]->Bonus[om.Preferinta[1]] < Ateliere[j]->Bonus[om.Preferinta[1]]){
                    Temp = Ateliere[i];
                    Ateliere[i] = Ateliere[j];
                    Ateliere[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ( (Ateliere[i]->Bonus[om.Preferinta[1]] == Ateliere[j]->Bonus[om.Preferinta[1]]) && (Ateliere[i]->Bonus[om.Preferinta[2]] < Ateliere[j]->Bonus[om.Preferinta[2]])){
                    Temp = Ateliere[i];
                    Ateliere[i] = Ateliere[j];
                    Ateliere[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ( (Ateliere[i]->Bonus[om.Preferinta[1]] == Ateliere[j]->Bonus[om.Preferinta[1]]) && (Ateliere[i]->Bonus[om.Preferinta[2]] == Ateliere[j]->Bonus[om.Preferinta[2]]) && (Ateliere[i]->Bonus[om.Preferinta[3]] < Ateliere[j]->Bonus[om.Preferinta[3]]) ){
                    Temp = Ateliere[i];
                    Ateliere[i] = Ateliere[j];
                    Ateliere[j] = Temp;
                }
            }
        }
        for (int i = 0; i < Size; i++){
            for (int j = i + 1; j < Size; j++){
                if ( (Ateliere[i]->Bonus[om.Preferinta[1]] == Ateliere[j]->Bonus[om.Preferinta[1]]) && (Ateliere[i]->Bonus[om.Preferinta[2]] == Ateliere[j]->Bonus[om.Preferinta[2]]) && (Ateliere[i]->Bonus[om.Preferinta[3]] == Ateliere[j]->Bonus[om.Preferinta[3]]) && (Ateliere[i]->Bonus[om.Preferinta[4]] < Ateliere[j]->Bonus[om.Preferinta[4]]) ){
                    Temp = Ateliere[i];
                    Ateliere[i] = Ateliere[j];
                    Ateliere[j] = Temp;
                }
            }
        }
    }

    friend void cumpara(ListaOm*, ListaAtelier*);
    friend void angajeaza(ListaOm*, ListaAtelier*);
    friend void productie(ListaAtelier*);
};
void productie(ListaAtelier* ateliere){
    for (int i = 0; i < ateliere->Size; i++){
        ateliere->Ateliere[i]->produceObiecte();
    }
}
void angajeaza(ListaOm* oameni, ListaAtelier* ateliere){
    int Indice = 0;
    Atelier* Temp;

    for (int i = 0; i < oameni->Size; i++){
        for (int j = 0; j < ateliere->Size; j++){
            for (int k = j + 1; k < ateliere->Size; k++){
                if ((ateliere->Ateliere[j]->Coef["STR"] * oameni->Oameni[i]->Atribute["STR"]) + (ateliere->Ateliere[j]->Coef["DEX"] * oameni->Oameni[i]->Atribute["DEX"]) + (ateliere->Ateliere[j]->Coef["INT"] * oameni->Oameni[i]->Atribute["INT"]) + (ateliere->Ateliere[j]->Coef["CHR"] * oameni->Oameni[i]->Atribute["CHR"]) < (ateliere->Ateliere[k]->Coef["STR"] * oameni->Oameni[i]->Atribute["STR"]) + (ateliere->Ateliere[k]->Coef["DEX"] * oameni->Oameni[i]->Atribute["DEX"]) + (ateliere->Ateliere[k]->Coef["INT"] * oameni->Oameni[i]->Atribute["INT"]) + (ateliere->Ateliere[k]->Coef["CHR"] * oameni->Oameni[i]->Atribute["CHR"])){
                    Temp = ateliere->Ateliere[j];
                    ateliere->Ateliere[j] = ateliere->Ateliere[k];
                    ateliere->Ateliere[k] = Temp;
                }
            }
        }
        for (int j = 0; j < ateliere->Size; j++){
            for (int k = j + 1; k < ateliere->Size; k++){
                if (((ateliere->Ateliere[j]->Coef["STR"] * oameni->Oameni[i]->Atribute["STR"]) + (ateliere->Ateliere[j]->Coef["DEX"] * oameni->Oameni[i]->Atribute["DEX"]) + (ateliere->Ateliere[j]->Coef["INT"] * oameni->Oameni[i]->Atribute["INT"]) + (ateliere->Ateliere[j]->Coef["CHR"] * oameni->Oameni[i]->Atribute["CHR"]) == (ateliere->Ateliere[k]->Coef["STR"] * oameni->Oameni[i]->Atribute["STR"]) + (ateliere->Ateliere[k]->Coef["DEX"] * oameni->Oameni[i]->Atribute["DEX"]) + (ateliere->Ateliere[k]->Coef["INT"] * oameni->Oameni[i]->Atribute["INT"]) + (ateliere->Ateliere[k]->Coef["CHR"] * oameni->Oameni[i]->Atribute["CHR"])) && (ateliere->Ateliere[j]->NumeAtelier > ateliere->Ateliere[k]->NumeAtelier )){
                    Temp = ateliere->Ateliere[j];
                    ateliere->Ateliere[j] = ateliere->Ateliere[k];
                    ateliere->Ateliere[k] = Temp;
                }
            }
        }
        for (int j = 0; j < ateliere->Size; j++){
            if(     (Indice == 0)    &&    ((ateliere->Ateliere[j]->Coef["STR"] * oameni->Oameni[i]->Atribute["STR"]) + (ateliere->Ateliere[j]->Coef["DEX"] * oameni->Oameni[i]->Atribute["DEX"]) + (ateliere->Ateliere[j]->Coef["INT"] * oameni->Oameni[i]->Atribute["INT"]) + (ateliere->Ateliere[j]->Coef["CHR"] * oameni->Oameni[i]->Atribute["CHR"])  <= ateliere->Ateliere[j]->BaniAtelier) ){
                lucreaza(*oameni->Oameni[i], *ateliere->Ateliere[j]);
                Indice++;
            }
        }
        Indice = 0;
    }
}
void cumpara(ListaOm* oameni, ListaAtelier* ateliere){
    int Indice = 0;
    for (int i = 0; i < oameni->Size ; i++){
        ateliere->sorteazaDupaPreferinta(*oameni->Oameni[i]);
        for (int j = 0; j < ateliere->Size && Indice == 0; j++){
            if((oameni->Oameni[i]->BaniOm >= ateliere->Ateliere[j]->Pret)&&(Indice == 0)&&(ateliere->Ateliere[j]->NrObiecte > 0)){
                oameni->Oameni[i]->BaniOm = oameni->Oameni[i]->BaniOm - ateliere->Ateliere[j]->Pret;
                ateliere->Ateliere[j]->BaniAtelier = ateliere->Ateliere[j]->BaniAtelier + ateliere->Ateliere[j]->Pret;
                ateliere->Ateliere[j]->NrObiecte = ateliere->Ateliere[j]->NrObiecte - 1;
                oameni->Oameni[i]->Atribute["STR"] = oameni->Oameni[i]->Atribute["STR"] + ateliere->Ateliere[j]->Bonus["STR"];
                oameni->Oameni[i]->Atribute["DEX"] = oameni->Oameni[i]->Atribute["DEX"] + ateliere->Ateliere[j]->Bonus["DEX"];
                oameni->Oameni[i]->Atribute["INT"] = oameni->Oameni[i]->Atribute["INT"] + ateliere->Ateliere[j]->Bonus["INT"];
                oameni->Oameni[i]->Atribute["CHR"] = oameni->Oameni[i]->Atribute["CHR"] + ateliere->Ateliere[j]->Bonus["CHR"];
                Indice++;
            }
        }
        Indice = 0;
    }
}
void lucreaza(Om& om, Atelier& atelier) {
    int PuncteFacute = 0;
    PuncteFacute = (atelier.Coef["STR"] * om.Atribute["STR"]) + (atelier.Coef["DEX"] * om.Atribute["DEX"]) + (atelier.Coef["INT"] * om.Atribute["INT"]) + (atelier.Coef["CHR"] * om.Atribute["CHR"]);
    atelier.Puncte = atelier.Puncte + PuncteFacute;
    om.BaniOm = om.BaniOm + PuncteFacute;
    atelier.BaniAtelier = atelier.BaniAtelier - PuncteFacute;
    if (atelier.BaniAtelier < 0){
        atelier.BaniAtelier = 0;
    }
}
int main() {
    int n, m, D;
    cin >> n;
    ListaOm oameni(n);
    oameni.creeazaListaOm();
    cin >> m;
    ListaAtelier ateliere(m);
    ateliere.creeazaListaAtelier();
    cin >> D;
    for (int i = 0; i < D; i++){
        oameni.sortareOameni();
        cumpara(&oameni, &ateliere);
        oameni.sortareOameni();
        angajeaza(&oameni, &ateliere);
        productie(&ateliere);
    }
    oameni.sortareFinala();
    oameni.afisare();
    return 0;
}