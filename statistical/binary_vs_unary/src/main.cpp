#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <sys/resource.h>
#include <unistd.h>

#define TESTS 500
static int x = 0;
volatile int a = 0;
volatile uint64_t i = 0;
volatile uint64_t j = 0;

int binaryRegister(int i) {
    i = i + 1;
    return i;
}

int unaryRegister(int i) {
    i++;
    return i;
}

int binaryMemory(int i) {
    x = x + 1;
    return i;
}

int unaryMemory(int i) {
    x++;
    return i;
}

double sum = 0;
unsigned int samples = 0;
void nullptrStatData() {
    sum = 0;
    samples = 0;
}

void processStatData(double item) {
    sum += item;
    samples++;
}

void printStatData() {
    fprintf(stdout, "\nStatistics: ");
    fprintf(stdout, "collected samples: %d", samples);
    fprintf(stdout, ", arithmetical average: %lf\n", sum / samples);
}

int main(){
    setpriority(PRIO_PROCESS, getpid(), -20);

    struct timeval start, end, startAll, endAll;
    double fUnaryRegister[TESTS], fUnaryMemory[TESTS], fBinaryRegister[TESTS], fBinaryMemory[TESTS], fLoop[TESTS];
    unsigned int test;

    fprintf(stdout, "---------------- Starting %d tests\n", TESTS);
    gettimeofday(&startAll, nullptr);
    sleep(1);

    for(i = 0; i < 100; i++){
        for (j = 0; j < 1000000; j++){
            a = binaryRegister(a);
        }
    }
    for(i = 0; i < 100; i++){
        for (j = 0; j < 1000000; j++){
            a = unaryRegister(a);
        }
    }

    for (test = 0; test < TESTS; test++) {
        gettimeofday(&start, nullptr);
        for(i = 0; i < 100; i++){
            for (j = 0; j < 1000000; j++){
                a = binaryRegister(a);
            }
        }
        gettimeofday(&end, nullptr);
        fBinaryRegister[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

        gettimeofday(&start, nullptr);
        for(i = 0; i < 100; i++){
            for (j = 0; j < 1000000; j++){
                a = unaryRegister(a);
            }
        }
        gettimeofday(&end, nullptr);
        fUnaryRegister[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

        gettimeofday(&start, nullptr);
        for(i = 0; i < 100; i++){
            for (j = 0; j < 1000000; j++){
                a = binaryMemory(a);
            }
        }
        gettimeofday(&end, nullptr);
        fBinaryMemory[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

        gettimeofday(&start, nullptr);
        for(i = 0; i < 100; i++){
            for (j = 0; j < 1000000; j++){
                a = unaryMemory(a);
            }
        }
        gettimeofday(&end, nullptr);
        fUnaryMemory[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

        gettimeofday(&start, nullptr);
        for(i = 0; i < 100; i++){
            for (j = 0; j < 1000000; j++){
            }
        }
        gettimeofday(&end, nullptr);
        fLoop[test] = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;
    }

    gettimeofday(&endAll, nullptr);
    fprintf(stdout, "---------------- Measured data\n");

    nullptrStatData();
    fprintf(stdout, "\rUnary via register: \n");
    for(test = 0; test < TESTS; test++) {
        fprintf(stdout, "%lf ", fUnaryRegister[test]);
        processStatData(fUnaryRegister[test]);
    }
    printStatData();

    nullptrStatData();
    fprintf(stdout, "\rBinary via register: \n");
    for(test = 0; test < TESTS; test++) {
        fprintf(stdout, "%lf ", fBinaryRegister[test]);
        processStatData(fBinaryRegister[test]);
    }
    printStatData();

    nullptrStatData();
    fprintf(stdout, "\rUnary via memory: \n");
    for(test = 0; test < TESTS; test++) {
        fprintf(stdout, "%lf ", fUnaryMemory[test]);
        processStatData(fUnaryMemory[test]);
    }
    printStatData();

    nullptrStatData();
    fprintf(stdout, "\rBinary via memory: \n");
    for(test = 0; test < TESTS; test++) {
        fprintf(stdout, "%lf ", fBinaryMemory[test]);
        processStatData(fBinaryMemory[test]);
    }
    printStatData();

    fprintf(stdout, "\rLoop: \n");
    nullptrStatData();
    for(test = 0; test < TESTS; test++) {
        fprintf(stdout, "%lf ", fLoop[test]);
        processStatData(fLoop[test]);
    }
    printStatData();

    unsigned int registerResults = 0, memoryResults = 0;
    for(test = 0; test < TESTS; test++) {
        if (fUnaryRegister[test] < fBinaryRegister[test]) {
            registerResults++;
        }
        if (fUnaryMemory[test] < fBinaryMemory[test]) {
            memoryResults++;
        }
    }

    fprintf(stdout, "\n---------------- Registry results:\n");
    fprintf(stdout, "Unary calls were faster in %d%% tests.\n", registerResults * 100 / TESTS);
    fprintf(stdout, "\n---------------- Memory results:\n");
    fprintf(stdout, "Unary calls were faster in %d%% tests.\n", memoryResults * 100 / TESTS);
    fprintf(stdout, "\nTesting program was runig %lf seconds.\n", (endAll.tv_sec - startAll.tv_sec) + (endAll.tv_usec - startAll.tv_usec)/1000000.0);
    return 0;
}
