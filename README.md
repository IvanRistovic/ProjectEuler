# ProjectEuler

## Description
My solutions for problems for [Project Euler](https://projecteuler.net/archives).

## Usage
- For Python script, no additional procedures needed. Just run it.
- For C code, compile the code as following:
```
gcc {problem}.c [-o {desired output name}] {LIBS}
```

  Where:
  - {problem} is the name of the source (ex. 0007\ -\ 10001st\ prime). Space has to be escaped.
  - [-o {desired output name}] is optional
  - {LIBS} are the libraries needed by the source.

  Please check source for detailed information on what libraries to use.

  Example:
  ```
  gcc 0007\ -\ 10001st\ prime.c -o prb0007 primes.c -lm
  ```
