# STM32F4 KS0108 FRAME_BUFFER GLCD

STM32Cube IDE arayüzü ile yazılmış, Frame Buffer destekli, KS0108 denetleyicili Grafik LCD (128x64) kütüphanesi. 

STM32F407VG serisi denetleyici için hazırlanmıştır.

1- Denetleyicinin pin isimleri, main.h dosyasındaki tanımlamalar dikkate alınarak hazırlanmalıdır.

2- "Inc" klasöründeki "fss_grafik_display.h" ve "fss_util.h" dosyaları derleyici tarafından oluşturulan yeni "Inc" klasörüne kopyalanmalıdır.

3- "FSS_DRV" klasörü, ".cproject" dosyası ile aynı dizine kopyalanmalı ve tanıtılmalıdır.

4- FILE -> Properties -> C/C++General -> Paths and Symbols -> (tab)Includes -> (button)Add -> Dosya dizini ve adı seçilerek tanıtlır.

5- FILE -> Properties -> C/C++General -> Paths and Symbols -> (tab)Source Location -> (button)Add Folder... -> Dosya dizini ve adı seçilerek tanıtlır.




FSS_DRV>

    -font3x5.c
    -fss_grafik_display.c
    -fss_grafik_lib.c
    -fss_util.c

Inc>

    -fss_grafik_display.h
    -fss_util.h
    -main.h (örnek dosya / for example)

Src>

    -main.c (örnek dosya / for example)
    
<a href="https://ibb.co/Y7f9MKY"><img src="https://i.ibb.co/6RDhxpV/LCD.jpg" alt="LCD" border="0"></a>

<a href="https://ibb.co/VSd4BnN"><img src="https://i.ibb.co/Hz08gw2/PIN.jpg" alt="PIN" border="0"></a>
