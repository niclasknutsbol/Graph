#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

Vertex*
Edge::get_neighbour() const
{
   return neighbour;
}

void
Edge::set_neighbour( Vertex *v )
{
   neighbour = v;
}
