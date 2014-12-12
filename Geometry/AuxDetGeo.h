////////////////////////////////////////////////////////////////////////
/// \file  AuxDetGeo.h
/// \brief Encapsulate the geometry of an auxiliary detector
///
/// \author  miceli@fnal.gov
////////////////////////////////////////////////////////////////////////

#ifndef GEO_AuxDetGeo_H
#define GEO_AuxDetGeo_H
#include <vector>
#include "TGeoVolume.h"
#include "SimpleTypesAndConstants/geo_types.h"
class TGeoNode;
class TGeoHMatrix;
class TGeoMatrix;

namespace geo {
  
  class AuxDetGeo {
  public:
    AuxDetGeo(std::vector<const TGeoNode*>& path, int depth);
    ~AuxDetGeo();
    
    void GetCenter(double* xyz, double localz=0.0) const;
    void GetNormalVector(double* xyzDir) const;

    //box geometry
    double Length()          const { return fLength;     };
    double HalfWidth()       const { return fHalfWidth;  };
    double HalfSmallWidth()  const { return fHalfSmallWidth;  };
    double HalfHeight()      const { return fHalfHeight; };
    const TGeoVolume* TotalVolume()  const { return fTotalVolume;}
    
    double DistanceToPoint(double * xyz) const;
    
    void LocalToWorld(    const double* local, double* world) const;
    void LocalToWorldVect(const double* local, double* world) const;
    void WorldToLocal(    const double* world, double* local) const;
    void WorldToLocalVect(const double* world, double* local) const;
    
  private:
    TGeoHMatrix*          fGeoMatrix;     ///< Transformation matrix to world frame
    const TGeoVolume*     fTotalVolume;   ///< Total volume of AuxDet, called vol*
    double                fLength;        ///< length of volume
    double                fHalfWidth;     ///< half width of volume
    double                fHalfSmallWidth;///< smaller half width of the volume if a trapezoid    
    double                fHalfHeight;    ///< half height of volume
  };
}


#endif
