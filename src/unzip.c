/*************************************************************************
    > File Name: unzip.c
    > Author: YangShufan
    > Mail: yangshufan@baidu.com 
    > Created Time: Mon 05 Dec 2016 02:44:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>

#include "zip.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage:%s zip_path entry_name output_path\n", argv[0]);
        exit(1);
    }

    const char *zip_path = argv[1];
    const char *entry_name = argv[2];
    const char *out_path = argv[3];
    
    void *out = NULL;
    unsigned long out_size = 0;
    zip_extract_to_mem(zip_path, entry_name, &out, &out_size);

    if (out == NULL || out_size==0) {
        printf("fail to extract %s from %s\n", entry_name, zip_path);
        exit(1);
    }

    int fd = open(out_path, O_RDWR | O_CREAT, 00666);
    if (fd == -1) {
        printf("fail to create %s\n", out_path);
        exit(1);
    }

    write(fd, out, out_size);

    close(fd);

    return 0;
}
