#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
//#include <sys/resource.h>
#include <unistd.h>

#define TESTS 100
static int x;

volatile int a = 0;
volatile uint64_t i = 0;
volatile uint64_t j = 0;

//int unaryRegister(int i) {
//    i++;
//    return i;
//}

//int binaryRegister(int i) {
//    i = i + 1;
//    return i;
//}

//int unaryMemory(int i) {
//    x++;
//    return i;
//}

//int binaryMemory(int i) {
//    x = x + 1;
//    return i;
//}

//double sum = 0;
//unsigned int samples = 0;
//void nullStatData() {
//    sum = 0;
//    samples = 0;
//}

//void processStatData(double item) {
//    sum += item;
//    samples++;
//}

//void printStatData() {
//    fprintf(stdout, "\nStatistics: ");
//    fprintf(stdout, "colected samples: %d", samples);
//    fprintf(stdout, ", arithmetical average: %lf\n", sum / samples);
//}


//int main(){
//    // we will eliminate mistake in measurements:
//    // - setting priority for ptocces to high
//    // - giving system time to change priority level
//    // - launching first loop without measurement
//    // - not writting anything into console
//    // - launching measured functions in 100.0000.000 cycles
//    // - measuring loop time to make sure results are comarable
//    // - comparing results "per partes", not all of them together
//    // mistake in measurement will be:
//    // - writting results into memory
//    // - calling system function gettimeofday between tests
//    // - wrong location of funtion unary and binary in compiled code, I hope this will not happen
//    // - comaring float variables with the same time value could be miseading
//    // - so, we will launch 500 tests to get strong reults

////    setpriority(PRIO_PROCESS, getpid(), -20);

//    struct timeval start, end, startAll, endAll;
//    double fUnaryRegister[TESTS], fUnaryMemory[TESTS], fBinaryRegister[TESTS], fBinaryMemory[TESTS], fLoop[TESTS];
//    unsigned int test;

//    fprintf(stdout, "---------------- Start of %d tests\n", TESTS);
//    gettimeofday(&startAll, NULL);
//    sleep(1);

//    for(i = 0; i < 100; i++){
//        for (j = 0; j < 1000000; j++){
//            a = unaryRegister(a);
//        }
//    }
//    for(i = 0; i < 100; i++){
//        for (j = 0; j < 1000000; j++){
//            a = binaryRegister(a);
//        }
//    }


//    for (test = 0; test < TESTS; test++) {
//        gettimeofday(&start, NULL);
//        for(i = 0; i < 100; i++){
//            for (j = 0; j < 1000000; j++){
//                a = unaryRegister(a);
//            }
//        }
//        gettimeofday(&end, NULL);
//        fUnaryRegister[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

//        gettimeofday(&start, NULL);
//        for(i = 0; i < 100; i++){
//            for (j = 0; j < 1000000; j++){
//                a = binaryRegister(a);
//            }
//        }
//        gettimeofday(&end, NULL);
//        fBinaryRegister[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

//        gettimeofday(&start, NULL);
//        for(i = 0; i < 100; i++){
//            for (j = 0; j < 1000000; j++){
//                a = unaryMemory(a);
//            }
//        }
//        gettimeofday(&end, NULL);
//        fUnaryMemory[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

//        gettimeofday(&start, NULL);
//        for(i = 0; i < 100; i++){
//            for (j = 0; j < 1000000; j++){
//                a = binaryMemory(a);
//            }
//        }
//        gettimeofday(&end, NULL);
//        fBinaryMemory[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

//        gettimeofday(&start, NULL);
//        for(i = 0; i < 100; i++){
//            for (j = 0; j < 1000000; j++){
//            }
//        }
//        gettimeofday(&end, NULL);
//        fLoop[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
//    }

//    gettimeofday(&endAll, NULL);
//    fprintf(stdout, "---------------- Measured data\n");

//    nullStatData();
//    fprintf(stdout, "\rUnary via register: \n");
//    for(test = 0; test < TESTS; test++) {
//        fprintf(stdout, "%lf ", fUnaryRegister[test]);
//        processStatData(fUnaryRegister[test]);
//    }
//    printStatData();

//    nullStatData();
//    fprintf(stdout, "\rBinary via register: \n");
//    for(test = 0; test < TESTS; test++) {
//        fprintf(stdout, "%lf ", fBinaryRegister[test]);
//        processStatData(fBinaryRegister[test]);
//    }
//    printStatData();

