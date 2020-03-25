# Common Design Patterns in C++

## List:
 - Pimpl(Pointer Implementation)
 - Singleton
 - ...

## How to document C++ code:

**Template**:
```C++
/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
double sum(std::vector<double> & const values) {
    ...
}
```

**Reference**: [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html)
