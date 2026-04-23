#include <stdio.h>
#include "oncelik_kuyrugu.h"
#include "rfc_cozucu.h"

int main() {
    ÖncelikKuyrugu* ok = kuyruk_olustur(10);

    // Simule edilen HTTP istek basliklari
    const char* gelen_istekler[] = { "u=5", "u=0", "u=3", "u=7", "u=1" };
    
    printf("--- Istekler Aliniyor ---\n");
    for (int i = 0; i < 5; i++) {
        Istek ist;
        ist.id = i + 1;
        ist.oncelik = rfc_9213_oncelik_coz(gelen_istekler[i]);
        sprintf(ist.veri, "ID %d Verisi", ist.id);
        
        printf("Eklendi: ID %d (Oncelik u=%d)\n", ist.id, ist.oncelik);
        ekle(ok, ist);
    }

    printf("\n--- Isleme Sirasi (Min-Heap Sonucu) ---\n");
    while (ok->boyut > 0) {
        Istek ust = en_oncelikliyi_cikar(ok);
        printf("Isleniyor: ID %d [RFC Oncelik u=%d]\n", ust.id, ust.oncelik);
    }

    bellegi_serbest_birak(ok);
    return 0;
}