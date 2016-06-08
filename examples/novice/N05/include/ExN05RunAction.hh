// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN05RunAction.hh,v 1.6 2000/01/06 15:06:51 gcosmo Exp $
// GEANT4 tag $Name: geant4-02-00 $
//

#ifndef ExN05RunAction_h
#define ExN05RunAction_h 1

#include "globals.hh"
#include "G4UserRunAction.hh"

class G4Timer;
class G4Run;

class ExN05RunAction : public G4UserRunAction
{
  public:
    ExN05RunAction();
    ~ExN05RunAction();

  public:
    void BeginOfRunAction(const G4Run* aRun);
    void EndOfRunAction(const G4Run* aRun);

  private:
    G4Timer* timer;
};

#endif
