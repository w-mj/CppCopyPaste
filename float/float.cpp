#include <cstdio>

void printHex(void* data, size_t length) {
    unsigned char *t = (unsigned char *)(data);
    for (int i = 0; i < length; i++) {
        printf("%02x ", t[i]);
    }
    printf("\n");
}

void printf4(float a) {
    printf("%.4f\n", a);
}

template<typename ...Args>
void printf4(float a, Args... remain) {
    printf("%.4f ", a);
    printf4(remain...);
}

int main() {
    // float a = 0.65f;
    // float b = 0.6f;
    // float c = a - b;
    // printHex(&c, sizeof(c));
    // printf("%lf\n", c);
    // printf4(0.999999999, 1.0);
    // printf("%.9f\n", 0.3);

    float a = 1.2344999, b = 1.2345000;
    printf("%.3f, %.3f\n", a, b);
}