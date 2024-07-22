#include <stdio.h>
#include <stdbool.h>
#include "mapping.h"
#include "management.h"

bool addPackage(struct Truck* truck, const struct Package package, const struct Map basemap){
    if (package.weight < 0 || package.volume < 0)
    {
        printf("Package weight and volume must be greater than 0. Package was not added.\n");
        return false;
    }
    // Check if the truck can accommodate the package based on weight and volume
    if (truck->currentWeight + package.weight > MAX_WEIGHT)
    {
        printf("Truck has reached its maximum weight. Package was not added.\n");
        return false;
    }

    if (truck->currentVolume + package.volume > MAX_VOLUME)
    {
        printf("Truck has reached its maximum volume. Package was not added.\n");
        return false;
    }

    // Check if package is the correct size
    if (package.volume != 1 && package.volume != 3 && package.volume != 5)
    {
        printf("Package must be 1 cubic meter, 3 cubic meters, or 5 cubic meters in size. Package was not added. \n");
        return false;
    }

    // Check if destination points are valid
    if (package.destination.row < 0 || package.destination.row >= basemap.numRows || package.destination.col < 0 || package.destination.col >= basemap.numCols)
    {
        printf("Invalid position (%d, %d). Please provide a valid position within the map bounds.\n", package.destination.row, package.destination.col);
        return false;
    }

    if (basemap.squares[package.destination.row][package.destination.col] != 1)
    {
        printf("Invalid position (%d, %d). Package cannot be delivered to this point. Please provide a valid position.\n", package.destination.row, package.destination.col);
        return false;
    }

    // Otherwise
    // Add the package to the truck
    truck->packages[truck->packageCount] = package;
    truck->packageCount++;

    // Update the truck's current weight and volume
    truck->currentWeight += package.weight;
    truck->currentVolume += package.volume;

    return true; 
}

//Check if the size of box is valid
int isValidBoxSize(int boxSize) {
    if (boxSize == 1 || boxSize == 3 || boxSize == 5) {
        return 1;
    }
    else {
        return 0;
    }
}


int findNearestTruck(struct Truck* trucks, int numTrucks, struct Package* package, const struct Map* map){}


bool isValidRoute(const struct Truck* truck, const struct Package* package) {
    for (int i = 0; i < MAX_ROUTE; i++) {
        if (truck->routes[i].numPoints == package->deliveryRoute.numPoints) {
            bool isSameRoute = true;

            for (int j = 0; j < truck->routes[i].numPoints; j++) {
                if (!eqPt(truck->routes[i].points[j], package->deliveryRoute.points[j])) {
                    isSameRoute = false;
                    break;
                }
            }
            if (isSameRoute) {
                return true;
            }
        }
    }
    return false;
}

