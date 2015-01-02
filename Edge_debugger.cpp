#include "lib/Edge.h"
#include <utility>
#include <set>
#include <string>

int main()
{
   /*
   * SOLVED
   * http://stackoverflow.com/questions/19937260/use-user-defined-struct-as-the-key-for-map-c
   *
   */

   std::set<Edge> s;
   s.insert( Edge("A") );

   return 0;
}
