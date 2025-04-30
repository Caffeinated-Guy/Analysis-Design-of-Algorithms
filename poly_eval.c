/* This program is used to evaluate a polynomial at multiple points using Polynomial Evaluation – 
Evaluate a polynomial of degree N at multiple points using Horner’s rule. 
By Team: Adarsh Devadiga (4MW23CS002), Adarsh Acharya (4MW23CS003), Ashish prasad (4MW23CS018), Kunal Kamalaksha Prabhu (4MW23CS060) */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>  /*OpenMP header(Open Multi-Processing) is an API that supports multi-platform shared-memory multiprocessing programming in C and C++ */ 

/* This function is used to evaluate a polynomial at a single point using Horner's rule*/ 
double horner_evaluate(double *coeffs, int degree, double x) {
    double result = coeffs[degree];
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + coeffs[i];
    }
    return result;
}

int main() {
    int degree = 5;   // Degree of the polynomial
    int num_points;   // Number of x points to evaluate (user should input)

    /* Asks user to enter number of points*/ 
    printf("Enter the number of points to evaluate: (50^5<=''input''<10^9 ): ");
    scanf("%d", &num_points);
    if(num_points < 500000){
        printf("Input Too low Parallelization doesn't make sense for low input !!! (50^5 <= input < 10^9 ) \n");
        exit(0);// parallelization dosn't make sense for number of points less than 10^5
    }else if(num_points > 999999999){
        printf("Input to big INT_OVERFLOW (50^5 <= input < 10^9 )!! \n");
        exit(0);
    } 
    /* Allocate memory dynamically*/ 
    double *coeffs = (double *)malloc((degree + 1) * sizeof(double)); 
    double *x_values = (double *)malloc(num_points * sizeof(double));
    double *results_serial = (double *)malloc(num_points * sizeof(double));
    double *results_parallel = (double *)malloc(num_points * sizeof(double));

    /* Initialize random coefficients*/ 
    srand(time(NULL));
    for (int i = 0; i <= degree; i++) {
        coeffs[i] = (double)(rand() % 10); // Coefficients between 0-9
    }

    /* Initialize random x values*/ 
    for (int i = 0; i < num_points; i++) {
        x_values[i] = (double)(rand() % 100) / 10.0; // x between 0.0 and 10.0
    }

    /* ------------- Serial Version -------------*/ 
    clock_t start_serial = clock(); // Start timer (series)

    for (int i = 0; i < num_points; i++) {
        results_serial[i] = horner_evaluate(coeffs, degree, x_values[i]);
    }

    clock_t end_serial = clock(); // End timer (series)
    double time_serial = (double)(end_serial - start_serial) / CLOCKS_PER_SEC;

    /* ------------- Parallel Version -------------*/ 
    clock_t start_parallel = clock(); // Start timer (parallel)

    #pragma omp parallel for    //to parallelise the loop automatically
    for (int i = 0; i < num_points; i++) {
        results_parallel[i] = horner_evaluate(coeffs, degree, x_values[i]);
    }

    clock_t end_parallel = clock(); // End timer (parallel)
    double time_parallel = (double)(end_parallel - start_parallel) / CLOCKS_PER_SEC;

    /* ------------- Verify results ------------- to ensure parallelization didn't cause errors.*/ 
    int correct = 1;
    for (int i = 0; i < num_points; i++) {
        if (abs(results_serial[i] - results_parallel[i]) > 1e-6) {
            correct = 0;
            break;
        }
    }

    if (correct)
        printf("\nResults Match!\n");
    else
        printf("\nResults DO NOT Match!\n");

    /*------------- Display timings ------------- */ 
    printf("\nSerial Execution Time (Without OpenMP)  = %.6f seconds\n", time_serial);
    printf("Parallel Execution Time (With OpenMP) = %.6f seconds\n", time_parallel);

    /* Free dynamically allocated memory*/ 
    free(coeffs);
    free(x_values);
    free(results_serial);
    free(results_parallel);

    return 0;
}

/* To run the program: gcc -fopenmp poly_eval.c -o poly_eval   &&   ./poly_eval */