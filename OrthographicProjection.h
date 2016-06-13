// $Id: OrthographicProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _ORTHOGRAPHICPROJECTION_H_
#define _ORTHOGRAPHICPROJECTION_H_

#include "AzimuthalProjection.h"

namespace ProjLib
{

class OrthographicProjection : public AzimuthalProjection  
{
public:
  OrthographicProjection( double centralLongitude, double centralLatitude,
                          double falseEasting, double falseNorthing,
                          double sphereRadius, DATUM d, UNIT u,
                          DATUM geoDatum = DEFAULT_DATUM,
                          UNIT geoUnit = ARC_DEGREES );
  OrthographicProjection( const OrthographicProjection& p );

  // Accessors
  PROJSYS getProjectionSystem() const throw();

  // Cloning
  Projection* clone() const throw(std::bad_alloc);

  // String override
  std::string toString() const throw();
};

// ***************************************************************************
inline PROJSYS OrthographicProjection::getProjectionSystem() const throw()
{
  return ORTHO;
}


} // namespace ProjLib

#endif

