// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN02PrimaryGeneratorAction.hh,v 1.2 1999/12/15 14:49:20 gunter Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 

#ifndef ExN02PrimaryGeneratorAction_h
#define ExN02PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class ExN02DetectorConstruction;
class G4ParticleGun;
class G4Event;
class ExN02PrimaryGeneratorMessenger;

class ExN02PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    ExN02PrimaryGeneratorAction(ExN02DetectorConstruction* myDC);    
    ~ExN02PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event* anEvent);
    void SetRndmFlag(G4String val) { rndmFlag = val;}

  private:
    G4ParticleGun* particleGun;
    ExN02DetectorConstruction* myDetector;
    
    ExN02PrimaryGeneratorMessenger* gunMessenger;
    G4String rndmFlag;       
};

#endif

