#include <stdio.h>
#include <stdlib.h>
#include "oncelik_kuyrugu.h"

ÖncelikKuyrugu* kuyruk_olustur(int baslangic_kapasitesi) {
    ÖncelikKuyrugu* ok = (ÖncelikKuyrugu*)malloc(sizeof(ÖncelikKuyrugu));
    ok->yigin = (Istek*)malloc(sizeof(Istek) * baslangic_kapasitesi);
    ok->boyut = 0;
    ok->kapasite = baslangic_kapasitesi;
    return ok;
}

void yer_degistir(Istek* a, Istek* b) {
    Istek gecici = *a;
    *a = *b;
    *b = gecici;
}

// Min-Heap kuralini korumak icin yukari tasima
void yukari_yiginla(ÖncelikKuyrugu* ok, int indeks) {
    while (indeks > 0) {
        int ebeveyn = (indeks - 1) / 2;
        if (ok->yigin[indeks].oncelik < ok->yigin[ebeveyn].oncelik) {
            yer_degistir(&ok->yigin[indeks], &ok->yigin[ebeveyn]);
            indeks = ebeveyn;
        } else break;
    }
}

// Min-Heap kuralini korumak icin asagi tasima
void asagi_yiginla(ÖncelikKuyrugu* ok, int indeks) {
    int en_kucuk = indeks;
    int sol = 2 * indeks + 1;
    int sag = 2 * indeks + 2;

    if (sol < ok->boyut && ok->yigin[sol].oncelik < ok->yigin[en_kucuk].oncelik)
        en_kucuk = sol;
    if (sag < ok->boyut && ok->yigin[sag].oncelik < ok->yigin[en_kucuk].oncelik)
        en_kucuk = sag;

    if (en_kucuk != indeks) {
        yer_degistir(&ok->yigin[indeks], &ok->yigin[en_kucuk]);
        asagi_yiginla(ok, en_kucuk);
    }
}

void ekle(ÖncelikKuyrugu* ok, Istek yeni_istek) {
    // Dinamik Bellek Yonetimi (Realloc)
    if (ok->boyut == ok->kapasite) {
        ok->kapasite *= 2;
        ok->yigin = (Istek*)realloc(ok->yigin, sizeof(Istek) * ok->kapasite);
    }
    ok->yigin[ok->boyut] = yeni_istek;
    yukari_yiginla(ok, ok->boyut);
    ok->boyut++;
}

Istek en_oncelikliyi_cikar(ÖncelikKuyrugu* ok) {
    if (ok->boyut == 0) {
        fprintf(stderr, "Hata: Kuyruk bos!\n");
        exit(1);
    }
    Istek kok = ok->yigin[0];
    ok->yigin[0] = ok->yigin[ok->boyut - 1];
    ok->boyut--;
    asagi_yiginla(ok, 0);
    return kok;
}

void bellegi_serbest_birak(ÖncelikKuyrugu* ok) {
    free(ok->yigin);
    free(ok);
}