# Miniprocessor

## Task 1: Basic Bit Manipulation and Operator Parsing
This module implements keyboard input processing to extract binary-encoded expressions:
- Reads binary input and determines the value n through bit shifting operations
- Extracts the last significant bits and applies increment operations as specified
- Identifies operator bit patterns and maps them to their corresponding arithmetic operations (4 distinct operator types)
- Calculates the required bit shifts to determine operand sizes
- Outputs the parsed value of n and identified operators

## Task 2: Fixed-Size Operand Expression Evaluation
Extends Task 1 functionality with vector-based storage and expression evaluation:
- Stores identified operators in a dedicated vector structure
- Processes operands with power-of-2 bit sizes according to specification requirements
- Maintains operand values in a structured vector for sequential processing
- Initializes expression evaluation with the first operand value
- Iteratively applies operators to subsequent operands in sequence
- Returns the final computed expression result

## Task 3: Variable-Size Operand Processing
Advanced implementation supporting arbitrary operand bit lengths:
- Handles operands with non-power-of-2 sizes that may span multiple input reads
- Implements two-case bit processing logic:
  - **Case 1**: Sufficient bits available for complete operand grouping
  - **Case 2**: Requires additional bits from subsequent reads for operand completion
- Manages bit remainder handling through left-shifting operations to accommodate new input bits
- Utilizes iterative grouping algorithms with conditional processing loops
- Maintains bit usage tracking throughout the parsing process

## Task 4: Operator Precedence Expression Evaluation
Comprehensive expression evaluator with mathematical operator precedence:
- Inherits core functionality from Task 3 with enhanced precedence handling
- Implements separate result and operator vector storage systems
- Processes multiplication and division operations with immediate evaluation
- Defers addition and subtraction operations for final precedence-correct evaluation
- Executes two-phase evaluation:
  - High-precedence operations (multiplication/division) during parsing
  - Low-precedence operations (addition/subtraction) in final traversal
- Outputs precedence-compliant expression results
