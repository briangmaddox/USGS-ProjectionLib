// $Id: GnomonicProjection.cpp,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#include <new>
#include <strstream>
#include "GnomonicProjection.h"

using namespace ProjLib;

#ifdef _WIN32
#pragma warning( disable : 4291 ) // Disable warning messages for new(nothrow)
#endif

// ***************************************************************************
GnomonicProjection::GnomonicProjection( double centralLongitude,
                                        double centralLatitude,
                                        double falseEasting,
                                        double falseNorthing,
                                        double sphereRadius, DATUM d, UNIT u,
                                        DATUM geoDatum, UNIT geoUnit )
  : AzimuthalProjection(centralLongitude, centralLatitude, falseEasting,
                        falseNorthing, sphereRadius, d, u, geoDatum, geoUnit )
{
}


// ***************************************************************************
GnomonicProjection::GnomonicProjection( const GnomonicProjection& p )
: AzimuthalProjection(p)
{
}


// ***************************************************************************
Projection* GnomonicProjection::clone() const throw(std::bad_alloc)
{
  Projection* foo = NULL;
  
  if (!(foo = new(std::nothrow) GnomonicProjection(*this)))
    throw std::bad_alloc();

  return foo;
}

// ***************************************************************************
std::string GnomonicProjection::toString() const throw()
{
  std::strstream tempstream;
  std::string    ret;

  try
  {
    tempstream << std::string("Gnomonic Projection") << std::endl
               << AzimuthalProjection::toString() << std::ends;

    ret = tempstream.str();
    tempstream.freeze(false);
    return ret;
  }
  catch (...)
  {
    return std::string("");
  }
}

#ifdef _WIN32
#pragma warning( default : 4291 ) // Enable warning messages for new(nothrow)
#endif
