#include <iostream>
#include <fstream>
using namespace std;

string new_code = "#include <iostream>\nusing namespace std;\nunsigned char arr[30000];\nshort i = 0;\nint main() {\n";

void check_code(string code) {
    for(int j = 0; j < code.length(); j ++) {
        switch (code[j]) {
        case '+':
            new_code += "    arr[i] ++;\n";
            break;
        case '-':
            new_code += "    arr[i] --;\n";
            break;
        case '>':
            new_code += "    i ++;\n";
            break;
        case '<':
            new_code += "    i --;\n";
            break;
        case '.':
            new_code += "    cout << arr[i];\n";
            break;
        case ',':
            new_code += "    cin >> arr[i];\n";
            break;
        case '[':
            new_code += "    while(arr[i] != 0) {\n";
            break;
        case ']':
            new_code += "    }\n";
            break;
        default:
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream indata;
    indata.open(argv[1]);
    string code;
    getline(indata, code, (char)0);
    check_code(code);
    new_code += "}";
    ofstream outdata;
    string outname = argv[1];
    outdata.open(outname.substr(0, outname.find(".")) + ".cpp");
    outdata << new_code << endl;
}