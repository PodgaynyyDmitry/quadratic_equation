#include "quadratic_equation.h"

Solution solve_equation(double a, double b, double c) {
  Solution solution = {0};
  if(a==0 && b==0)
  {
    solution.x1 = solution.x2 = NAN;
  }
  else if(a==0)
  {
      solution.x1 = solution.x2 = -c /b;
  }
  else
  {
    double D = b * b - 4 * a * c;
    if (D < 0) {
        solution.x1 = solution.x2 = NAN;
    } 
    else if (D == 0) {
    solution.x1 = solution.x2 = -b / (2 * a);
    }
   else {
    solution.x1 = (-b + sqrt(D)) / (2 * a);
    solution.x2 = (-b - sqrt(D)) / (2 * a);
    }
  }

  return solution;
}