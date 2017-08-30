import binary_c

def run_test_binary():
    m1 = 12.0
    m2 = 9.0
    eccentricity = 0.41
    metallicity = 0.02
    time = 33.895
    orbital_period = 13000.0

    output = binary_c.run_binary(m1, m2, orbital_period, eccentricity, metallicity, time)

    return output

print run_test_binary()
