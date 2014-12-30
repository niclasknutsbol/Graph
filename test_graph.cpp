	#include <iostream>
#include "lib/Graph.h"

int main()
{
   Graph G;

   G.insert_vertex("A");
   G.insert_vertex("B");
   G.insert_vertex("C");
   G.insert_vertex("D");

   G.insert_edge("A","B");
   G.insert_edge("A","C");

   G.insert_edge("B","A");
   G.insert_edge("B","C");

   G.insert_edge("D","A");
   G.insert_edge("D","A");
   G.insert_edge("D","A");
   

   //G.print_node( "A" );    
   G.print_graph();
   std::cout << '\n';

   Graph GT = G.transpose();
   GT.print_graph();
   std::cout << '\n';

   //print_graph( G.transpose() );

   Graph Gk = G.merge( GT );
   Gk.print_graph();

   return 0;
}

