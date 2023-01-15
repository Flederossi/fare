#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char cdelim[] = "\n";

int err(char *content){
    printf("Fare [ERROR] -> %s\n", content);
    return 0;
}

int run(char *target, char *content){
    char *cp;
    char t[sizeof(target) + 1];
    int found_target = 0, ret = 0;

    sprintf(t, "!%s", target);
    cp = strtok(content, cdelim);
    while (cp != NULL){
        if (cp[0] == '!'){
            if (found_target && target == NULL)
                return ret;
            found_target = 0;
            if (strcmp(t, cp) == 0 || target == NULL)
                found_target = ret = 1;
        }else if (found_target){
            printf("%s\n", cp);
            system(cp);
        }
        cp = strtok(NULL, cdelim);
    }
    free(cp);
    return ret;
}

int main(int argc, char *argv[]){
    FILE *fp;
    char *content;
    long size;

    fp = fopen("./Faregets", "r");
    if (fp == NULL)
        return err("No target file 'Faregets' found");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    content = malloc(size + 1);
    if (content == NULL)
        return err("Couldn't allocate memory for targets");
    fread(content, size, 1, fp);
    fclose(fp);
    content[size] = 0;

    if (!(argc < 2 ? run(NULL, content) : run(argv[1], content)))
        return err("Couldn't find requested target in 'Faregets' file");

    free(content);
    return 0;
}