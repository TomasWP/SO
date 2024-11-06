/**
 * @brief Simulation parameter values for Parking Management System.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <stdlib.h>

/**
 *  \brief maximum number of parking spaces
 */
#define MAX_PARKING_SPOTS 100

/**
 *  \brief maximum time (in microseconds) for a car to wait
 */
#define MAX_WAIT_TIME 1000000

/**
 *  \brief maximum license plate length
 */
#define MAX_LICENSE_PLATE 15

/**
 *  \brief invalid parking spot number
 */
#define INVALID_SPOT -1

/**
 *  \brief parking lot capacity check
 */
#define check_valid_parking_spot(spot) do { \
    if(spot < 0 || spot >= MAX_PARKING_SPOTS) { \
        printf("\e[31;01m[%s, line %d, function %s] ERROR: invalid parking spot %d!\e[0m\n", \
               __FILE__, __LINE__, __FUNCTION__, spot); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

/**
 *  \brief license plate verification test
 */
#define check_valid_license_plate(plate) do { \
    if(plate[0] == '\0' || strlen(plate) > MAX_LICENSE_PLATE) { \
        printf("\e[31;01m[%s, line %d, function %s] ERROR: invalid license plate \"%s\"!\e[0m\n", \
               __FILE__, __LINE__, __FUNCTION__, plate); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

/**
 *  \brief parking lot full check
 */
#define check_parking_full(count) do { \
    if(count >= MAX_PARKING_SPOTS) { \
        printf("\e[31;01m[%s, line %d, function %s] ERROR: parking lot is full!\e[0m\n", \
               __FILE__, __LINE__, __FUNCTION__); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

#endif // SETTINGS_H

