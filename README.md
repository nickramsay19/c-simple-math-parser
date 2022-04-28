# Basic Arithmetic Parser | c-simple-math-parser
Performs a recursive descent parse of a basic mathematical statement. This parser does not produce a parsing tree, rather it showcases a minimal parser for a minimal grammar.

| Syntax      | Description |
| ----------- | ----------- |
| Header      | Title       |
| Paragraph   | Text        |

## Basic arithmetic grammar (left-recursion removed)
| Non-Terminal      | &#8594; | Derivation                    |
| ----------------- | ------- | ----------------------------- |
| STATEMENT         | &#8594; | EXPRESSION + "$"              |
| EXPRESSION        | &#8594; | TERM + FACTOR_OPERATION       |
| FACTOR_OPERATION  | &#8594; | "+" + TERM + FACTOR_OPERATION |
|                   | &#8594; | "-" + TERM + FACTOR_OPERATION |
|                   | &#8594; | &epsi;                        |
| TERM              | &#8594; | FACTOR + TERM_OPERATION       |
| FACTOR            | &#8594; | "(" + EXPRESSION + ")"        |
|                   | &#8594; | INTEGER                       |


| INTEGER           | &#8594; | (0|1|2|...|9)+                |


## Usage
```
make
.dist/main <statement>
```
Where statement doesn't have any whitespace.
