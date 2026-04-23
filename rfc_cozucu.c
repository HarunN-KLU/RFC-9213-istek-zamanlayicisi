#include <string.h>
#include <stdlib.h>
#include "turler.h"

int rfc_9213_oncelik_coz(const char* baslik) {
    // "u=x" formatini arar (Ornek: "u=2, i")
    char* u_konumu = strstr(baslik, "u=");
    if (u_konumu) {
        return atoi(u_konumu + 2); 
    }
    return 3; // Varsayilan oncelik degeri
}