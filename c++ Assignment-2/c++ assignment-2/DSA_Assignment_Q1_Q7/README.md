# C++ DSA Assignment Q1–Q7

Student: S. Lavanya  
Register Number: 192411113  
Institution: SIMATS

## Contents
- `cpp_source/`: independently compilable C++17 programs for Q1–Q7, including Q6 benchmark and Q7 redesign.
- `execution_screenshots/`: terminal-style captures of actual program output.
- `SIMATS_Cpp_DSA_Assignment_Q1_Q7_Lavanya.docx`: complete assignment report.

## Compile and run
For each `.cpp` file:
```bash
g++ -std=c++17 -O2 -Wall -Wextra filename.cpp -o program
./program
```
For the Q6 timing comparison, compile `Q6_inline_timing.cpp` separately with `-O0` and `-O2`.

## Notes
- `Q2_dangling_warning_only.cpp` is intentionally unsafe and must not be executed to dereference its returned reference. It exists only to produce compiler-warning evidence.
- Timing values vary by computer and compiler.
- Add your GitHub repository URL to the report cover page after uploading this folder.
