#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "management.h"

int main(void)
{
	struct Map baseMap = populateMap(); //return a struct Map, map has 0 and 1 (yes/no buildings)
	struct Route blueRoute = getBlueRoute(); //return struct Route, collection of points, the number of points, and a colour
	struct Map routeMap = addRoute(&baseMap, &blueRoute);// return a struct map, 

	printMap(&routeMap, 0, 0);

	struct Point start = { 0, 0 };
	struct Point last = { 12, 6 };
	struct Route route1 = shortestPath(&routeMap, start, last);
	printf("\n");
	for (int i = 0; i < route1.numPoints; i++)
	{
		
		printf("{%d,%d},",route1.points[i].row, route1.points[i].col);
		
	}
	printf("\n");

	return 0;
}