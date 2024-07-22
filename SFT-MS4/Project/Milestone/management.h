#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "mapping.h"
#include <stdbool.h>


#define MAX_WEIGHT 2500
#define MAX_VOLUME 100

struct Package
{
	float weight;
	float volume;
	struct Point destination;
	struct Route deliveryRoute;
};

struct Truck
{
	char truckID[20];							
	float currentWeight;		
	float currentVolume;		
	struct Package packages[MAX_VOLUME];
	int packageCount;
	struct Route routes[MAX_ROUTE];
};

/**
 * Function: addPackage
 * - Attempts to add a package (Package struct) to a truck's load (Truck struct).
 * - Returns true if the add operation was successful, indicating that the package was loaded onto the truck.
 * - Returns false if the operation fails for any reason (e.g., truck capacity exceeded).
 *
 * @param truck - Pointer to the Truck struct containing information and current status of the truck.
 * @param package - Constant Package struct containing information about the package.
 * @param basemap -  Constant Map struct containing the position of all buildings
 * @returns - Boolean, true if the package was successfully added to the truck, false otherwise.
 */
bool addPackage(struct Truck* truck, const struct Package package, const struct Map basemap);

/**
 * Function: isValidBoxSize
 * - Checks whether the given box size is valid.
 * - Valid sizes are 1, 3, or 5 cubic meters.
 * - Returns 1 if the box size is one of the valid values.
 * - Returns 0 if the box size is not valid.
 *
 * @param boxSize - An integer representing the size of the box in cubic meters.
 * @returns - An integer value, 1 if the box size is valid, 0 if the size is not valid.
 * Unusual Conditions: If the box size is not 1, 3, or 5, the function returns 0.
 */
int isValidBoxSize(int boxSize);

/**
 * Function: findNearestTruck
 * - Finds the closest available truck that has space for the package.
 * - Checks that weight, size, and destination are valid.
 * - Returns the index of the closest truck or -1 if no truck is found.
 *
 * @param trucks - Pointer to an array of struct Truck, representing the trucks for delivery.
 * @param numTrucks - Integer, representing the number of trucks in the array.
 * @param package - Pointer to struct Package, representing the package(s) to be delivered.
 * @param map - Pointer to struct Map, representing the map with location of buildings and routes.
 * @returns - An integer value, the index of the closest truck or -1 if no truck is found.
 */
int findNearestTruck(struct Truck* trucks, int numTrucks, struct Package* package, const struct Map* map);

/**
 * Function: isValidRoute
 * - Checks if the delivery route of the package is valid based on the routes available in the truck.
 * - Returns true if the route is valid, false otherwise.
 *
 * @param truck - Pointer to struct Truck, representing the truck to check against.
 * @param package - Pointer to struct Package, representing the package being delivered.
 * @returns - Boolean value, true if the route is valid, false otherwise.
 */
bool isValidRoute(const struct Truck* truck, const struct Package* package);



#endif