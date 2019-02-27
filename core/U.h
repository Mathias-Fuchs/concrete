#pragma once

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_rng.h>

double U(
	const gsl_matrix * data,
	const size_t B,
	const int m,
	gsl_rng * r,
	double(*kernel)(const gsl_matrix *),
	double* confIntLower,
	double* confIntUpper,
	double* Usquared,
	double* UsquaredLower,
	double* UsquaredUpper);
