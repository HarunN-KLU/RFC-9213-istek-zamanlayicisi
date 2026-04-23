#ifndef TURLER_H
#define TURLER_H

// RFC 9213: u=0 (en yüksek), u=7 (en düşük)
typedef struct {
    int id;
    int oncelik;      // RFC 9213 'u' değeri
    char veri[64];    // İstek içeriği
} Istek;

typedef struct {
    Istek* yigin;     // Heap dizisi
    int boyut;        // Mevcut eleman sayısı
    int kapasite;     // Maksimum kapasite
} ÖncelikKuyrugu;

#endif