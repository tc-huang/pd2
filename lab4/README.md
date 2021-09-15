# lab4

## A.

Run `g++ -o lab4_a lab4_a.cpp` and `nm lab4_a` will get output like:
```
0000000100003f30 T __Z7averagePdRd
0000000100003f60 T __Z7averageif
0000000100000000 T __mh_execute_header
0000000100003f90 T _main
                 U dyld_stub_binder
```

The encoded identifiers used for the functions:
- double average()-> _Z7averagePdRd
- int average()-> _Z7averageif
- int main()-> main

## B.

Run `g++ -o lab4_a lab4_b.cpp` and `./lab4_b` will get output like:
```
1 8
4 8
4 8
8 8
```

These numbers represent the size of variables stored in
the memory.
char type variables using 1 byte  memory, int type and float using 4 byte,
and double type  using 8 bytes.
We saw the memory use by the all types of pointer(*) are 8 bytes.
That makes us conveniently and safely to point other variables, avoiding making overflow.
Last but not least, the result may vary from our compiler edition.