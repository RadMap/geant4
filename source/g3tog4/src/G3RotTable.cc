// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G3RotTable.cc,v 1.12 2000/07/24 11:32:14 gcosmo Exp $
// GEANT4 tag $Name: g3tog4-V02-00-03 $
//
// by I.Hrivnacova, 27 Sep 99

#include "G3RotTable.hh"

G3RotTable::G3RotTable()
{
  fRotVector = new G3RotMatrixVector();
}

G3RotTable::~G3RotTable()
{
  fRotVector->clear();
  //fRotVector->clearAndDestroy();
  delete fRotVector;
}

G4RotationMatrix* G3RotTable::Get(G4int id) const
{
  for (G4int i=0; i<fRotVector->entries(); i++) {
    G3RotTableEntry* rte = (*fRotVector)[i];
    if (id == rte->GetID()) return rte->GetMatrix();
  }
  return 0;
}    

void G3RotTable::Put(G4int id, G4RotationMatrix* matrix)
{
  G3RotTableEntry* rte = new G3RotTableEntry(id, matrix);
  fRotVector->insert(rte);
}

void G3RotTable::Clear()
{
  fRotVector->clearAndDestroy();
}