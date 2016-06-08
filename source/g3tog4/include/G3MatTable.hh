// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G3MatTable.hh,v 1.8 1999/12/09 01:27:42 lockman Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// by I.Hrivnacova, 27 Sep 99

#ifndef G3MATTABLE_HH
#define G3MATTABLE_HH 1

#include "G3MatTableEntry.hh"

#include "globals.hh"

#include "g4rw/tpordvec.h"

class G4Material;

typedef G4RWTPtrOrderedVector<G3MatTableEntry>  G3MaterialVector;

class G3MatTable
{
  public:
    G3MatTable();
    virtual ~G3MatTable();
    
    // methods
    // keep the same names of methods as in G4 g3tog4
    G4Material* get(G4int id) const;
    void put(G4int id, G4Material* material);
    void Clear();

  private:
    G3MaterialVector*  fMatVector;
};

extern G3MatTable G3Mat;

#endif