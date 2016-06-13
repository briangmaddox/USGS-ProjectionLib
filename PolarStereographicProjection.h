// $Id: PolarStereographicProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _POLARSTEREOGRAPHICPROJECTION_H_
#define _POLARSTEREOGRAPHICPROJECTION_H_

#include "AzimuthalProjection.h"

namespace ProjLib
{

class PolarStereographicProjection : public AzimuthalProjection
{
 public:
  PolarStereographicProjection( double longPol, double trueScale,
                                double sMajor,  double sMinor,
                                double falseEasting, double falseNorthing,
                                DATUM d, UNIT u,
                                DATUM geoDatum = DEFAULT_DATUM,
                                UNIT geoUnit = ARC_DEGREES );
  PolarStereographicProjection( const PolarStereographicProjection& p );

  // Accessors
  double getLongitudePole() const throw();
  /* Returns the longitude down the pole of the map */
  
  PROJSYS getProjectionSystem() const throw();
  
  double getSemiMajorAxis() const throw();
  /* Returns the semi-major axis */

  double getSemiMinorAxis() const throw();
  /* Returns the semi-minor axis */

  double getTrueScaleLatitude() const throw();
  /* Returns the latitude of the true scale */

  // Modifiers
  void setLongitudePole( double longPole ) throw();
  /* Sets the longitude down the pole of the map */

  void setSemiMajorAxis( double sMajor ) throw();
  /* Sets the semi-major axis */

  void setSemiMinorAxis( double sMinor ) throw();
  /* Sets the semi-minor axis */

  void setTrueScaleLatitude( double trueScale ) throw();
  /* Sets the latitude of the true scale */

  // String override
  std::string toString() const throw();

  // Cloning
  Projection* clone() const throw(std::bad_alloc);

protected:
  // Overrides
  bool checkCoordinateRange( double latitude, double longitude ) const throw();
};

// ***************************************************************************
inline double PolarStereographicProjection::getLongitudePole() const throw()
{
  return getCentralLongitude();
}

// ***************************************************************************
inline PROJSYS PolarStereographicProjection::getProjectionSystem() 
     const throw()
{
  return PS;
}

// ***************************************************************************
inline double PolarStereographicProjection::getSemiMajorAxis() const throw()
{
  return getSphereRadius();
}

// ***************************************************************************
inline double PolarStereographicProjection::getSemiMinorAxis() const throw()
{
  return d_projectionParameters[1];
}

// ***************************************************************************
inline double PolarStereographicProjection::getTrueScaleLatitude() 
     const throw()
{
  return getCentralLatitude();
}

// ***************************************************************************
inline void PolarStereographicProjection::setLongitudePole( double longPole )
 throw()
{
  setCentralLongitude( longPole );
}

// ***************************************************************************
inline void PolarStereographicProjection::setSemiMajorAxis( double sMajor )
 throw()
{
  setSphereRadius( sMajor );
}

// ***************************************************************************
inline void PolarStereographicProjection::setSemiMinorAxis( double sMinor )
 throw()
{
  d_projectionParameters[1] = sMinor;
}

// ***************************************************************************
inline 
void PolarStereographicProjection::setTrueScaleLatitude( double trueScale )
 throw()
{
  setCentralLatitude( trueScale );
}

} // namespace ProjLib

#endif
