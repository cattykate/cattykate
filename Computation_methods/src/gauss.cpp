#include <iostream>
#include <cmath>

int main() {
	const unsigned int n = 4;

	double matrix[n][n+1] = {
		{-2, -9, -3, 7, -26 },
		{-7, 2, 2, 5, -25 },
		{-6, 2, 0, 0, -16 },
		{0, -3, 8, -3, 5}
	};

	double max = 0;
	int ind_max = 0;
	double tmp = 0;
	double x = 0;

	///// finding max elem

	for (int i = 0; i < n; i++) {
		for (int m = i; m < n; m++) {
			if ((abs(matrix[m][i])) > max)
			{
				ind_max = m;
				max = abs(matrix[m][i]);
			}
		}
		max = 0.0;

		if (ind_max != i)
		{
			for (int j = i; j < n + 1; j++)
			{
				tmp = matrix[ind_max][j];
				matrix[ind_max][j] = matrix[i][j];
				matrix[i][j] = tmp;
			}
		}

		// finding multipliers
		x = matrix[i][i];
		for (int j = n; j >= i; j--) {
			matrix[i][j] = matrix[i][j] / x;
		}
		for (int j = i + 1; j < n; j++) {
			x = matrix[j][i];
			for (int p = n; p >= i; p--) {
				matrix[j][p] = matrix[j][p] - x*matrix[i][p];
			}
		}
	}

	return 0;
}

