#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int length;
    int delay;
} FlightData;

int compare(const void *a, const void *b) {
    FlightData *flightA = (FlightData *)a;
    FlightData *flightB = (FlightData *)b;
    return flightA->length - flightB->length;
}

int main() {
    FILE *inputFile = fopen("Airlines.csv", "r");
    FILE *outputFile = fopen("filtered_flights.csv", "w");
    if (!inputFile || !outputFile) {
        return 1;
    }

    char line[256];
    size_t capacity = 1000;
    size_t count = 0;
    FlightData *flights = malloc(capacity * sizeof(FlightData));

    if (flights == NULL) {
        return 1;
    }

    fgets(line, sizeof(line), inputFile);

    while (fgets(line, sizeof(line), inputFile)) {
        if (count >= capacity) {
            capacity *= 2;
            flights = realloc(flights, capacity * sizeof(FlightData));
            if (flights == NULL) {
                return 1;
            }
        }

        FlightData flight;
        char *token = strtok(line, ",");
        int column = 0;

        while (token) {
            switch (column) {
                case 7: 
                    flight.length = atoi(token);
                    break;
                case 8: 
                    flight.delay = atoi(token);
                    break;
            }
            token = strtok(NULL, ",");
            column++;
        }
        flights[count++] = flight;
    }

    qsort(flights, count, sizeof(FlightData), compare);

    fprintf(outputFile, "Length,Delay\n");
    for (size_t i = 0; i < count; i++) {
        fprintf(outputFile, "%d,%d\n", flights[i].length, flights[i].delay);
    }

    free(flights);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
