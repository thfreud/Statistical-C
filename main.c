#include <stdio.h>

//defining de number of data points in the vector
#define SIZE 12

void sort(double array[]);

void median(double array[]);

void mean(const double array[]);

void mode(double array[]);

void printArray(double array[]);

int main() {
    //the vector with values to use.
    double array[SIZE] = { 1, 2.5, 2.5, 4, 5, 5, 7, 8, 10, 10,12,12 };

    //print data on the screen
    printArray(array);

    //Reckoning statistical basic measures.
    median(array);
    mean(array);
    mode(array);

    return 0;
}

//function used to sorting data points.
void sort(double array[]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE - 1; ++j) {
            double hold = 0;
            if (array[j] > array[j + 1]) {
                hold = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold;
            }
        }
    }
}

//function that calculates median value
void median(double array[]) {
    sort(array);
    const double answer = (SIZE % 2 == 0)
                          ? (((double)array[SIZE / 2] + (double)array[SIZE / 2 + -1]) * 0.5)
                          : array[SIZE / 2];
    printf("\n************************************");
    printf("\nThe median value is: %.4f", answer);
    printf("\n************************************");
}

//function that calculates mean value
void mean(const double array[]) {
    double sum = 0;
    for (unsigned int i = 0; i < SIZE; ++i) {
        sum += array[i];
    }
    printf("\n************************************");
    printf("\nThe mean value is: %.2f\n", sum / SIZE);
    printf("\n************************************");
}

//function that calculates modal value
void mode(double array[]) {
    sort(array);

    double h[SIZE + 1][2];

    int l = 0;

    for (int k = 0; k < SIZE; ++k)
    {
        if (array[k + 1] != array[k])
        {
            h[l][0] = array[k];
            h[l][1] = 0;

            ++l;
        }
    }
    //filling last value of h.
    h[l][0] = '\0';


    //finding modal value
    for (unsigned int k = 0; k < SIZE; ++k) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            if (h[k][0] == array[j]) {
                ++h[k][1];
            }
        }
    }
    printf("\n----------------------------------");
    printf("\nNumber\t Frequency");
    printf("\n----------------------------------");
    int i = 0;
    while (h[i][0] != '\0') {

        printf("\n%.2f\t %.0f", h[i][0], h[i][1]);
        ++i;
    }



    double maxFrequency = 0;
    for (unsigned int i1 = 0; i1 < SIZE; ++i1) {
        if (h[i1][1] > maxFrequency) {
            maxFrequency = h[i1][1];
        }
    }

    //looking for more then one modal value

    int count = 0;
    for (int j = 0; j<SIZE;++j)
    {
        if (maxFrequency==h[j][1])
        {
            ++count;
        }
    }
    printf("\n----------------------------------");
    printf("\n There is %d modal value(s)", count);


    //finding the modal value
    printf("\n************************************");
    for (unsigned int i1 = 0; i1 < SIZE; ++i1) {
        if (h[i1][1] == maxFrequency) {
            printf("\n The modal value is : %.2f", h[i1][0]);

        }

    }
    printf("\n************************************");

}

void printArray(double array[])
{
    sort(array);
    for (unsigned int i = 0; i< SIZE; ++i)
    {
        if (i%10==0)
        {
            puts("");
        }

        printf("%.2f\t", array[i]);
    }
}



