#include <iostream>

using namespace std;

struct toprema{
  int sifra;
  char naziv[51];
  char proizvodjac[51];
  int godina;
  int matbr;
};

struct tlista{
  toprema oprema[1001];
  int cursor;
};

typedef int element;

element FirstL(tlista *l){
  return 0;
}

element EndL(tlista *l){
  return l->cursor;
}

element PreviousL(element p, tlista *l){
  if(p==FirstL(l)) return -1;
  return p-1;
}

element NextL(element p, tlista *l){
  if(p==PreviousL(EndL(l),l)) return EndL(l);
  return p+1;
}

element LocateL(toprema x, tlista *l){
  int j;
  for(j=0;j<EndL(l);j++){
    if(x.sifra!=0){
      if(x.sifra == l->oprema[j].sifra)
        return j;
    }
    else if(x.matbr!=0){
      if(x.matbr == l->oprema[j].matbr)
        return j;
    }
  }
  return EndL(l);
}

element InsertL(toprema x, element p, tlista *l){
  int j;
  for(j=EndL(l);j>p;j--)
     l->oprema[j]=l->oprema[j-1];
  l->oprema[p]=x;
  l->cursor=l->cursor+1;
  if(l->oprema[p].sifra==x.sifra)
     return 1;
  else 
     return 0;
}

element DeleteL(element p, tlista *l){
  int j;
  int pom=l->cursor;
  for(j=p;j<EndL(l);j++)
     l->oprema[j]=l->oprema[j+1];
  if(p!=EndL(l)) 
     l->cursor=l->cursor-1;
  if(pom!=l->cursor)
     return 1;
  else
     return 0;
}
        
toprema RetrieveL(element p, tlista *l){
  return l->oprema[p];
}
                  
element DeleteAllL(tlista *l){
  l->cursor=0;
  return 1;
}        

tlista* InitL(tlista *l){
  l = new tlista;
  l->cursor=0;
  return l;
}        
