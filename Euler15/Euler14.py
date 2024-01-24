def calculate_factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * calculate_factorial(n - 1)

def calculate_routes(n, k):
    return calculate_factorial(n) // (calculate_factorial(k) * calculate_factorial(n - k))

grid_size = 20
routes = calculate_routes(2 * grid_size, grid_size)

print(f"Number of routes in a {grid_size}x{grid_size} grid: {routes}")
