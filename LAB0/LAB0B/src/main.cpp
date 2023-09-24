#include <iostream>
#include <fstream>

#include "utils.h"
#include "file_utils.h"
#include "my_exception.h"
#include "word_counter.h"

using namespace std;

int main(int argc, char * argv[]) {

    string in_path;
    string out_path;
    ifstream in_file;
    ofstream out_file;

    try {
        parse_args(in_path, out_path, argc, argv);
        open_in_file(in_file, in_path);
        open_out_file(out_file, out_path);
        count_words(in_file, out_file);
    } catch (my_exception & ex) {
        cout << ex.get_msg() << endl;
    } catch (...) {
        cout << "Undefined behavior" << endl;
    }

    in_file.close();
    out_file.close();

	return 0;
}
