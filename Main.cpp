/*********************************************************************

 1.  NAME
       mygrep

 2.  DESCRIPTION
       grep program with functions for searching from user given strings 
       and searching from a file with given options.

 3.  VERSIONS
       Original:
         28.02.2022 / Marko Sulkunen

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include "SearchString.cpp"
#include "SearchFile.cpp"

/*********************************************************************
*    MAIN PROGRAM                                                    *
**********************************************************************/

int main(int argc, char *argv[])
{
  if (argv[1] && argv[2] || argv[1] && argv[2] && argv[3])
    {
      SearchFile(argc, argv);
    }
  else
    {
      SearchString();
    }

  return 0;
} /* end of main */