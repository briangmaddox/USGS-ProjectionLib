// $Id: ProjectionException.cpp,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

// Implementation for the ProjectionException class

#ifndef _PROJECTION_EXCEPTION_CPP_
#define _PROJECTION_EXCEPTION_CPP_

#include "ProjectionException.h"

using namespace ProjLib;

// ***************************************************************************
ProjectionException::ProjectionException()
  : myexception(PROJ_UNKNOWN_ERROR)
{
}

// ***************************************************************************
ProjectionException::ProjectionException(const short int& inexception)
  : myexception(inexception)
{
}

// **************************************************************************
void ProjectionException::setException(const short int& inexception) throw()
{
  myexception = inexception;
  return;
}


// ***************************************************************************
void ProjectionException::getException(short int& inexception) const throw()
{
  inexception = myexception;
  return;
}


// ***************************************************************************
void ProjectionException::getString(std::string& instring) const throw()
{
  switch (myexception)
  {
    case 0:
      instring = std::string("Projection Library: Invalid Inputs");
      break;
    case 1:
      instring = std::string("Projection Library: Invalid Projection");
      break;
    default:
      instring = std::string("Projection Library: Unknown Error");
      break;
    }

  return;
}

#endif
