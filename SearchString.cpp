/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <string.h>

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: SearchString
 DESCRIPTION: Searches string from a given string and tells position
              if search string is found from given string
 Input: void
 Output: void
*********************************************************************/

using namespace std;

void SearchString()
{
  string Given;
  string Search;
  size_t StringFound;

  cout << "Give a string from which to search for: ";
  cin >> Given;
  cout << endl;

  cout << "Give search string: ";
  cin >> Search;
  cout << "\n" << endl;

  StringFound = Given.find(Search);

  if (StringFound && StringFound != string::npos)
    {
      cout << Search << " found in " << Given << " in position " << StringFound << endl;
    }
  else if (StringFound == 0)
    {
      cout << Search << " found in " << Given << " in position 0" << endl;
    }
  else
    {
      cout << Search << " not found in " << Given << endl;
    }
} /* end of SearchString */