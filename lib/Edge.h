#ifndef EDGE_H
#define EDGE_H

#include <string>

class Edge
{
public:
//protected:
   Edge();
   Edge( const std::string &);
   std::string get_edge() const;
   bool operator>( const Edge& ) const;
   bool operator<( const Edge& ) const ;
   bool operator==( const Edge& ) const; 
private:
   std::string edge;
};

#endif /* EDGE_H */


