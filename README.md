# RFC 9213 Uyumlu Modüler API Gateway İstek Zamanlayıcısı
Bu proje, API Gateway sistemlerinde gelen HTTP isteklerini RFC 9213 (Extensible HTTP Priorities) standartlarına göre önceliklendiren ve Min-Heap veri yapısı kullanarak yöneten modüler bir simülasyondur.
## Proje Amacı
API üzerinden gelen yoğun trafik akışında, "urgency" (acil durum) parametresine göre istekleri sıralamak ve sistem kaynaklarını en verimli şekilde yönetmektir.
## Teknik Özellikler
- Algoritma: Min-Heap (Öncelikli Kuyruk) 
- Standart: RFC 9213 (u=0 en yüksek, u=7 en düşük öncelik) 
- Dil: C (Modüler Mimari) 
- Bellek Yönetimi: Dinamik Bellek Tahsisi (malloc, realloc, free)
## Dosya Yapısı
Proje, yazılım mimarisi prensiplerine uygun olarak header (.h) ve kaynak (.c) dosyalarına ayrılmıştır: 
- main.c: Sistem simülasyonu ve kontrol katmanı.
- oncelik_kuyrugu.c/.h: Min-Heap operasyonları (Ekleme, Çıkarma, Heapify). 
- rfc_cozucu.c/.h: RFC 9213 uyumlu header parser. 
- turler.h: Ortak veri yapıları (Struct tanımları).
## Zaman Karmaşıklığı (Big-O)
1) İşlem - 2) Algoritma - 3) Karmaşıklık
İstek Ekleme -  Min-Heap Insertion - O(\log n)
Öncelikliyi Çıkarma - Extract Min - O(\log n)
En Öncelikliyi Bulma - Peek (Kök Erişimi) - O(1)
Bellek Alanı - Dynamic Array - O(n)
