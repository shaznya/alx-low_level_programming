#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append_text_to_file(const char *filename, char *text_content) {
    FILE *file;
    size_t len, bytesWritten;

    if (filename == NULL)
        return -1;

    file = fopen(filename, "a");
    if (file == NULL)
        return -1;

    if (text_content != NULL) {
        len = strlen(text_content);
        bytesWritten = fwrite(text_content, sizeof(char), len, file);
        if (bytesWritten < len) {
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return 1;
}

