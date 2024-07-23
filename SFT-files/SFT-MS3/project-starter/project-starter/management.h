#pragma once
#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "mapping.h"

struct Truck
{
	char id[20];				
	float maxWeight;			
	float maxVolume;			
	float currentWeight;		
	float currentVolume;		
	Package packages[100];		 
	int packageCount;			
};
	
struct Package
{
	float weight;			
	float volume;				
	Point destination;			
};

struct System
{
	Route routes[MAX_ROUTE];	
	int routeCount;				
	Truck trucks[MAX_TRUCK];	
	int truckCount;				
};

#endif