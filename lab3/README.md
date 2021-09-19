# lab3

## A.

run question A. by `g++ -o lab3_a.out lab3_a.cpp` and `./lab3_a`.

## B.

run question B. by `make` cmd.

The output result will be like:
```
size            sort()          insertion_sort() (time in second)
1000            4.8e-05         0.004003
10000           0.000535        0.317673
100000          0.005566        27.9564
```
Result explaination:

Take size=10^5 for example. If we use "Insertion Sort O(n^2)" to manage our 
vector, it needs 10^12 clocks to finish. Compared to this,"Sort() O(nlogn)"
roughly needs 10^7 clocks to complete. The number of clock of Insetion Sort
are 10^5 times bigger than the sort(). Therefore, no matter how powerful CPU 
deals with program, sort() certainly finish quicklier than the Insertion Sort.