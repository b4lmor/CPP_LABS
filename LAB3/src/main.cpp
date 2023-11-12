#include <iostream>
#include "utils/ParsedArgs.h"
#include "utils/Helper.h"
#include "exception/MyException.h"
#include "soundprocessor/SoundProcessor.h"

int main(int argc, char *argv[]) {

    try {
        ParsedArgs args(argc, argv);

        switch (args.get_mode()) {
            case HELP:
                print_help();
                break;
            case PROCESS:
                SoundProcessor soundProcessor(
                        args.get_output_file_path(),
                        args.get_input_paths()
                );
                soundProcessor.process(
                        args.get_config_file_path()
                );
                break;
        }

    } catch (MyException &e) {
        std::cerr << e.get_cause() << std::endl;
        return 1;
    }

    return 0;
}
