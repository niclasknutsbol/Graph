#include <string>
#include "Edge.h"

Edge::Edge() = default;

Edge::Edge( const std::string & e )
   : edge( e )
   {}

std::string
Edge::get_edge() const
{
   return edge;
}

bool
Edge::operator>( const Edge & E ) const
{
   return get_edge() > E.get_edge();
};

bool
Edge::operator<( const Edge & E ) const
{
   return get_edge() < E.get_edge();
};

bool
Edge::operator==( const Edge & E ) const
{
   return get_edge() == E.get_edge();
}


