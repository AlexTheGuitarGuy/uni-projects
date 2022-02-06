#pragma once
#include <iostream>
#include "classes/incidencyMatrixGraphClass.h"
#include "classes/adjacencyMatrixGraphClass.h"
#include "classes/adjacencyListGraphClass.h"
#include "converters/al_to_am.cpp"
#include "converters/am_to_al.cpp"
#include "converters/im_to_am.cpp"
#include "converters/am_to_im.cpp"

adjacencyMatrix ALtoAM(adjacencyList in);
adjacencyList AMtoAL(adjacencyMatrix in);
adjacencyMatrix IMtoAM(incidencyMatrix in);
incidencyMatrix AMtoIM(adjacencyMatrix in);