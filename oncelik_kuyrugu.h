#ifndef ONCELIK_KUYRUGU_H
#define ONCELIK_KUYRUGU_H

#include "turler.h"

ÖncelikKuyrugu* kuyruk_olustur(int baslangic_kapasitesi);
void ekle(ÖncelikKuyrugu* ok, Istek yeni_istek);
Istek en_oncelikliyi_cikar(ÖncelikKuyrugu* ok);
void bellegi_serbest_birak(ÖncelikKuyrugu* ok);

#endif