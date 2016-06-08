// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4DisplacedSolid.hh,v 1.7 2000/04/27 09:59:36 gcosmo Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
//
// class G4DisplacedSolid
//
// Class description:
//
// A displaced solid is a solid that has been shifted from its original
// frame of reference to a new one. It is meant to be used only for
// simplifying the implementation of "Boolean solids". 

// History:
//
// 28.10.98 V.Grichine, creation according J. Apostolakis's recommendations

#ifndef G4DisplacedSolid_HH
#define G4DisplacedSolid_HH

#include "G4VSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4AffineTransform.hh"

class G4DisplacedSolid : public G4VSolid
{
  public:  // with description

    G4DisplacedSolid( const G4String& pName,
                            G4VSolid* pSolid ,
                            G4RotationMatrix* rotMatrix,
                      const G4ThreeVector& transVector  ) ;

    G4DisplacedSolid( const G4String& pName,
                            G4VSolid* pSolid ,
                      const G4Transform3D& transform  ) ;

    G4DisplacedSolid( const G4String& pName,
                            G4VSolid* pSolid ,
		      const G4AffineTransform directTransform );
      // For use in instantiating a transient instance from a persistent one.

    virtual ~G4DisplacedSolid() ;

  public:  // without description 

    // It also has all the methods that a solid requires, eg.

    EInside Inside( const G4ThreeVector& p ) const ; 

    G4bool CalculateExtent(const EAxis pAxis,
			   const G4VoxelLimits& pVoxelLimit,
			   const G4AffineTransform& pTransform,
				 G4double& pMin, G4double& pMax) const ;

    G4ThreeVector SurfaceNormal( const G4ThreeVector& p ) const ;

    G4double DistanceToIn( const G4ThreeVector& p,
                           const G4ThreeVector& v  ) const ;

    G4double DistanceToIn( const G4ThreeVector& p) const ;

    G4double DistanceToOut( const G4ThreeVector& p,
			    const G4ThreeVector& v,
			    const G4bool calcNorm=false,
			    G4bool *validNorm=0,
			    G4ThreeVector *n=0      ) const ;

    G4double DistanceToOut( const G4ThreeVector& p ) const ;


    void ComputeDimensions( G4VPVParameterisation* p,
	                    const G4int n,
                            const G4VPhysicalVolume* pRep ) ;
                                   
  public:  // with description 

    virtual G4GeometryType  GetEntityType() const;

    virtual const G4DisplacedSolid* GetDisplacedSolidPtr() const   ;
    virtual       G4DisplacedSolid* GetDisplacedSolidPtr();
      // If the Solid is a "G4DisplacedSolid",
      // return a self pointer else return 0.

    G4VSolid*                GetConstituentMovedSolid() const;
    G4AffineTransform        GetTransform() const; 
    G4AffineTransform        GetDirectTransform() const; 
      // Access methods.

    G4RotationMatrix         GetFrameRotation() const;
    G4ThreeVector            GetFrameTranslation() const; 
      // Get the rotation/translation, as applied to the frame of reference.

    G4RotationMatrix         GetObjectRotation() const;
    G4ThreeVector            GetObjectTranslation() const; 
      // Get the rotation/translation, as applied to the object.

  public:  // without description

    void DescribeYourselfTo ( G4VGraphicsScene& scene ) const ;
    G4Polyhedron* CreatePolyhedron () const ;
    G4NURBS*      CreateNURBS      () const ;
      // For creating graphical representations (ie for visualisation).

  protected:

    G4VSolid* fPtrSolid ;
    G4AffineTransform* fPtrTransform ;
    G4AffineTransform* fDirectTransform ;
              
} ;

inline G4GeometryType G4DisplacedSolid::GetEntityType() const 
{
   return G4String("G4DisplacedSolid");
}

#endif