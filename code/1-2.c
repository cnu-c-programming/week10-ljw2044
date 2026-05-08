#include <stdio.h>
#include <string.h>

struct IPv4 {
    unsigned int version;
    unsigned int ihi;
    unsigned long long ttl;
    unsigned long long protocol;
    unsigned char data[1024];
};

int main() {
    struct IPv4 s;
    s.version;
    s.ihi;
    s.ttl;
    s.protocol;
    sprintf(s.data, "hello world");

    printf("version: %u, size: %zu\n", s.version, sizeof(s.version));
    printf("ihi: %u, size: %zu\n", s.ihi, sizeof(s.ihi));
    printf("ttl: %llu, size: %zu\n", s.ttl, sizeof(s.ttl));
    printf("protocol: %llu, size: %zu\n", s.protocol, sizeof(s.protocol));
    printf("data: %s, size: %zu\n", s.data, sizeof(s.data));
}
