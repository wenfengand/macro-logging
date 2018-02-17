# project macro-logging
This is a project to build a log system, especially for embedded system.
## Features
- Built by macros
- Multiple levels: info, warning, serious, and severe
- Multiple types: trace, state, fresh and halt

# Test it
1. Git clone project macro-logging.
2. Make build directory. Command is "mkdir build"
3. Generate makefiles. Command are "cd build" and "cmake -G "MSYS Makefiles" ../ "
4. Build test. Command is "make test-logging"
5. Run test. Command is "./test/test-logging.exe" 

*NOTE*: Only tested on windows system.

## Usage
1. Move debug.h and ports/config.h to your project
2. Customize it according to your requirements. All you can customize it is replacing standard printf with marco debug_printf, switch on debug types by DBG_TYPES_ON macro, switch on debug level by DBG_MIN_LEVEL macro, and define your own debug macros like NORMAL_DEBUG, which is demonstrated in folder test.