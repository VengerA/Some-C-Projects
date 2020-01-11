#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int addMovingtime(int totalDistance, int carDistance, int carSeconds, int footSeconds, int repairTime, int NeededToRepair){
    if(NeededToRepair){
        if(totalDistance >= carDistance){
            if(carDistance * carSeconds + repairTime >= carDistance * footSeconds){
                return totalDistance * footSeconds;
            }
            else if(carDistance * carSeconds + repairTime < totalDistance * footSeconds){
                return carSeconds * carDistance + repairTime + addMovingtime(totalDistance - carDistance, carDistance, carSeconds, footSeconds, repairTime, 1);
            }
        }
        else{
            if(totalDistance * carSeconds + repairTime >= totalDistance * footSeconds){
                return totalDistance * footSeconds;
            }
            else{
                return totalDistance * carSeconds + repairTime;
            }
        }
    }else{
        if(carDistance >= totalDistance){
            return totalDistance * carSeconds;
        }
        else{
            
            return carDistance * carSeconds + addMovingtime(totalDistance - carDistance, carDistance, carSeconds, footSeconds, repairTime, 1);
        }
    }
    return 0;
}

int main() {
    int d, k, a, b, t, c;
    scanf("%d %d %d %d %d", &d, &k, &a, &b, &t);
    
    c = addMovingtime(d, k, a, b, t, 0);
    
    printf("%d", c);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

