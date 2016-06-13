// $Id: MillerCylindricalProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _MILLERCYLINDRICALPROJECTION_H_
#define _MILLERCYLINDRICALPROJECTION_H_

#include "PseudocylindricalProjection.h"

namespace ProjLib
{

class MillerCylindricalProjection : public PseudocylindricalProjection  
{
 public:
  MillerCylindricalProjection( double sphereRadius, double centralMeridian,
                               double falseEasting, double falseNorthing,
                               DATUM d, UNIT u,
                               DATUM geoDatum = DEFAULT_DATUM,
                               UNIT geoUnit = ARC_DEGREES );
  MillerCylindricalProjection( const MillerCylindricalProjection& p );
  
  // Accessors
  PROJSYS getProjectionSystem() const throw();

  // Cloning
  Projection* clone() const throw(std::bad_alloc);

  // String override
  std::string toString() const throw();
};


// ***************************************************************************
inline PROJSYS MillerCylindricalProjection::getProjectionSystem() const throw()
{
  return MILLER;
}

} // namespace ProjLib

#endif
