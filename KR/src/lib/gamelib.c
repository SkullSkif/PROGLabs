#include <lib/gamelib.h>

void compress(char* input, char* output)
{
    int dict_size = 256;
    int i, j;
    unsigned int k;
    int len = strlen(input);

    int* dict = (int*)calloc(MAX_DICT_SIZE, sizeof(int));
    char* str = (char*)calloc(len + 1, sizeof(char));
    int* compressed = (int*)calloc(len, sizeof(int));

    for (i = 0; i < MAX_DICT_SIZE; i++)
        dict[i] = -1;

    for (i = 0; i < len; i++) {
        str[i] = input[i];
    }

    int p = str[0], c;
    j = 256;

    for (i = 1; i < len; i++) {
        c = str[i];
        k = (p << 8) + c;
        if (dict[k] != -1) {
            p = dict[k];
        } else {
            compressed[j++] = p;
            dict[k] = j - 1;
            p = c;
        }
    }

    compressed[j++] = p;

    FILE* fp;
    fp = fopen(output, "wb");

    fwrite(compressed, sizeof(int), j, fp);

    fclose(fp);

    free(dict);
    free(str);
    free(compressed);
}

void decompress(char* input, char* output)
{
    int dict_size = 256;
    int i, j;
    unsigned int k;
    int len;

    FILE* fp;
    fp = fopen(input, "rb");

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(int);
    rewind(fp);

    int* compressed = (int*)calloc(len, sizeof(int));
    char* str = (char*)calloc(MAX_DICT_SIZE, sizeof(char));
    char* out = (char*)calloc(MAX_DICT_SIZE, sizeof(char));

    for (i = 0; i < len; i++) {
        fread(&compressed[i], sizeof(int), 1, fp);
    }

    fclose(fp);

    for (i = 0; i < 256; i++) {
        str[i] = i;
    }

    int p = compressed[0], c;
    j = 0;

    out[j++] = p;

    for (i = 1; i < len; i++) {
        k = compressed[i];
        if (str[k] != '\0') {
            strcpy(out + j, str + k);
            j += strlen(str + k);
            c = str[k];
            str[dict_size++] = p;
            p = k;
        } else {
            c = str[p];
            strcpy(out + j, str + p);
            j += strlen(str + p);
            out[j++] = c;
            str[dict_size++] = p;
            p = k;
        }
    }

    FILE* fp2;
    fp2 = fopen(output, "w");

    fwrite(out, sizeof(char), j, fp2);

    fclose(fp2);

    free(compressed);
    free(str);
    free(out);
}