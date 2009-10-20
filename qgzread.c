#include <stdio.h>
#include <zlib.h>
#include "../include/k.h"
#define BUFLEN      16384
K zread(K x,K y)
{
    char buf[BUFLEN];
    int err;

    gzFile in = gzopen(xs, "rb");
    if (in == NULL) {
        fprintf(stderr, "can't gzopen %s\n", xs);
        return ki(-1);
    }
    if(-1 == gzseek(in, y->j,SEEK_SET)) {
        fprintf(stderr, " %s\n", gzerror(in, &err));
        return ki(-1);
    }
    int len = gzread(in, buf, sizeof(buf));
    if (len < 0) {
        fprintf(stderr, " %s\n", gzerror(in, &err));
        return ki(-1);
    }
    if (gzclose(in) != Z_OK) {
        fprintf(stderr, "failed gzclose");
        return ki(-1);
    }
    return kpn(buf,len);
}
