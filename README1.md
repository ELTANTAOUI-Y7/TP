# How It Works

## Compilation Targets for Each Exercise

Each target (`exo1`, `exo2`, etc.) compiles the corresponding `.cpp` file into an executable with the same name. For example:

- `exo1.cpp` is compiled into `exo1`
- `exo2.cpp` is compiled into `exo2`

## Running Individual Exercises

You can compile and run each exercise separately using `make`:

```sh
make exo1  # Compiles exo1.cpp into exo1
./exo1     # Runs the compiled executable

make exo2  # Compiles exo2.cpp into exo2
./exo2     # Runs the compiled executable
```

## Running All Exercises

To compile all exercises at once, use:

```sh
make all
```

This will generate executables for all exercises available in the directory.

## Example Usage

### Compile and Run Exercise 1

```sh
make exo1
./exo1
```

### Compile and Run Exercise 2

```sh
make exo2
./exo2
```

### Compile All Exercises

```sh
make all
```

This ensures that all `.cpp` files are compiled into their respective executables.


