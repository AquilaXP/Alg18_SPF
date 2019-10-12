#pragma once

#include "Graph.h"
#include "Edge.h"

void BellmanFord( Graph5& graph, IArray< size_t >& path )
{
    struct D
    {
        size_t w; ///< Вес
        size_t p; ///< Предыдущая вершина
    };
    // Фиксируем бесконечность
    size_t infinity = ( std::numeric_limits<size_t>::max )( );
    // Заполняем начальные значения вершин
    std::vector< D > vertex( graph.size(), { infinity, infinity } );
    // Первую помечаем 0
    vertex[0] = D{ 0, infinity };

    while( true )
    {
        bool relaction = false;
        // Обходим все ребра
        for( size_t i = 0; i < graph.size(); ++i )
        {
            for( size_t j = 0; j < graph[i].size(); ++j )
            {
                auto& e = graph[i][j];
                if( vertex[i].w < infinity )
                {
                    // Лучше, перезаписываем и запоминаем, откуда пришли
                    if( vertex[e.v].w > vertex[i].w + e.w )
                    {
                        vertex[e.v].w = vertex[i].w + e.w;
                        vertex[e.v].p = i;
                        relaction = true;
                    }
                }
            }
        }
        if( relaction == false )
            break;
    }

    // Сохраняем путь от 0 до последней
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