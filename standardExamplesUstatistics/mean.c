#include "U.h"
#include <gsl/gsl_matrix.h>

// the kernel of the U-statistics for the mean is just the identity function on a one-times-one-matrix
double kern(const gsl_matrix* data) {
	return gsl_matrix_get(data, 0, 0);
}

int main() {
	gsl_rng* r = gsl_rng_alloc(gsl_rng_taus2);
	gsl_rng_set(r, 1234);
	size_t B = 1e3;
	gsl_matrix* data = gsl_matrix_alloc(10, 1);
	gsl_matrix_set(data, 0, 0, 2.0);
	gsl_matrix_set(data, 1, 0, 2.0);
	gsl_matrix_set(data, 2, 0, 4.0);
	gsl_matrix_set(data, 3, 0, 6.0);
	gsl_matrix_set(data, 4, 0, 2.0);
	gsl_matrix_set(data, 5, 0, 6.0);
	gsl_matrix_set(data, 6, 0, 4.0);
	gsl_matrix_set(data, 7, 0, 5.0);
	gsl_matrix_set(data, 8, 0, 4.0);
	gsl_matrix_set(data, 9, 0, 6.0);
	double computationConfIntLower, computationConfIntUpper, thetaConfIntLower, thetaConfIntUpper;
	double estimatedMean = U(
		data, B, 1, r, kern, &computationConfIntLower, &computationConfIntUpper, &thetaConfIntLower, &thetaConfIntUpper);
	printf("U-statistic with confidence interval for its exact computation:\n[%f %f %f]\n", computationConfIntLower, estimatedMean, computationConfIntUpper);
	printf("U-statistic with confidence interval for the population value:\n[%f %f %f]\n", thetaConfIntLower, estimatedMean, thetaConfIntUpper);
}