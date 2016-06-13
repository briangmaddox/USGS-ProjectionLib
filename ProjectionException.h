// $Id: ProjectionException.h,v 1.1.1.1 2002-02-20 16:35:07 cbilderback Exp $
// Last modified by $Author: cbilderback $ on $Date: 2002-02-20 16:35:07 $

// This is the exception class for the projection library.

#ifndef _PROJECTION_EXCEPTION_H_
#define _PROJECTION_EXCEPTION_H_

#include <string>
#include <exception>

namespace ProjLib
{

// Series of defines for the various exceptions which can occur.
#define PROJ_INVALID_INPUT   0
#define PROJ_INVALID_PROJ    1
#define PROJ_UNKNOWN_ERROR   255

class ProjectionException
{
 public:
  ProjectionException(); // default
  ProjectionException(const short int& inexception);
  virtual ~ProjectionException() {};

  // Methods to change the exception of the current object
  void setException(const short int& inexception) throw();
  void getException(short int& inexception) const throw();
  void getString(std::string& instring)     const throw();

 protected:
  short int myexception;
};

} // namespace

#endif // #ifndef _PROJECTION_EXCEPTION_H_

