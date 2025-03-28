/**
 *   Hovedprogrammet for OOP-prosjektet V25 med kunder, soner og (ene)boliger.
 *
 *   @file     MAINV25.CPP
 *   @author   Frode Haug, NTNU
 */


 #include <iostream>
 #include "kunder.h"
 #include "soner.h"
 #include "funksjoner.h"
 #include "LesData3.h"
 using namespace std;
 
 
 Kunder gKundebase;         ///<  Globalt container-objekt med ALLE kundene.
 Soner gSonebase;           ///<  Globalt container-objekt med ALLE sonene.
 
 //  Kode som legges innledningsvis i de .cpp-filene som trenger å bruke
 //  en eller begge det to globale objektene definert ovenfor:
 //         extern Kunder gKundebase;
 //         extern Soner gSonebase;
 
 
 /**
  *  Hovedprogram.
  */
 int main()  {
     char valg;
 
     gKundebase.lesFraFil();
     gSonebase.lesFraFil();
 
     skrivMeny();
     valg = lesChar("\nKommando");
 
     while(valg != 'Q')  {
       switch(valg)    {
         case 'K':            gKundebase.handling();      break;
         case 'S': case 'O':  gSonebase.handling(valg);   break;
         default:             skrivMeny();                break;
      }
      valg = lesChar("\nKommando");
     }
 
     gKundebase.skrivTilFil();
     gSonebase.skrivTilFil();
 
     cout << "\n\n";
     return 0;
 }