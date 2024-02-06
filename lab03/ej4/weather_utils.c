#include <stdlib.h>
#include <stdio.h>
#include "weather_utils.h"
#include "array_helpers.h"
#include "weather.h"

int historical_minimum(WeatherTable a) {
    int r=INT_MAX;
    for (unsigned int i = 0; i < YEARS; i++) {
        for (unsigned int j = 0; j < MONTHS; j++) {
            for (unsigned int k = 0; k < DAYS; k++) {
                if (a[i][j][k]._min_temp < r) {
                    r = a[i][j][k]._min_temp;
                }
            }
        }
    }
    return r;
}

void max_for_year(WeatherTable a,int res[]){
    for (unsigned int i = 0; i < YEARS; i++) {
        int m=INT_MIN;
        for (unsigned int j = 0; j < MONTHS; j++) {
            for (unsigned int k = 0; k < DAYS; k++) {
                if (a[i][j][k]._max_temp > m) {
                    m = a[i][j][k]._max_temp;
                }
            }
        }
        res[i]=m;
    }
}

void month_rainfall(WeatherTable a,int res_month[]){
unsigned int max_mes,maxprec,prec;
    for (unsigned int i = 0; i < YEARS; i++) {
        max_mes=0;
        maxprec=0;
        for (unsigned int j = 0; j < MONTHS; j++) {
            prec=0;
            for (unsigned int k = 0; k < DAYS; k++) {
                prec=prec+a[i][j][k]._rainfall;
            }
              if(prec>maxprec){
                maxprec=prec;
                max_mes=j;
                }
        }
        res_month[i]=max_mes;
    }
}
