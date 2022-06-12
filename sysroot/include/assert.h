#ifndef __ASSERT_H
#define __ASSERT_H

#include <stdio.h>
#include <kernel/vga.h>
#include <kernel/sys.h>

#ifdef NDEBUG //Assert does nothing if NDEBUG is set

#define assert(_Expression) ((void)0)

#else // !NDEBUG

//The lack of printf() makes this really awkward
#define assert(_Expression) if(!_Expression){\
    settextcolor(15, 4);\
    puts("Assertion failed ("); puts(#_Expression); puts("). At ");\
    puts(__FILE__); puts(":"); put_int(__LINE__); puts("\nProgram halted.");\
    cli(); hlt();\
    }

#endif //NDEBUG

#endif //__ASSERT_H
