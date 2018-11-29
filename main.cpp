#include <iostream>
#include <fstream>
#include <ios>
#include <unistd.h>
#include <limits.h>
#include "c_enum_file.h"

using namespace std;

/**
 * 将当前路径下的图片构建为一个Ubuntu的背景xml配置文件,以实现自定义图片背景切换
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    char cwd[PATH_MAX];
    getcwd(cwd,PATH_MAX);
    string type = ".jpg,.png,.jpeg,.svg,.gif,.bmp";
    cout << "<!-- image type : " << type << " -->" << endl;
    cout << "<background>\n" <<
         "  <starttime>\n" <<
         "    <year>2009</year>\n" <<
         "    <month>08</month>\n" <<
         "    <day>04</day>\n" <<
         "    <hour>00</hour>\n" <<
         "    <minute>00</minute>\n" <<
         "    <second>00</second>\n" <<
         "  </starttime>" << endl;
    vector<string> files = enum_dir(".", type);
    for (int i = 0; i < files.size(); ++i) {
        string file = files[i];
        string next_file = files[(i + 1) % files.size()];
        // 图片显示时间55秒,切换时间0.5秒,需要的自行修改
        cout <<
             "  <static>\n" <<
             "    <duration>55.0</duration>\n" <<
             "    <file>" << cwd << "/" << file.c_str() << "</file>\n" <<
             "  </static>\n" <<
             "  <transition>\n" <<
             "    <duration>0.5</duration>\n" <<
             "    <from>" << cwd << "/" << file.c_str() << "</from>\n" <<
             "    <to>" << cwd << "/" << next_file.c_str() << "</to>\n" <<
             "  </transition>" << endl;
    }
    cout << "</background>" << endl;
    return 0;
}