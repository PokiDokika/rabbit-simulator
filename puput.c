#include <stdio.h>
#include <stdlib.h>

float dt = 0.08;    // Delta time (around a month)
float t = 0;        // Current time
float limit = 10;   // Time limit (years)

int food = 1000;
float population = 100;
float s = 2;    // s and k are variables that can be changed to affect the population growth
float k = 1;

int main(){
    printf("Enter a time limit (years):");
    scanf("%f", &limit);

    while(t<limit){

        // Food delta to make the population change a bit more interesting
        int foodDelta = (rand() % 50) - 25;
        if(food+foodDelta >= 0)
            food += foodDelta;

        float popFood = population/food;

        // Calculate population delta
        float dc = ((s-k)*population*(1-popFood))*dt;
        if(population + dc >= 0)
            population += dc;
            
        t += dt;
        
        // Print: currentTime : currentPopulation (foodAvailable) @ populationGrowth
        printf("%.2f : %.f (%i) @ %.2f\n",t,population,food,dc);
    }
}
