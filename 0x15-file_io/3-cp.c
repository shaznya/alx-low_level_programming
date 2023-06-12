#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *srcFile, const char *destFile);

int main(int argc, char *argv[])
{
    const char *srcFile;
    const char *destFile;

    if (argc != 3)
    {
        printf("Usage: cp file_from file_to\n");
        return 1;
    }

    srcFile = argv[1];
    destFile = argv[2];

    copyFile(srcFile, destFile);

    return 0;
}

void copyFile(const char *srcFile, const char *destFile)
{
    FILE *src;
    FILE *dest;
    size_t bytesRead;
    char buffer[1024];

    src = fopen(srcFile, "rb");
    if (src == NULL)
    {
        printf("Error: Can't open source file %s\n", srcFile);
        exit(1);
    }

    dest = fopen(destFile, "w");
    if (dest == NULL)
    {
        printf("Error: Can't create or write to destination file %s\n", destFile);
        fclose(src);
        exit(1);
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        if (fwrite(buffer, 1, bytesRead, dest) != bytesRead)
        {
            printf("Error: Can't write to destination file %s\n", destFile);
            fclose(src);
            fclose(dest);
            exit(1);
        }
    }

    fclose(src);
    fclose(dest);
}

