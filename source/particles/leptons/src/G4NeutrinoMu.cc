// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4NeutrinoMu.cc,v 1.3 2000/02/27 06:23:41 kurasige Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 
// ----------------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      For information related to this code contact:
//      CERN, CN Division, ASD Group
//      History: first implementation, based on object model of
//      4th April 1996, G.Cosmo 
//      by             H.Kurashige,7  July 1996
// **********************************************************************

#include "g4std/fstream"
#include "g4std/iomanip"

#include "G4NeutrinoMu.hh"

// ######################################################################
// ###                     MU NEUTRINO                               ###
// ######################################################################

G4NeutrinoMu::G4NeutrinoMu(
       const G4String&     aName,        G4double            mass,
       G4double            width,        G4double            charge,   
       G4int               iSpin,        G4int               iParity,    
       G4int               iConjugation, G4int               iIsospin,   
       G4int               iIsospin3,    G4int               gParity,
       const G4String&     pType,        G4int               lepton,      
       G4int               baryon,       G4int               encoding,
       G4bool              stable,       G4double            lifetime,
       G4DecayTable        *decaytable )
 : G4VLepton( aName,mass,width,charge,iSpin,iParity,
              iConjugation,iIsospin,iIsospin3,gParity,pType,
              lepton,baryon,encoding,stable,lifetime,decaytable )
{
  SetParticleSubType("mu");
}		     

// ......................................................................
// ...                 static member definitions                      ...
// ......................................................................
//     
//    Arguments for constructor are as follows
//               name             mass          width         charge
//             2*spin           parity  C-conjugation
//          2*Isospin       2*Isospin3       G-parity
//               type    lepton number  baryon number   PDG encoding
//             stable         lifetime    decay table 

G4NeutrinoMu G4NeutrinoMu::theNeutrinoMu(
              "nu_mu",         0.0*MeV,       0.0*MeV,         0.0, 
		    1,               0,             0,          
		    0,               0,             0,             
	     "lepton",               1,             0,           14,
		 true,             0.0,          NULL
);

G4NeutrinoMu* G4NeutrinoMu::NeutrinoMuDefinition()
{
  return &theNeutrinoMu;
}
G4double   G4NeutrinoMu::theNeutrinoMuLengthCut = -1.0;
G4double*  G4NeutrinoMu::theNeutrinoMuKineticEnergyCuts = NULL;

// **********************************************************************
// **************************** SetCuts *********************************
// **********************************************************************
void G4NeutrinoMu::SetCuts(G4double aCut)
{
  theCutInMaxInteractionLength = aCut;

  const G4MaterialTable* materialTable = G4Material::GetMaterialTable();
  // Create the vector of cuts in energy
  // corresponding to the stopping range cut
  if(theKineticEnergyCuts) delete [] theKineticEnergyCuts;
  theKineticEnergyCuts = new G4double [materialTable->length()];

  // Build range vector for every material, convert cut into energy-cut,
  // fill theKineticEnergyCuts and delete the range vector
  for (G4int J=0; J<materialTable->length(); J++)
  {
    G4Material* aMaterial = (*materialTable)[J];
    theKineticEnergyCuts[J] = 0.0*keV;
  }
  theNeutrinoMuLengthCut = theCutInMaxInteractionLength;  
  theNeutrinoMuKineticEnergyCuts = theKineticEnergyCuts;
  // Rebuild the physics tables for every process for this particle type
  
}
