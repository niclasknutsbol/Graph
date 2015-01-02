#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>
#include "Vertex.h"

class Graph : public Vertex, Edge
{
public:
   void insert_vertex( std::string);
   void insert_edge( std::string, std::string);
   void remove_edge( std::string, std::string );

   Graph transpose() const;
   Graph merge( const Graph & ) const;
   Graph inverse() const;  
 
   void print_graph() const;
 
protected:
   void insert_edge( std::string, Edge);

private:
   std::map<std::string,Vertex> vertexes;
};

void print_graph( Graph );

#endif /* GRAPH_H */
