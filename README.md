# 🔐 RSAbrk – Prime Factorization of Semiprimes

RSAbrk is a C program for factoring semiprime numbers, i.e., numbers formed by the product of two large prime numbers (P and Q). It was created for fun and exploration of number theory, and features two different implementations: `RSAbrk_v1` and `RSAbrk_v2`.

---

## 🚀 About

You enter a number `PQ` (assumed to be the product of two primes), and the program attempts to recover `P` and `Q`.

- ✅ **Version 2** (`RSAbrk_v2`) factors `PQ = 124520438789` into `P = 128819` and `Q = 966631` in **~17 seconds**.
- ❌ **Version 1** (`RSAbrk_v1`) takes **13+ minutes** and might still return **"no factors found"**, likely due to precision limitations and inefficiencies in the approach.

> _“I enjoyed playing with math to come up with this!” — Justus_

---

## 🧠 Files Overview

- `MRSAbrk.c`: Main program entry, asks for user input and prints factor results.
- `RSAbrk.h`: Function prototype for the factorization logic.
- `RSAbrk_v1.c`: First (slow) algorithm version using mathematical functions and trigonometric exploration.
- `RSAbrk_v2.c`: Optimized and more effective second version, refined based on insights from v1.

---

## 🧪 Example

### Input:
```sh
$ ./MRSAbrk
Entrez pq:
124520438789
````

### Output (using v2):

```
pq= 124520438789!
n=..., tmp_q=..., ...
124520438789=128819*966631
```

---

## ⚙️ Compilation

To compile with either version, change which `.c` file you link:

### For RSAbrk\_v2:

```sh
gcc MRSAbrk.c RSAbrk_v2.c -o RSAbrk -lm
```

### For RSAbrk\_v1:

```sh
gcc MRSAbrk.c RSAbrk_v1.c -o RSAbrk -lm
```

The `-lm` flag links the math library, which is required for `sqrt`, `log10l`, etc.

---

## 📚 Theory

* Uses mathematical transformations and square root approximations to derive possible factors.
* Includes exploratory techniques like applying trigonometric and exponential functions in `v1`.
* `v2` optimizes the search by bounding the number of iterations using estimates based on the square root of `PQ`.

---

## 💡 Tips

* For large `PQ` values, use `v2` to avoid long runtimes.
* Adjust the precision (`m`) and iteration ranges if you plan to extend the algorithm to much larger keys.
* This is not suitable for cryptographic-grade RSA keys, but is perfect for educational exploration.

---

## 📜 License

This project is licensed under the **Creative Commons Attribution 4.0 International License**.

---
