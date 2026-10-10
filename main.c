#include <stdio.h>

void output(FILE* file);

int main(int argc, char *argv[]) {
    
    if (argc == 1) {
        FILE* file = stdin;
        output(file);
    } else {
        int count = argc - 1;
        FILE* file[count];

        for (int i = 0; i < count; i++) {
            file[i] = fopen(argv[i + 1], "rb");
            if (file[i] == NULL) {
                fprintf(stderr, "%s\n", "文件未找到！");
                return 1;
            }

            output(file[i]);
            fclose(file[i]);
        }
    }

    return 0;
}

void output(FILE* file) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        putc(c, stdout);
    }
}
