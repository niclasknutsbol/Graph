#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <algorithm>
#include <string>

class Vertex
{
public:
   Vertex() = default;

   Vertex( const std::string & n )
   : name(n)
   {}

   std::string get_name()const;
 
//protected:
   std::vector<class Edge*> neighbours;
private:
   std::string name;
};

#endif /* VERTEX_H */

