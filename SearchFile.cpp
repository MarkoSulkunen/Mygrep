/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "LowerCase.cpp"

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: SearchFile
 DESCRIPTION: Searches string from given file and gives different results
              based on a given option

 Input: int& argc, char* argv[]
 Output: void
*********************************************************************/

using namespace std;

void SearchFile(int& argc, char* argv[])
{
  char *filename;
  string SearchText;
  string OriginalText;
  string Options;

  bool Line = false;
  bool Occur = false;
  bool Case = false;
  bool Reverse = false;

  if (argv[1][0] == '-' && argv[1][1] == 'o' && argv[3]) // after -o takes given option
    {
      filename = argv[3];
      SearchText = argv[2];
      OriginalText = argv[2];
      Options = argv[1];
    }
  else
    {
      filename = argv[2];
      SearchText = argv[1];
      OriginalText = argv[1];
    }

  Options.erase(0,2);

  /* line number option */
  if (Options.find('l') != string::npos)
    {
      Line = true;
    }

  /* occurrence/only matching option */
  if (Options.find('o') != string::npos)
    {
      Occur = true;
    }

  /* ignore case option */
  if (Options.find('i') != string::npos) 
    {
      Case = true;
    }

  /* reverse search option */
  if (Options.find('r') != string::npos)
    {
      Reverse = true;
    }

  if (Case) 
    {
      SearchText = LowerCase(SearchText);
    }
     
  string text, textCopy;

  ifstream File;

  try
    {
      File.open(filename);
      
      if(File.fail())
        {
          throw "File could not be opened \n";
        }
    }
  catch (const char* message)
    {
      cout << message << endl;
      exit(1);
    }

  int lineNumber = 0;
  int count = 0;

  while (!File.eof())
    {
      getline(File, textCopy);
      lineNumber++;

      if (Case) 
        {
          text = LowerCase(textCopy);
        } 
      else 
        {
          text = textCopy;
        }

      if(!Reverse)
        {
          if (text.find(SearchText) != string::npos)
            {
              count++;

              if (Line)
                {
                  cout << lineNumber << ":\t";
                }

              cout << textCopy << endl;
            }
        }

      if(Reverse)
        {
          if (text.find(SearchText) == string::npos)
            {
              count++;

              if (Line)
                {
                  cout << lineNumber << ":\t";
                }

              cout << textCopy << endl;
            }
        }
    }

  if (Occur && !Reverse)
    {
      cout << "\n \n Occurrences of lines containing '" << OriginalText << "': " << count << endl;
    }

  if (Occur && Reverse)
    {
      cout << "\n \n Occurrences of lines not containing '" << OriginalText << "': " << count << endl;
    }
} /* end of SearchFile */