//    nullStatData();
//    fprintf(stdout, "\rUnary via memory: \n");
//    for(test = 0; test < TESTS; test++) {
//        fprintf(stdout, "%lf ", fUnaryMemory[test]);
//        processStatData(fUnaryMemory[test]);
//    }
//    printStatData();

//    nullStatData();
//    fprintf(stdout, "\rBinary via memory: \n");
//    for(test = 0; test < TESTS; test++) {
//        fprintf(stdout, "%lf ", fBinaryMemory[test]);
//        processStatData(fBinaryMemory[test]);
//    }
//    printStatData();

//    fprintf(stdout, "\rLoop: \n");
//    nullStatData();
//    for(test = 0; test < TESTS; test++) {
//        fprintf(stdout, "%lf ", fLoop[test]);
//        processStatData(fLoop[test]);
//    }
//    printStatData();

//    unsigned int registerResults = 0, memoryResults = 0;
//    for(test = 0; test < TESTS; test++) {
//        if (fUnaryRegister[test] < fBinaryRegister[test]) {
//            registerResults++;
//        }
//        if (fUnaryMemory[test] < fBinaryMemory[test]) {
//            memoryResults++;
//        }
//    }

//    fprintf(stdout, "\n---------------- Registry reults:\n");
//    fprintf(stdout, "Unary calls were faster in %d%% tests.\n", registerResults * 100 / TESTS);
//    fprintf(stdout, "\n---------------- Memory reults:\n");
//    fprintf(stdout, "Unary calls were faster in %d%% tests.\n", memoryResults * 100 / TESTS);
//    fprintf(stdout, "\nTest was runnig %lf seconds.\n", (endAll.tv_sec - startAll.tv_sec) + (endAll.tv_usec - startAll.tv_usec)/1000000.0);

//    int main2();
//    main2();
//    return 0;
//}

int unary(int i) {
  i++;
  return i;
}


int binary(int i) {
  i = i + 2;
  return i;
}

int unary2(int i) {
  x++;
  return i;
}


int binary2(int i) {
  x = x + 2;
  return i;
}


int main() {
  struct timeval start, end;

  float f1, f2, f3, f4, f5;
  int reg = 0, mem = 0;

  for (int test = 1; test <= TESTS; test++) {
    printf("Test: %d ", test);

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = unary(a);
      }
    }
    gettimeofday(&end, NULL);
    f1 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    fprintf(stdout, "Unary: %lf ", f1);

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = binary(a);
      }
    }
    gettimeofday(&end, NULL);
    f2 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    fprintf(stdout, "Binary: %lf ", f2);

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = unary2(a);
      }
    }
    gettimeofday(&end, NULL);
    f3 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    fprintf(stdout, "Unary: %lf ", f3);

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = binary2(a);
      }
    }
    gettimeofday(&end, NULL);
    f4 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    fprintf(stdout, "Binary2: %lf ", f4);

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
      }
    }
    gettimeofday(&end, NULL);
    f5 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    fprintf(stdout, "Loop: %lf ", f5);

    if (f1 > f2) {
      reg++;
    }
    if (f3 > f4) {
      mem++;
    }

    fprintf(stdout, "df reg: %lf ", f1 - f2);
    fprintf(stdout, "df mem: %lf ", f3 - f4);
    fprintf(stdout, " Unaries loosed reg: %d%% mem: %d%%\n", reg * 100 / test, mem * 100 / test);
  }

  mem = 0;
  reg = 0;
  for (int test = 1; test <= TESTS; test++) {
    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = unary(a);
      }
    }
    gettimeofday(&end, NULL);
    f1 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = binary(a);
      }
    }
    gettimeofday(&end, NULL);
    f2 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = unary2(a);
      }
    }
    gettimeofday(&end, NULL);
    f3 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
        a = binary2(a);
      }
    }
    gettimeofday(&end, NULL);
    f4 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

    gettimeofday(&start, NULL);
    for(i = 0; i < 100; i++){
      for (j = 0; j < 1000000; j++){
      }
    }
    gettimeofday(&end, NULL);
    f5 = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

    if (f1 > f2) {
      reg++;
    }
    if (f3 > f4) {
      mem++;
    }
  }

  fprintf(stdout, "Non-writting test: df reg: %lf ", f1 - f2);
  fprintf(stdout, "df mem: %lf ", f3 - f4);
  fprintf(stdout, " Unaries loosed reg: %d%% mem: %d%%\n", reg * 100 / TESTS, mem * 100 / TESTS);

  return 0;
}
