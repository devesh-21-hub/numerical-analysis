/**
 * @file Bisection.cpp
 * @author Devesh Kumar (devesh-21hub)
 * @brief C++ Program to implement Bisection Method.
 * @version 0.1
 * @date 2022-01-15
 *
 */

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Defining equation to be solved
#define f(x) cos(x) - x *exp(x)

// Declaring required variables
float x0, x1, x, f0, f1, f, e;
int step = 1;

void takeInput()
{

    cout << "Enter first guess, second guess, and tolerable error: \n";
    cin >> x0 >> x1 >> e;
    return;
}

int main()
{

    cout << setprecision(6) << fixed;
    takeInput();

    // Calculating Functional Value
    f0 = f(x0);
    f1 = f(x1);

    // Checking whether given guesses brackets the root or not.
    if (f0 * f1 > 0.0)
    {
        cout << "Incorrect Initial Guesses."
             << "\n";
        main();
    }
    // Implementing Bisection Method

    cout << "Implementing Bisection Method"
         << "\n";

    do
    {
        // Bisecting Interval
        x = (x0 + x1) / 2;
        f = f(x);

        cout << "Iteration-" << step << ":\t x = " << setw(10) << x << " and f(x) = " << setw(10) << f(x) << "\n";

        if (f0 * f < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        step = step + 1;
    } while (fabs(f) > e);

    cout << "\n"
         << "Root is: " << x << "\n";

    return 0;
}