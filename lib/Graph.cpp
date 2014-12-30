#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"

void
Graph::insert_vertex( std::string name)
{
   for( auto& vertex  : list  )
   {
      if( name == vertex -> get_name() )
      {
         return;
      }
   }

   Vertex *temp = new Vertex(name);
   list.push_back ( temp );
}

void 
Graph::insert_edge( Vertex *n, Vertex *new_edge )
{
if( n == nullptr || new_edge == nullptr )
   {
      return;
   }

   if( !is_vertex( n ) )
   {
      return;
   }

   for( auto& vertex : list )
   {
      if( n -> get_name() == vertex -> get_name() )
      {
         for( auto& current_edges : vertex -> neighbours )
         {
            if( current_edges -> get_neighbour() -> get_name() == new_edge -> get_name() )
            {
               return;
            }
         } 
         Edge* temp = new Edge;
         temp -> set_neighbour( new_edge );
         vertex -> neighbours.push_back( temp );
      }
   }
}

void
Graph::insert_edge( std::string n, std::string new_edge)
{
   Vertex* temp1 = get_vertex( n );
   Vertex* temp2 = get_vertex( new_edge );
   insert_edge( temp1, temp2 );
}

Vertex*
Graph::get_vertex( std::string name ) const
{
   for( auto& vertex : list )
   {
      if( name == vertex -> get_name() )
      {
         return vertex;
      }
   }
return nullptr;
}

void
Graph::print_vertex( std::string name ) const
{  
   std::cout << name << " : ";
   for( auto&  vertex : list )
   {
      if(name == vertex -> get_name() )
      {
         for( auto& edge : vertex -> neighbours )
         {
            std::cout << " -> " << edge -> get_neighbour() -> get_name();
         }
         std::cout << std::endl;
         break;
      }
   }
}

void
Graph::print_graph() const
{
   for( auto&  vertex : list )
   {
      std::cout << vertex -> get_name() << " : ";
      for( auto& edge : vertex -> neighbours )
      {
       std::cout << " -> " << edge -> get_neighbour() -> get_name();
      }
      std::cout << std::endl;
   }
}

bool
Graph::is_vertex( Vertex *n )
{
for( auto& vertex : list )
   {
      if( vertex -> get_name() == n -> get_name() )
      {
         return true;
      }
   }
   return false; 
}



Graph
Graph::transpose() const
{
   Graph Graph_T;

   for( auto& vertex : list )
   {
      Graph_T.insert_vertex( vertex -> get_name() );
   }

   for( auto& vertex : list )
   {
      for( auto& edges : vertex -> neighbours )
      {
         Graph_T.insert_edge(edges -> get_neighbour() ,vertex );
      }
   }
   return Graph_T;  
}

Graph
Graph::merge( const Graph & G2 ) const
{
   Graph temp;
   for( auto& vertex : list)
   {
      temp.insert_vertex( vertex -> get_name() );
   }

   for( auto& vertex : G2.list)
   {
      temp.insert_vertex( vertex -> get_name() );
   }


   for( auto& vertex : list )
   {
      for( auto edge : vertex -> neighbours )
      {
         temp.insert_edge( vertex, edge -> get_neighbour() ); 
      }   
   }

   for( auto& vertex : G2.list )
   {
      for( auto edge : vertex -> neighbours )
      {
         temp.insert_edge( vertex, edge -> get_neighbour() ); 
      }   
   }
   return temp;
}

Graph
Graph::inverse() const
{
/*
   Graph temp;

   for( auto& vertex : list )
   {
      temp.insert_vertex( vertex );
   }

   for( auto& vertex : list )
   {
      for( auto edge : vertex -> neighbours )
      {
         temp.insert_edge( vertex, edge -> get_neighbour() ); 
      }   
   }
*/
   //TODO
   //HOW TO DO THIS?

   //REMOVE
   return *this;
}
//Global functions
void print_graph( Graph G )
{
   G.print_graph();
}




