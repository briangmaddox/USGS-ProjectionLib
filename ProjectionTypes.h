// $Id: ProjectionTypes.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

#ifndef _PROJECTIONTYPES_H_
#define _PROJECTIONTYPES_H_

namespace ProjLib
{

// Enumeration of the ellipsoid types
enum ELLIPSOID
{
  CLARKE_1866 = 0, CLARKE_1880, BESSEL, INTERNATIONAL_1967,
  INTERNATIONAL_1909, WGS_72_ELLIPSOID, EVEREST, WGS_66, GRS_1980, AIRY,
  MODIFIED_EVEREST, MODIFIED_AIRY, WGS_84_ELLIPSOID, SOUTHEAST_ASIA,
  AUSTRALIAN_NATIONAL, KRASSOVSKY, HOUGH, MERCURY_1960,
  MODIFIED_MERCURY_1968, SPHERE_RADIUS_6370997_M,
  UNKNOWN_ELLIPSOID = -1, NO_ELLIPSOID = -2 
};

// Enumeration of projection system types
enum PROJSYS
{ 
  GEO = 0, UTM, SPCS, ALBERS, LAMCC, MERCAT, PS,
  POLYC, EQUIDC, TM, STEREO, LAMAZ, AZMEQD, GNOMON,
  ORTHO, GVNSP, SNSOID, EQRECT, MILLER, VGRINT, HOM,
  ROBIN, SOM, ALASKA, GOOD, MOLL, IMOLL, HAMMER,
  WAGIV, WAGVII, OBLEQA, USER_DEFINED, UNKNOWN_PROJSYS = -1
};

// Enumeration of the unit types
enum UNIT 
{
  RADIANS = 0, US_FEET, METERS, ARC_SECONDS, ARC_DEGREES, INTERNATIONAL_FEET,
  STATE_ZONE_TABLE, UNKNOWN_UNIT = -1 
};

// Enumeration of the datum types
enum DATUM 
{
  ADINDAN = 0, ARC1950, ARC1960, AUSTRALIAN_GEODETIC_1966,
  AUSTRALIAN_GEODETIC_1984, CAMP_AREA_ASTRO, CAPE,
  EUROPEAN_DATUM_1950, EUROPEAN_DATUM_1979, GEODETIC_DATUM_1949,
  HONG_KONG_1963, HU_TZU_SHAN, INDIAN, NAD27, NAD83, 
  OLD_HAWAIIAN_MEAN, OMAN, ORDNANCE_SURVEY_1936, PUERTO_RICO, 
  PULKOVO_1942, PROVISIONAL_S_AMERICAN_1956, TOKYO, WGS_72, WGS_84, 
  UNKNOWN_DATUM = -1, NO_DATUM = -2, DEFAULT_DATUM = -3 
};

} // namespace ProjLib
#endif