/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <string>
#include <string.h>

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: LowerCase
 DESCRIPTION: Converts string to lowercase letters

 Input: string
 Output: string
*********************************************************************/

using namespace std;

string LowerCase(string UpperToLower)
{
  for (int i = 0; i < UpperToLower.size(); i++) 
    {
      UpperToLower[i] = tolower(UpperToLower[i]);
    }

  return UpperToLower;
} /* end of LowerCase */