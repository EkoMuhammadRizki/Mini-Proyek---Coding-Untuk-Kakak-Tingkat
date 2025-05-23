#include <stdio.h>              
#include <string.h>             

int main() {
    char nama[50];             // Variabel untuk menyimpan nama member
    int pilihan;               // Untuk menyimpan menu yang dipilih user
    int qty, bayar, total = 0; // qty: jumlah barang, bayar: uang dibayar, total: total belanja

    // Variabel menyimpan jumlah masing-masing barang di keranjang
    int totalBeras = 0, totalTelur = 0, totalSabun = 0;

    printf("Masukkan nama member: "); // Input nama member
    scanf("%s", nama);

    while (1) { // Perulangan utama menu kasir
        // Menampilkan menu utama
        printf("\n=== MENU UTAMA KASIR ===\n");
        printf("1. Tambah barang ke keranjang\n");
        printf("2. Lihat keranjang & total\n");
        printf("3. Hapus barang dari keranjang\n");
        printf("4. Cetak struk & bayar\n");
        printf("5. Keluar\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan); // Input pilihan menu

        // Pilihan 1: Tambah barang
        if (pilihan == 1) {
            printf("\n=== DAFTAR BARANG ===\n");
            printf("1. Beras - Rp12000\n");
            printf("2. Telur - Rp22000\n");
            printf("3. Sabun - Rp5000\n");
            int barang;
            printf("Pilih barang (1-3): "); // Input pilihan barang
            scanf("%d", &barang);
            printf("Jumlah: ");             // Input jumlah barang
            scanf("%d", &qty);

            // Tambahkan barang ke keranjang
            if (barang == 1) {
                totalBeras += qty;
            } else if (barang == 2) {
                totalTelur += qty;
            } else if (barang == 3) {
                totalSabun += qty;
            } else {
                printf("Barang tidak valid.\n"); // Barang tidak ada
            }

        // Pilihan 2: Lihat keranjang
        } else if (pilihan == 2) {
            // Hitung total harga semua barang
            total = totalBeras * 12000 + totalTelur * 22000 + totalSabun * 5000;
            printf("\n=== KERANJANG ===\n");

            // Tampilkan isi keranjang
            if (totalBeras > 0) printf("Beras x %d = Rp%d\n", totalBeras, totalBeras * 12000);
            if (totalTelur > 0) printf("Telur x %d = Rp%d\n", totalTelur, totalTelur * 22000);
            if (totalSabun > 0) printf("Sabun x %d = Rp%d\n", totalSabun, totalSabun * 5000);
            if (total == 0) printf("Keranjang kosong.\n");

            // Tampilkan total belanja
            printf("TOTAL: Rp%d\n", total);

        // Pilihan 3: Hapus barang dari keranjang
        } else if (pilihan == 3) {
            printf("\n=== HAPUS BARANG ===\n");
            printf("1. Beras\n");
            printf("2. Telur\n");
            printf("3. Sabun\n");
            int hapus;
            printf("Pilih barang yang ingin dihapus (1-3): ");
            scanf("%d", &hapus);
            printf("Jumlah yang ingin dihapus: ");
            scanf("%d", &qty);

            // Kurangi jumlah barang sesuai pilihan
            if (hapus == 1 && totalBeras >= qty) {
                totalBeras -= qty;
                printf("Beras dikurangi %d.\n", qty);
            } else if (hapus == 2 && totalTelur >= qty) {
                totalTelur -= qty;
                printf("Telur dikurangi %d.\n", qty);
            } else if (hapus == 3 && totalSabun >= qty) {
                totalSabun -= qty;
                printf("Sabun dikurangi %d.\n", qty);
            } else {
                printf("Jumlah tidak valid atau barang belum ada di keranjang.\n");
            }

        // Pilihan 4: Cetak struk dan bayar
        } else if (pilihan == 4) {
            // Hitung total
            total = totalBeras * 12000 + totalTelur * 22000 + totalSabun * 5000;

            // Tampilkan struk
            printf("\n=== STRUK PEMBAYARAN ===\n");
            printf("Nama Member: %s\n", nama);
            if (totalBeras > 0) printf("Beras x %d = Rp%d\n", totalBeras, totalBeras * 12000);
            if (totalTelur > 0) printf("Telur x %d = Rp%d\n", totalTelur, totalTelur * 22000);
            if (totalSabun > 0) printf("Sabun x %d = Rp%d\n", totalSabun, totalSabun * 5000);
            printf("TOTAL BAYAR: Rp%d\n", total);

            // Jika keranjang tidak kosong
            if (total == 0) {
                printf("Tidak ada barang yang dibeli.\n");
            } else {
                printf("Masukkan uang pembayaran: ");
                scanf("%d", &bayar);
                if (bayar >= total) {
                    printf("Kembalian: Rp%d\n", bayar - total);
                    printf("Terima kasih telah berbelanja!\n");
                    // Reset keranjang setelah pembayaran
                    totalBeras = 0;
                    totalTelur = 0;
                    totalSabun = 0;
                } else {
                    printf("Uang tidak cukup. Transaksi dibatalkan.\n");
                }
            }

        // Pilihan 5: Keluar program
        } else if (pilihan == 5) {
            printf("Terima kasih, %s! Sampai jumpa.\n", nama);
            break; // Keluar dari loop

        // Jika input tidak valid
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0; // Akhiri program
}
