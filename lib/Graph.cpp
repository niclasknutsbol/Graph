#include <iostream>
#include <set>
#include <map>
#include <string>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include <utility>

void
Graph::insert_vertex( std::string name)
{
   std::pair<std::string, Vertex> temp (name, Vertex() );
   vertexes.insert( temp );
}

void 
Graph::insert_edge( std::string node, Edge new_edge )
{
   auto it = vertexes.find( node );
   if( it != vertexes.end() )
   {
     it -> second.edges.insert( new_edge );
   }
}

void
Graph::insert_edge( std::string node, std::string new_edge )
{
   if( node != new_edge )
   {
      Edge temp( new_edge );
      insert_edge( node, temp );
   }
}

void
Graph::remove_edge( std::string node, std::string edge )
{
   for( auto& pair : vertexes )
   {
      if( pair.first == node )
      {
         pair.second.edges.erase( edge );
      }
   }
}
 
void
Graph::print_graph() const
{
   for( auto&  pair : vertexes )
   {
      std::cout << pair.first << " : ";
      for( auto& edge : pair.second.edges )
      {
         std::cout << " -> " << edge.get_edge();
      }
      std::cout << std::endl;
   }
}


Graph
Graph::transpose() const
{
   Graph Graph_T;

   //Vertex
   for( auto& pair : vertexes )
   {
      Graph_T.insert_vertex( pair.first );
   }

   //Edges
   for( auto& pair : vertexes )
   {
      for( auto& edge : pair.second.edges )
      {
         Graph_T.insert_edge(edge.get_edge() ,pair.first );
      }
   }
   return Graph_T;  
}

Graph
Graph::merge( const Graph & G2 ) const
{
   Graph temp;

   //Merge vertexes
   for( auto& pair : vertexes)
   {
      temp.insert_vertex( pair.first );
   }

   for( auto& pair : G2.vertexes )
   {
      temp.insert_vertex( pair.first );
   }

   //Merge edges
   for( auto& pair : vertexes )
   {
      for( auto edge : pair.second.edges )
      {
         temp.insert_edge( pair.first, edge.get_edge() ); 
      }   
   }

   for( auto& pair : G2.vertexes )
   {
      for( auto edge : pair.second.edges )
      {
         temp.insert_edge( pair.first, edge.get_edge() ); 
      }   
   }
   return temp;
}

Graph
Graph::inverse() const
{
   //Create a Graph temp which is complete
   Graph temp;

   for( auto& pair : vertexes )
   {
      temp.insert_vertex( pair.first );
   }

   for( auto& pair : vertexes )
   {
      for( auto vertex : vertexes )
      {
         temp.insert_edge( pair.first,vertex.first  ); 
      }   
   }

  
   //Remove all edges which is THIS graph
   for( auto& pair : vertexes )
   {
      for( auto edge : pair.second.edges )
      {
         temp.remove_edge( pair.first, edge.get_edge()  );
      }   
   }

   return temp;
}


//Global functions
void print_graph( Graph G )
{
   G.print_graph();
}

