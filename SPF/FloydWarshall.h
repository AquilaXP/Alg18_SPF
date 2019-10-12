#pragma once

#include <vector>
#include <limits>

#include "Graph.h"

void FloydWarshall( Graph5& graph, IArray< size_t >& path )
{
    size_t infinity = ( std::numeric_limits<size_t>::max )( );
    std::vector< std::vector< size_t > > D( graph.size(), std::vector< size_t >( graph.size(), infinity ) );
    for( size_t i = 0; i < D.size(); ++i )
        D[i][i] = 0;

    std::vector< std::vector< size_t > > P( graph.size(), std::vector< size_t >( graph.size(), infinity ) );
    // Строим матрицу
    for( size_t i = 0; i < graph.size(); ++i )
    {
        for( size_t j = 0; j < graph[i].size(); ++j )
        {
            auto& e = graph[i][j];
            D[i][e.v] = e.w;
            P[i][e.v] = e.v;
        }
    }

    for( size_t k = 0; k < D.size(); ++k )
    {
        for( size_t i = 0; i < D.size(); ++i )
        {
            for( size_t j = 0; j < D.size(); ++j )
            {
                if( i == j || D[i][k] == infinity || D[k][j] == infinity )
                    continue;

                if( D[i][j] > D[i][k] + D[k][j] )
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[i][k];
                }
            }
        }
    }

    // Сохраняем путь от 0 до последней
    path.clear();
    size_t i = 0;
    size_t j = graph.size() - 1;
    while( i != j )
    {
        i = P[i][j];
        path.add( i );
    }
}