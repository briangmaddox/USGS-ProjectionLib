// $Id: ZonedProjection.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _ZONEDPROJECTION_H_
#define _ZONEDPROJECTION_H_

namespace ProjLib
{

class ZonedProjection  
{
public:
  ZonedProjection( long zone );
  ZonedProjection( const ZonedProjection& p );
  virtual ~ZonedProjection();

  // Accessors
  long getZone() const throw();

  // Modifiers
  virtual void setZone( long zone ) throw();
  /* Sets the zone for the projection.  This function can be
     overriden in derived classes to provide additional error
     checking */
  
protected:
  // Data members
  long d_zone;
};

// ***************************************************************************
inline long ZonedProjection::getZone() const throw()
{
  return d_zone;
}

// ***************************************************************************
inline void ZonedProjection::setZone( long zone ) throw()
{
  d_zone = zone;
}

} // namespace ProjLib

#endif
