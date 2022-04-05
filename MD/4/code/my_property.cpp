

#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/bellman_ford_shortest_paths.hpp>

// the predefined property types are listed here:
// http://www.boost.org/doc/libs/1_64_0/libs/graph/doc/using_adjacency_list.html#sec:adjacency-list-properties

struct VertexData
{
    std::string first_name;
    int num;
    int pred;
    int dist;
};

struct EdgeData
{
    std::string edge_name;
    double dist;
};

void example2()
{
    typedef boost::adjacency_list<boost::vecS, boost::vecS,
                                  boost::directedS,
                                  VertexData,
                                  EdgeData>
        MyGraphType;

    MyGraphType G;

    int v[3];
    v[0] = add_vertex(G);
    v[1] = add_vertex(G);
    v[2] = add_vertex(G);

    add_edge(v[0], v[1], {"edge1", 10}, G).first;
    add_edge(v[1], v[2], {"edge2", 20}, G).first;

    bellman_ford_shortest_paths(G, v[0],
                                predecessor_map(get(&VertexData::pred, G))
                                    .distance_map(get(&VertexData::pred, G))
                                    .weight_map(get(&EdgeData::dist, G)));
}

int main()
{
    example2();
}
