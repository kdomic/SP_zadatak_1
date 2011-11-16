#include <iostream>
#include "lista_polje.h"
//#include "lista_pokazivaci.h"

using namespace std;

//Globalne varijable
  int sifra = 10000;
  
void unos(char *niz){
  cin.getline(niz, 50);
  if(cin.gcount()==1)
    cin.getline(niz,50);
}

int noviZapis(tlista *l){
  system("cls");
  toprema x;
  cout << "Sifra: " << sifra << endl; x.sifra = sifra;
  cout << "Naziv opreme: "; unos(x.naziv);
  cout << "Naziv proizvidjaca: "; unos(x.proizvodjac);
  cout << "Godina proizvodnje: "; cin >> x.godina;
  cout << "Mat.br. zaposlenika: "; cin >> x.matbr;
  int test = InsertL(x, EndL(l), l);
  if(test==1){
    cout << endl << "Zapis je uspjesno dodan" << endl;
    sifra++;
    return 1;
  }
  else return 0;
  system("pause");
}

void ispis(toprema x){
  cout << "Sifra: " << x.sifra << endl;
  cout << "Naziv: " << x.naziv << endl;
  cout << "Proizvodjac: " << x.proizvodjac << endl;
  cout << "Godina: " << x.godina << endl;
  cout << "Zapolenik: " << x.matbr << endl;
  cout << endl;
}

void ispisSilazno(tlista *l, bool _2009=false){
  system("cls");
  int num=0;
  toprema x;
  element last = PreviousL(EndL(l), l);
  if(EndL(l) != FirstL(l))
    while(true){
      x = RetrieveL(last, l);
      if(!_2009)
        ispis(x);
      else if(x.godina>2009){
        ispis(x);
        num++;
      }
      if(last == FirstL(l)) break;
      last = PreviousL(last, l);
    }
  if(_2009) cout << "Unupno nakon 2009.: " << num << endl;
  system("pause");
}

int brisanje(tlista *l){
  system("cls");
  toprema x;
  bool test = false;
  cout << "Brisanje zapisa po Sifri zapisa" << endl << endl;
  cout << "Sifra: "; cin >> x.sifra;
  x.matbr = 0;
  element p = LocateL(x, l);
  if(p != EndL(l))
    test = DeleteL(p, l);
  if(test){
    cout << "Zapis sa sifrom: " << x.sifra << " uspjesno je uklonjen." << endl;
    system("pause");
    return 1;
  } else {
    cout << "Zapis sa sifrom: " << x.sifra << " nije pronadjen." << endl;
    return 0;
  }
}

int umirovi(tlista *l){
  system("cls");
  toprema x;
  bool test = false;
  cout << "Umirovljenje zaposlenika" << endl << endl;
  cout << "Mat. br. zaposlanika: "; cin >> x.matbr;
  x.sifra = 0;
  while(LocateL(x, l) != EndL(l))
    test = DeleteL(LocateL(x, l), l);

  if(test){
    cout << "Zaposlenik: " << x.matbr << " je razduzen." << endl;
    system("pause");
    return 1;
  } else {
    cout << "Zaposlenik: " << x.matbr << " nije pronadjen." << endl;
    system("pause");
    return 0;
  }
  system("pause");
}

void sort(tlista *l){
  if(EndL(l) == FirstL(l)) return;
  toprema x1, x2;
  element last, end;
  bool zamjena;
  do{
    zamjena = false;
    last = FirstL(l);
    end = PreviousL(EndL(l),l);
    while(last != end){
      x1 = RetrieveL(last, l);
      last = NextL(last, l);
      x2 = RetrieveL(last, l);
      if(strcmp(x1.proizvodjac, x2.proizvodjac)<0){
        InsertL(x1, NextL(last, l), l);
        DeleteL(PreviousL(last,l), l);
        zamjena = true;
      }
    }
  }while(zamjena);
}

int main(){
  tlista *l = InitL(l);
  int izbor;

  do{
    system("cls");
    cout << "Izbornik" << endl << endl;
    cout << "1 - Unos novog zapisa" << endl;
    cout << "2 - Ispis(silazno)" << endl;
    cout << "3 - Ispis proizvoda proizvedenih nakon 2009" << endl;
    cout << "4 - Brisanje po Sifri opreme" << endl;
    cout << "5 - Umirovljenje zaposlenika" << endl;
    cout << "6 - Sortiranje i ispis zapisa" << endl;
    cout << "0 - Kraj rada" << endl << endl;
    cout << "Vas izbor: ";
    cin >> izbor;

    switch(izbor){
      case 1: noviZapis(l); break;
      case 2: ispisSilazno(l); break;
      case 3: ispisSilazno(l,1); break;
      case 4: brisanje(l); break;
      case 5: umirovi(l); break;
      case 6: sort(l); ispisSilazno(l); break;
      case 0: cout << "Kraj rada." << endl; break;
      default: cout << "Krivi unos!" << endl; system("pause");
    }
  }while(izbor);


  system("pause");
  return 0;
}
