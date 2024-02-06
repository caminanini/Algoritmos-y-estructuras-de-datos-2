#ifndef _WEATHER_UTILS_H 
#define _WEATHER_UTILS_H 

#include <limits.h> 
#include "array_helpers.h"
#include "weather.h"

int historical_minimum(WeatherTable tabla_a);

void max_for_year(WeatherTable tabla_b,int res[]);

void month_rainfall(WeatherTable tabla_c,int res_month[]);

#endif 