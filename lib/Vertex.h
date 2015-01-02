#ifndef VERTEX_H
#define VERTEX_H

#include <set>
#include "Edge.h"

class Vertex
{
public:
 //protected
   Vertex();
   std::set<Edge> edges;
};

#endif /* VERTEX_H */

