// $Id: SinusoidalProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _SINUSOIDALPROJECTION_H_
#define _SINUSOIDALPROJECTION_H_

#include "PseudocylindricalProjection.h"

namespace ProjLib
{

class SinusoidalProjection : public PseudocylindricalProjection  
{
public:
  SinusoidalProjection( double sphereRadius, double centralMeridian,
                        double falseEasting, double falseNorthing,
                        DATUM d, UNIT u,
                        DATUM geoDatum = DEFAULT_DATUM,
                        UNIT geoUnit = ARC_DEGREES );
  SinusoidalProjection( const SinusoidalProjection& p );

  // Accessors
  PROJSYS getProjectionSystem() const throw();

  // Cloning
  Projection* clone() const throw(std::bad_alloc);

  // String override
  std::string toString() const throw();
};

// ***************************************************************************
inline PROJSYS SinusoidalProjection::getProjectionSystem() const throw()
{
  return SNSOID;
}

}
#endif
