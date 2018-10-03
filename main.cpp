#include <iostream>
#include <fstream>
#include <ios>
#include "c_enum_file.h"

using namespace std;

int main(int argc, char *argv[]) {
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
    cout << "<!-- directory : " << (argc > 1 ? argv[1] : ".") << " -->" << endl;
    vector<string> files = argc > 1 ? enum_dir(argv[1], type) : enum_dir(".", type);
    for (int i = 0; i < files.size(); ++i) {
        string file = files[i];
        string next_file = files[(i + 1) % files.size()];
        cout <<
             "  <static>\n" <<
             "    <duration>55.0</duration>\n" <<
             "    <file>/home/yuanhao/图片/" << file.c_str() << "</file>\n" <<
             "  </static>\n" <<
             "  <transition>\n" <<
             "    <duration>0.5</duration>\n" <<
             "    <from>/home/yuanhao/图片/" << file.c_str() << "</from>\n" <<
             "    <to>/home/yuanhao/图片/" << next_file.c_str() << "</to>\n" <<
             "  </transition>" << endl;
    }
    cout << "</background>" << endl;
    return 0;
}