// $Id: ConicProjection.cpp,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $


#include <strstream>
#include "ConicProjection.h"
#include "DatumConvertor.h"

// GCTPC includes
extern "C"
{
#include "gctpc/proj.h"
}


using namespace ProjLib;

// ***************************************************************************
ConicProjection::ConicProjection( double sMajor, double sMinor, double centMer,
                                  double originLat, double fe, double fn,
                                  DATUM d, UNIT u, DATUM geoDatum,
                                  UNIT geoUnit )
  : Projection(d,u,geoDatum,geoUnit)
{
  // Initialize all the projection parameters to zero
  for ( int i = 0; i < 15; i++ )
  {
    d_projParams[i] = 0.0;
  }
  
  setSemiMajorAxis( sMajor );
  setSemiMinorAxis( sMinor );
  setCentralMeridian( centMer );
  setOriginLatitude( originLat );
  setFalseEasting( fe );
  setFalseNorthing( fn );
}


// ***************************************************************************
ConicProjection::ConicProjection( const ConicProjection& p )
  : Projection(p)
{
  if ( this != &p )
  {
    setCentralMeridian( p.getCentralMeridian() );
    setFalseEasting( p.getFalseEasting() );
    setFalseNorthing( p.getFalseNorthing() );
    setOriginLatitude( p.getOriginLatitude() );
    setSemiMajorAxis( p.getSemiMajorAxis() );
    setSemiMinorAxis( p.getSemiMinorAxis() );
  }
}


// Comparison functions
// ***************************************************************************
bool ConicProjection::operator==( const Projection& p ) const throw()
{
  const ConicProjection* pRHS = NULL;

  try
  { 
    pRHS = dynamic_cast<const ConicProjection*>(&p);
    if ( NULL != pRHS )
    {
      if ( d_projParams[4] == pRHS->getCentralMeridian() &&
           d_projParams[6] == pRHS->getFalseEasting()    &&
           d_projParams[7] == pRHS->getFalseNorthing()   &&
           d_projParams[5]  == pRHS->getOriginLatitude()  &&
           d_projParams[0]   == pRHS->getSemiMajorAxis() )
      {
        return Projection::operator==( p );
      }
    }
  
    return false;
  }
  catch(...)
  {
    return false;
  }
}


// toString override
// ***************************************************************************
std::string ConicProjection::toString() const throw()
{
  std::string ret;
  std::strstream tempstream;
  
  try
  {
    tempstream << Projection::toString() << std::string("CENTRAL MERIDIAN: ")
               << packedDMSToString(d_projParams[4], false) << std::endl
               << std::string("ORIGIN LATITUDE: ")
               << packedDMSToString(d_projParams[5], true) << std::endl
               << std::string("FALSE EASTING: ") << d_projParams[6]
               << std::endl << std::string("FALSE NORTHING: ")
               << d_projParams[7] << std::endl
               << std::string("SEMI-MAJOR AXIS: ") << d_projParams[0]
               << std::endl << std::string("SEMI-MINOR AXIS: ")
               << d_projParams[1] << std::ends;

    ret = tempstream.str();
    return ret;
  }
  catch (...)
  {
    return std::string("");
  }
}


