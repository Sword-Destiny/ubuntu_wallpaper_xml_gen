#include <dirent.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> enum_dir(string dir, string type) {
    vector<string> files;
    DIR *dp;
    struct dirent *dir_ent_p;
    if ((dp = opendir(dir.c_str())) == NULL) {
        printf("目录不正确!\n");
        return files;
    }
    while ((dir_ent_p = readdir(dp)) != NULL) {
        if (strcmp(dir_ent_p->d_name, ".") == 0 || strcmp(dir_ent_p->d_name, "..") == 0) {
            continue;
        }
        char *tmp = strrchr(dir_ent_p->d_name, '.');
        if (tmp == NULL) {
            continue;
        }
        if (strstr(type.c_str(), tmp) != NULL) {
            files.emplace_back(string(dir_ent_p->d_name));
        }
    }
    return files;
}