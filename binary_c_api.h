//#include "../../code/binary_c/src/API/binary_c_API.h"
#include "../src/API/binary_c_API.h"

/* local function prototypes */
static double randd(double min, double max);
static void APIprintf(char * format,...);

static void set_srand(void);
static size_t getTotalSystemMemory(void);

int run_binary ( double m1, double m2, double orbital_period, double eccentricity, double metallicity, double maxt,
                 double* m1_out, double* m2_out, double* orbital_separation_out,
                 double* eccentricity_out, int* ktype_1, int* ktype_2);

int run_binaries ( double m1, double m2, double orbital_period, double eccentricity, double metallicity, double maxt );

/* C macros */
#define BINARY_C_APITEST_VERSION 0.1
#define APIprint(...) APIprintf(__VA_ARGS__);
#define NO_OUTPUT
