
#ifndef WORKSHOP3_H
#define WORKSHOP3_H

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_STRING_LEN 30
#define MAX_PROV_LEN 3
#define MAX_POSTAL 10 //A0A 0A0

struct Customer {
    char firstName[MAX_STRING_LEN];
    char lastName[MAX_STRING_LEN];
    char address[MAX_STRING_LEN];
    char city[MAX_STRING_LEN];
    char province[MAX_STRING_LEN];
    char postalCode[MAX_POSTAL];
};

// Function prototypes
void checkInput(char* prompt, char* input, size_t length);
int checkAddress(char* input);
int checkPostalCode(char* input);
struct Customer inputCustomerInfo();

#endif
