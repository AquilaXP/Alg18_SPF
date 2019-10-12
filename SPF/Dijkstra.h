#pragma once

#include "Graph.h"


void Dijkstra( Graph5& graph, IArray< size_t >& path )
{
    struct D
    {
        size_t w; ///< Вес
        size_t p; ///< Предыдущая вершина
    };
    // Фиксируем бесконечность
    size_t infinity = ( std::numeric_limits<size_t>::max )( );
    // Заполняем
    std::vector< D > vertex( graph.size(), { infinity, infinity } );
    vertex[0] = D{ 0, infinity };

    std::vector< bool > used( graph.size(), false );
    for( size_t i = 0; i < vertex.size(); ++i )
    {
        size_t minV = 0;
        size_t minW = infinity;
        for( size_t j = 0; j < used.size(); ++j )
        {
            if( used[j] == false )
            {
                if( vertex[j].w < minW )
                {
                    minW = vertex[j].w;
                    minV = j;
                }
            }
        }

        for( size_t j = 0; j < graph[minV].size(); ++j )
        {
            auto& sv = graph[minV][j];
            if( used[sv.v] == false )
            {
                if( vertex[sv.v].w > vertex[minV].w + sv.w )
                {
                    vertex[sv.v].w = vertex[minV].w + sv.w;
                    vertex[sv.v].p = minV;
                }
            }
        }
        used[minV] = true;
    }

    // Формируем путь
    path.clear();
    size_t curr = graph.size() - 1;
    while( true )
    {
        path.add( curr );
        if( vertex[curr].p == infinity )
            break;
        curr = vertex[curr].p;
    }
}