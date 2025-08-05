#include "space_age.h"

float age(planet_t planet, int64_t seconds){
    
    switch (planet){
        case 0: 
            return (seconds / 0.2408467)/31557600;
            break;
        case 1: 
            return (seconds / 0.61519726)/31557600;
            break;
        case 2: 
            return seconds / 31557600;
            break;
        case 3: 
            return (seconds / 1.8808158)/31557600;
            break;
        case 4: 
            return (seconds / 11.862615)/31557600;
            break;
        case 5: 
            return (seconds / 29.447498)/31557600;
            break;
        case 6: 
            return (seconds / 84.016846)/31557600;
            break;
        case 7: 
            return (seconds / 164.79132)/31557600;
            break;
        default: return -1;
    }
}