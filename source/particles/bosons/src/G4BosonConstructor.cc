// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4BosonConstructor.cc,v 1.2 1999/12/15 14:50:53 gunter Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 
// --------------------------------------------------------------
//	GEANT 4 class implementatBoson file 
//

#include "G4BosonConstructor.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
// Bosons
#include "G4ChargedGeantino.hh"
#include "G4Geantino.hh"
#include "G4Gamma.hh"
#include "G4OpticalPhoton.hh"

G4BosonConstructor::G4BosonConstructor()
{
}

G4BosonConstructor::~G4BosonConstructor()
{
}


void G4BosonConstructor::ConstructParticle()
{
  // pseudo-particles
  G4Geantino::GeantinoDefinition();
  G4ChargedGeantino::ChargedGeantinoDefinition();

  // gamma
  G4Gamma::GammaDefinition();

  // optical photon
  G4OpticalPhoton::OpticalPhotonDefinition();
}
