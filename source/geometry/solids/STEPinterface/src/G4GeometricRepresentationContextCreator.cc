// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4GeometricRepresentationContextCreator.cc,v 1.3 2000/01/21 13:46:02 gcosmo Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// ----------------------------------------------------------------------
// Class G4GeometricRepresentationContextCreator
//
// Authors: J.Sulkimo, P.Urban.
// Revisions by: L.Broglia, G.Cosmo.
//
// History:
//   18-Nov-1999: First step of re-engineering - G.Cosmo
// ----------------------------------------------------------------------

#include "G4GeometricRepresentationContextCreator.hh"
#include "G4GeometryTable.hh"

G4GeometricRepresentationContextCreator
  G4GeometricRepresentationContextCreator::csc;

G4GeometricRepresentationContextCreator::
  G4GeometricRepresentationContextCreator()
{
  G4GeometryTable::RegisterObject(this);
}

G4GeometricRepresentationContextCreator::
  ~G4GeometricRepresentationContextCreator() {}

void G4GeometricRepresentationContextCreator::CreateG4Geometry(STEPentity& Ent)
{
  // Made by L. Broglia
  STEPattribute *Attr;

  G4String attrName("coordinate_space_dimension");
  Attr = GetNamedAttribute(attrName, Ent);

  // Get coordinate space dimension
  SdaiReal Tmpdim = *Attr->ptr.r; // ptr.r --> REAL_TYPE

  // void *tmp = G4GeometryTable::CreateObject(*TmpEnt);
  // place = (G4Axis2Placement3D*)tmp...;

}

void G4GeometricRepresentationContextCreator::CreateSTEPGeometry(void* G4obj)
{
}