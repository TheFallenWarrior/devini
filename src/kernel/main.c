#include <kernel/vga.h>
#include <kernel/sys.h>
#include <stdio.h>

#define VER_STR "Devini v0.0.0"
#define BUILD_STR __DATE__

void main(){
    init_vga();
    puts(VER_STR);
    puts("\nBuild: "); puts(BUILD_STR); puts("\n\n");
    puts("VGA text-mode driver installed.\n");

    cli();
    hlt();
}
