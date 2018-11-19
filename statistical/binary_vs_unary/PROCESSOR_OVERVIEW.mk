# What is faster n++ or n = n + 1?
It will depend on following factors:

- Processor Architecture
- C/C++ Compiler
- Usage in your code
- Other factors and hardware problems
- Processor Architecture

## Processor Architecture
Processor architecture means for me processors have different instruction sets for now. We have two architecture families: CISC and RISC processors. Some chips does not need to have instructions for addition or incrementation. Generally, additional instructions are slower than incremental, if both are supported, but this is very poor answer.

CISC architectures have more complex instructions to “build” more steps together in algorithms. So, incrementation or addition can be only (and usually is) part of another instruction which is doing more complex operation in algorithm.

Next problem is some instructions are also modifying flag registers or other registers in processor. Sometimes, it is needed to bake up or clean up the flag register or another registers in your algorithms. You need to count also time of cleaning up after your instructions.

For example: What is faster on Intel?

```
n = n * 7;
n = n << 3 - n;
```

Multiplying instruction MUL will be probably slower on Intel than shifting bits and subtraction. But, second row needs one more free register in your Intel processor. You should also count time for instructions such as push and pop for bake up of your register, if it is not free. If you will write poor loop for test, you do not need to bake up the register, so information abut translation of poor loop by gcc could be misleading at the end.

## C/C++ Compiler

It is important how compiler will understand your code and how he will translate it into instructions. Sometimes, the compiler have more options how to translate your C/C++ code into instructions, especially on CISC architectures.

The rows:

```
n = n + 1;
n++;
```

If I isolate the problem only on two above rows, smart compilers supposed to understand what you need to calculate and they will translate both rows by the same way. No discussion about it. If your compiler will be not translating it by the same way, either the compiler is not smart, or you forced him not to be smart.

## Usage in your code

The problem is still not 100% properly answered, because you cannot isolate instructions in your translation for processor. Intel processors have pipes. It means, the same instruction will take another time on one place in your code and another time in another place in your code. I wanna say that time of executing of instruction will depend also on couple instructions before and after your instruction. Poor tests with only loops do not work 100 percent for me.

## Other factors and hardware problems

Time of execution of instruction will depend also on another factors, what compiler does not need to know in translation time. But these factors could be also considered in translation.

For example, the chips could be overheated by some instructions and then processor will slow down to protect himself. At the end, faster execution will be slower, because system could temporary decrease frequency of your processor. Some instructions are not thread safe, virtual memory safe etc. It means, instruction could be faster in ideal situation, but not in real situations.

## Final Answer

*Smart compiler will translate your code by the same way.* Any keywords or switches (e.g inline) forcing to compiler to do something due to your speed ideas could have negative impact on speed of your algorithm at the end.

Instructions for addition are usually slower than instructions for incrementation, but you cannot say it generally for all processors and all situations.