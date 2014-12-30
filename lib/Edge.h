#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{
public:
   Vertex* get_neighbour() const;
   void set_neighbour( Vertex *v );
private:
   Vertex *neighbour;
};

#endif /* EDGE_H */


