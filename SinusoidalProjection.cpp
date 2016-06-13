// $Id: SinusoidalProjection.cpp,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#include <strstream>
#include <new>
#include "SinusoidalProjection.h"

using namespace ProjLib;

#ifdef _WIN32
#pragma warning( disable : 4291 ) // Disable warning messages for new(nothrow)
#endif

// ***************************************************************************
SinusoidalProjection::SinusoidalProjection( double sphereRadius,
                                            double centralMeridian,
                                            double falseEasting,
                                            double falseNorthing,
                                            DATUM d, UNIT u, DATUM geoDatum,
                                            UNIT geoUnit )
  : PseudocylindricalProjection(sphereRadius, centralMeridian, falseEasting,
                                falseNorthing, d, u, geoDatum, geoUnit )
{
}


// ***************************************************************************
SinusoidalProjection::SinusoidalProjection( const SinusoidalProjection& p )
  : PseudocylindricalProjection(p)
{
}


// ***************************************************************************
Projection* SinusoidalProjection::clone() const throw(std::bad_alloc)
{
  Projection* foo = NULL;
  
  if (!(foo = new(std::nothrow) SinusoidalProjection( *this ) ))
    throw std::bad_alloc();

  return foo;
}


// ***************************************************************************
std::string SinusoidalProjection::toString() const throw()
{
  std::strstream tempstream;
  std::string    ret;

  try
  {
    tempstream << std::string("Sinusoidal Projection") << std::endl
               << PseudocylindricalProjection::toString() << std::ends;

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

