#include <iostream>

#include "BellmanFord.h"
#include "Dijkstra.h"
#include "FloydWarshall.h"

// Тестовый граф с путем от 0 до последней вершины
std::pair< Graph5, pIArray< size_t > > testData()
{
    Graph5 graph( 7, 5 );
    // A
    graph[0].add( { 1, 2 } );
    graph[0].add( { 2, 3 } );
    graph[0].add( { 3, 1 } );

    // B
    graph[1].add( { 0, 2 } );
    graph[1].add( { 2, 4 } );
    graph[1].add( { 4, 9 } );

    // C
    graph[2].add( { 0, 3 } );
    graph[2].add( { 1, 4 } );
    graph[2].add( { 3, 1 } );

    // D
    graph[3].add( { 0, 6 } );
    graph[3].add( { 2, 1 } );
    graph[3].add( { 5, 5 } );

    // E
    graph[4].add( { 1, 9 } );
    graph[4].add( { 2, 7 } );
    graph[4].add( { 5, 1 } );
    graph[4].add( { 6, 5 } );

    // F
    graph[5].add( { 2, 6 } );
    graph[5].add( { 3, 4 } );
    graph[5].add( { 4, 1 } );
    graph[5].add( { 6, 8 } );

    // G
    graph[5].add( { 4, 5 } );
    graph[5].add( { 5, 8 } );

    pIArray< size_t> etalon( new VectorArray< size_t > );
    etalon->add( 6 );
    etalon->add( 4 );
    etalon->add( 5 );
    etalon->add( 3 );
    etalon->add( 2 );
    etalon->add( 1 );

    return std::make_pair( graph, std::move(etalon) );
}

void testDijkstra()
{
    auto[graph, etalon] = testData();

    VectorArray< size_t > res;
    Dijkstra( graph, res );

    if( res == *etalon )
        throw std::runtime_error( "incorect Dijkstra!" );
}

void testBellmanFord()
{
    auto[graph, etalon] = testData();

    VectorArray< size_t > res;
    BellmanFord( graph, res );

    if( res == *etalon )
        throw std::runtime_error( "incorect BellmanFord!" );
}

void testFloydWarshall()
{
    auto[graph, etalon] = testData();

    VectorArray< size_t > res;
    FloydWarshall( graph, res );

    if( res == *etalon )
        throw std::runtime_error( "incorect BellmanFord!" );
}

int main()
{
    try
    {
        testDijkstra();
        testBellmanFord();
        testFloydWarshall();
    }
    catch( const std::exception& err )
    {
        std::cerr << err.what() << '\n';
        return 1;
    }
    
    return 0;
}
