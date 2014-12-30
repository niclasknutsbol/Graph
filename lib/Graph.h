#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <string>
#include "Vertex.h"

class Graph : public Vertex
{
public:
   void insert_vertex( std::string);
   void insert_edge( std::string, std::string); 
   void print_vertex( const std::string) const;
   void print_graph() const;
   Graph transpose() const;
   Graph merge( const Graph & ) const;
   Graph inverse() const;
protected:
   void insert_edge( Vertex*, Vertex*);
   Vertex* get_vertex( std::string ) const;
   bool is_vertex( Vertex * );   

private:
   std::vector<Vertex*> list;
};

void print_graph( Graph );

#endif /* GRAPH_H */
