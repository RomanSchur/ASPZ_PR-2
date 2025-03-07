#include <stdio.h>
#include <stdlib.h>

int global_var = 42;      
int bss_var ;      
static int static_var = 100; 

void stack_growth(int position) {
    char large_array[10000]; 
    printf("Змінна в стеку на позиції %d: %p\n", position, large_array);
    if (position < 5) { 
        stack_growth(position + 1);
    }
}
int main() {
    int i;      
    char *hp_var = malloc(1024); // Динамічно виділена пам’ять 
    printf("Адреса локальної змінної: %p\n", &i);
    printf("Адреса неініціалізованої змінної: %p\n", &bss_var);
    printf("Адреса глобальної змінної: %p\n", &global_var);
    printf("Адреса статичної змінної: %p\n", &static_var);
    printf("Адреса змінної в купі: %p\n", hp_var);
    stack_growth(1); 
    free(hp_var); 
    return 0;
}

