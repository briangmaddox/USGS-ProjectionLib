// $Id: AlaskaConformalProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _ALASKACONFORMALPROJECTION_H_
#define _ALASKACONFORMALPROJECTION_H_

#include "TransverseMercatorProjection.h"

namespace ProjLib
{

class AlaskaConformalProjection : public TransverseMercatorProjection  
{
public:
  AlaskaConformalProjection( double sMajor, double sMinor, 
                             double fe, double fn, 
                             DATUM d, UNIT u,
                             DATUM geoDatum = DEFAULT_DATUM,
                             UNIT geoUnit = ARC_DEGREES );
  AlaskaConformalProjection( const AlaskaConformalProjection& p );

  // Accessors
  PROJSYS getProjectionSystem() const throw();

  // Projection functions
  bool projectToGeo( double x, double y, 
                     double& latitude, double& longitude ) const throw();
  bool projectFromGeo( double latitude, double longitude,
                       double& x, double& y ) const throw();

  // toString override
  virtual std::string toString() const throw();

  // Cloning
  virtual Projection* clone() const throw(std::bad_alloc);
};

// ***************************************************************************
inline PROJSYS AlaskaConformalProjection::getProjectionSystem() const throw()
{
  return ALASKA;
}

} // namespace
#endif
