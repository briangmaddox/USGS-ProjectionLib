// $Id: StereographicProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _STEREOGRAPHICPROJECTION_H_
#define _STEREOGRAPHICPROJECTION_H_

#include "AzimuthalProjection.h"

namespace ProjLib
{

class StereographicProjection : public AzimuthalProjection  
{
public:
  StereographicProjection( double centralLongitude, double centralLatitude,
                           double falseEasting, double falseNorthing,
                           double sphereRadius, DATUM d, UNIT u,
                           DATUM geoDatum = DEFAULT_DATUM,
                           UNIT geoUnit = ARC_DEGREES );
  StereographicProjection( const StereographicProjection& p );
  
  // Accessors
  PROJSYS getProjectionSystem() const throw();

  // Cloning
  Projection* clone() const throw(std::bad_alloc);

  // String override
  std::string toString() const throw();
};

// ***************************************************************************
inline PROJSYS StereographicProjection::getProjectionSystem() const throw()
{
  return STEREO;
}


} // namespace ProjLib
#endif
