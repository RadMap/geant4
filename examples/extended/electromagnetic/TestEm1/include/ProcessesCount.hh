
// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ProcessesCount.hh,v 1.3 1999/12/15 14:48:56 gunter Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 
// -----------------------------------------------------------------
//	GEANT 4 class header file 
//
//	For information related to this code contact:
//	CERN, CN Division, ASD group
//
//      ------------------- class ProcessesCount -----------------
//
// 26-10-98: first version, M.Maire

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef ProcessesCount_HH
#define ProcessesCount_HH

#include "globals.hh"
#include "g4rw/tpordvec.h"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class OneProcessCount
{
public:
    OneProcessCount(G4String name) {Name=name; Counter=0;};
   ~OneProcessCount() {};
    G4int operator==(const OneProcessCount& right) const {return (this==&right);};
    G4int operator!=(const OneProcessCount& right) const {return (this!=&right);};
    
private:
    OneProcessCount(OneProcessCount& right)                        {*this= right;};
    const OneProcessCount& operator=(const OneProcessCount& right) {return right;};
   
public:
    G4String      GetName()       {return Name;};
    G4int         GetCounter()    {return Counter;};
    void          Count()         {Counter++;};
    
private:
    G4String Name;            // process name
    G4int    Counter;         // process counter
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....


typedef G4RWTPtrOrderedVector<OneProcessCount> ProcessesCount;

#endif