// Projection functions
// ***************************************************************************
bool ConicProjection::projectToGeo( double x, double y,
                                    double& latitude, double& longitude ) 
  const throw()
{
  static double outparm[15] = { 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0 };  // output parameter array

  double incoor[2];	// input coordinates (x, y)
  long   insys;		// input projection system
  long   inzone;	// input zone
  long   inunit;	// input units
  long   indatum;	// input spheroid code
  long   ipr;		// error message print flag
  char*  efile;		// file to contain output error messages
  long   jpr;		// projection parameter print flag
  char*  pfile;		// file to contain output projection parameter messages
  double outcoor[2];	// output coordinates (x, y)
  long   outsys;	// output projection system
  long   outzone;	// output zone
  long   outunit;	// output units
  long   outdatum;	// output spheroid code
  char*  fn27;		// file containing NAD 1927 state plane zones
  char*  fn83;		// file containing NAD 1983 state plane zones
  long   iflg;		// error flag

  try
  {
    // Variable initialization
    incoor[0] = x;
    incoor[1] = y;
    insys     = getProjectionSystem();
    inzone    = 0;
    inunit    = d_unit;
    indatum   = DatumConvertor::getDatumEllipsoid(d_datum);
    ipr       = -1;             // Do not print error messages
    efile     = NULL;           // No error file
    jpr       = -1;             // Do not print projection parameters
    pfile     = NULL;           // No projection parameter file
    outsys    = GEO;            // Output in geographic (lat, long)
    outzone   = 0;              // No zones for geographic
    outunit   = d_geoUnit;
    outdatum  = DatumConvertor::getDatumEllipsoid(d_geoDatum);
    fn27      = NULL;           // No NAD27 State Plane parameter file
    fn83      = NULL;           // No NAD83 State Plane parameter file
  
    // Do transformation
    gctp( incoor, &insys, &inzone, const_cast<double*>(d_projParams), &inunit, 
          &indatum, &ipr, efile, &jpr, pfile, outcoor, &outsys, &outzone, 
          outparm, &outunit, &indatum, fn27, fn83, &iflg );
  
    // Set latitude and longitude
    longitude = outcoor[0];
    latitude  = outcoor[1];

    // Convert the datums
    return convertDatum( latitude, longitude, d_datum, d_geoDatum);
  }
  catch (...)
  {
    return false;
  }
}


// ***************************************************************************
bool ConicProjection::projectFromGeo( double latitude, double longitude,
                                      double& x, double& y ) 
  const throw()
{
  static double inparm[15] = { 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0 };  // input parameter array

  double incoor[2];     // input coordinates (x, y)
  long   insys;	        // input projection system
  long   inzone;        // input zone
  long   inunit;        // input units
  long   indatum;       // input spheroid code
  long   ipr;           // error message print flag
  char*  efile;         // file to contain output error messages
  long   jpr;           // projection parameter print flag
  char*  pfile;         // file to contain output projection parameter messages
  double outcoor[2];    // output coordinates (x, y)
  long   outsys;        // output projection system
  long   outzone;       // output zone
  long   outunit;       // output units
  long   outdatum;      // output spheroid code
  char*  fn27;          // file containing NAD 1927 state plane zones
  char*  fn83;          // file containing NAD 1983 state plane zones
  long   iflg;          // error flag
  
  try
  {
    // Convert the datums
    if ( !convertDatum( latitude, longitude, d_geoDatum, d_datum) )
    {
      return false;
    }

    // Variable initialization
    incoor[0] = longitude;
    incoor[1] = latitude;
    insys     = GEO;
    inzone    = 0;
    inunit    = d_geoUnit;
    indatum   = DatumConvertor::getDatumEllipsoid(d_geoDatum);
    ipr       = -1;             // Do not print error messages
    efile     = NULL;           // No error file
    jpr       = -1;             // Do not print projection parameters
    pfile     = NULL;           // No projection parameter file
    outsys    = getProjectionSystem();
    outzone   = 0;
    outunit   = d_unit;
    outdatum  = DatumConvertor::getDatumEllipsoid(d_datum);
    fn27      = NULL;           // No NAD27 State Plane parameter file
    fn83      = NULL;           // No NAD83 State Plane parameter file

    // Do transformation
    gctp( incoor, &insys, &inzone, inparm, &inunit, &outdatum, 
          &ipr, efile, &jpr, pfile, outcoor, &outsys, &outzone, 
          const_cast<double*>(d_projParams), &outunit, 
          &outdatum, fn27, fn83, &iflg );
  
    // Set the coordinates
    x = outcoor[0];
    y = outcoor[1];
    
    return true;
  }
  catch (...)
  {
    return false;
  }
}










