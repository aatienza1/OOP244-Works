/***********************************************************************
// OOP244 Workshop # 10
//
// Version 1.0
// Date: 2023/11/25
// Author: Fardad Soleimanloo
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name:Alicia Atienza            Date: 11/30/2024            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Displayable.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const Displayable& c) {
      return c.display(os);
   }
}