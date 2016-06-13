// $Id: TransverseMercatorProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _TRANSVERSEMERCATORPROJECTION_H_
#define _TRANSVERSEMERCATORPROJECTION_H_

#include "MercatorProjection.h"

namespace ProjLib
{

class TransverseMercatorProjection : public MercatorProjection  
{
public:
  TransverseMercatorProjection( double scaleFactor, double sMajor,
                                double sMinor, double centMer,
                                double originLat, double fe, double fn,
                                DATUM d, UNIT u,
                                DATUM geoDatum = DEFAULT_DATUM,
                                UNIT geoUnit = ARC_DEGREES );
  TransverseMercatorProjection( const TransverseMercatorProjection& p );

  // Accessors
  PROJSYS getProjectionSystem()           const throw();
  double  getCentralMeridianScaleFactor() const throw();
  
  // Modifiers
  void setCentralMeridianScaleFactor( double scaleFactor ) throw();
  /* Set the scale factor at the central meridian */

  // Projection functions
  bool projectToGeo( double x, double y, 
                     double& latitude, double& longitude ) const throw();
  bool projectFromGeo( double latitude, double longitude,
                       double& x, double& y ) const throw();
  
  // Operator overloads
  bool operator==( const Projection& p ) const throw();

  // toString override
  virtual std::string toString() const throw();

  // Cloning
  virtual Projection* clone() const throw(std::bad_alloc);
};

// ***************************************************************************
inline PROJSYS TransverseMercatorProjection::getProjectionSystem() 
  const throw()
{
  return TM;
}

// ***************************************************************************
inline double 
TransverseMercatorProjection::getCentralMeridianScaleFactor() const throw()
{
  return d_projParams[2];
}

// ***************************************************************************
inline void
TransverseMercatorProjection::setCentralMeridianScaleFactor( double scaleFactor) throw()
{
  d_projParams[2] = scaleFactor;
}


} // namespace ProjLib
#endif
