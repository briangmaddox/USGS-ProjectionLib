// $Id: ZonedProjection.cpp,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#include "ZonedProjection.h"

using namespace ProjLib;

// ***************************************************************************
ZonedProjection::ZonedProjection( long zone )
{
  setZone( zone );
}

// ***************************************************************************
ZonedProjection::ZonedProjection( const ZonedProjection& p )
{
  if ( this != &p )
  {
    d_zone = p.d_zone;
  }
}

// ***************************************************************************
ZonedProjection::~ZonedProjection()
{
}
