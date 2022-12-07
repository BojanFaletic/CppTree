## CppTree

Like parse tree but in CPP.

Parsing large list with 10_000 entries. First test is with this parser
library second is with regular string comparison.

For large datasets parser outperform normal parsing.

Benchmark            |       Time      |       CPU   |Iterations
---                  | ---             | ---         | ---
Parse_parser         |    119 ns       |   119 ns    |  5470928
Parse_naive          |    7657 ns      |   7652 ns   |   100000
