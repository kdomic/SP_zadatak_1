#include <iostream>

using namespace std;

struct toprema{
  int sifra;
  char naziv[30];
  char proizvodjac[30];
  int godina;
  int matbr;
};
       
struct tlista{
  toprema oprema;
  tlista *sljedeci;
};
       
typedef tlista *element;

element FirstL(tlista *l){
    return l->sljedeci;        
}

element EndL(tlista *l){
    tlista *tekuci = l;
    while(tekuci->sljedeci)
       tekuci=tekuci->sljedeci;
    return tekuci;
}

element NextL(element p, tlista *l){
    if(p->sljedeci==NULL) return EndL(l);
    return p->sljedeci;
}

element PreviousL(element p, tlista *l){
    tlista *tekuci = l->sljedeci;
    while(p != tekuci->sljedeci && tekuci->sljedeci!=NULL)
       tekuci=tekuci->sljedeci;
    return tekuci;
}

element LocateL(toprema x, tlista *l){
     element tekuci;
     tekuci = l->sljedeci;
     while(tekuci){
        if(x.sifra!=0){
           if(x.sifra == tekuci->oprema.sifra)
              return tekuci;
        }
        else if(x.matbr!=0){
           if(x.matbr == tekuci->oprema.matbr)     
              return tekuci;
        }
        tekuci = tekuci->sljedeci;
     }
     return EndL(l);
}

int InsertL(toprema x, tlista *p, tlista *l){
    tlista *tekuci = p;
    tlista *novi = new tlista;
    
    if(p==EndL(l)){
       novi->sljedeci=NULL;
       tekuci->sljedeci = novi;
       tekuci->oprema = x;
    }
    else if(p==FirstL(l)){
         novi->sljedeci = tekuci;
         l->sljedeci = novi;
         novi->oprema = x;
    }
    else{
         tlista *prethodni = PreviousL(p,l);
         novi->sljedeci=tekuci;
         prethodni->sljedeci = novi;
         novi->oprema = x;
    }
    if(tekuci->oprema.sifra==x.sifra)
       return 1;
    else
       return 0;
}

int DeleteL(element p, tlista *l){
    element prethodni, tekuci;
    tekuci = p;
    if(p==FirstL(l)){
       l->sljedeci = tekuci->sljedeci;
       delete tekuci;
       return 1;
    }
    else{
       prethodni = PreviousL(tekuci,l);
       prethodni->sljedeci = tekuci->sljedeci;
       delete tekuci;
       return 1;
    }
    return 0;
}

toprema RetrieveL(element p, tlista *l){
    return p->oprema;
}

element DeleteAllL(tlista *l){
     l->sljedeci = EndL(l);
}

tlista* InitL(tlista *l){
        l = new tlista;
        tlista *zadnji = new tlista;
        l->sljedeci = zadnji;
        zadnji->sljedeci = NULL;
        return l;
}
