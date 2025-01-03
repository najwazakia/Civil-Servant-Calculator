#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//Inisialisasi Variabel
vector<vector<string>> jenisPangkat = {
    {"1a", "2a", "3a", "4a"},
    {"1b", "2b", "3b", "4b"},
    {"1c", "2c", "3c", "4c"},
    {"1d", "2d", "3d", "4d"}
};
string statusKawin;
string jenisKelamin;
int jumlahAnak;
string jabatan;

//Fungsi untuk Menghitung Gaji Pokok
int gajiPokok(string pangkat) {
    if (pangkat == "1a") {
        return 1700000;
    }
    else if (pangkat == "1b") {
        return 1900000;
    }
    else if (pangkat == "1c") {
        return 2100000;
    }
    else if (pangkat == "1d") {
        return 2300000;
    }
    else if (pangkat == "2a") {
        return 2500000;
    }
    else if (pangkat == "2b") {
        return 2700000;
    }
    else if (pangkat == "2c") {
        return 2900000;
    }
    else if (pangkat == "2d") {
        return 3100000;
    }
    else if (pangkat == "3a") {
        return 3300000;
    }
    else if (pangkat == "3b") {
        return 3500000;
    }
    else if (pangkat == "3c") {
        return 3700000;
    }
    else if (pangkat == "3d") {
        return 3900000;
    }
    else if (pangkat == "4a") {
        return 4100000;
    }
    else if (pangkat == "4b") {
        return 4300000;
    }
    else if (pangkat == "4c") {
        return 4500000;
    }
    else if (pangkat == "4d") {
        return 4700000;
    }
    else if (pangkat == "4e") {
        return 4900000;
    }
}

//Fungsi untuk Menghitung Tunjangan Keluarga
double tunjanganKeluarga(string statusKawin, int jumlahAnak, string pangkat) {
    double tunjanganKeluarga = 0;
    if (statusKawin == "kawin") {
        tunjanganKeluarga += 0.1 * gajiPokok(pangkat);
        if (jumlahAnak > 0) {
            tunjanganKeluarga += jumlahAnak * 0.02 * gajiPokok(pangkat);
        }
    }
    return tunjanganKeluarga;
}

//Fungsi untuk Menghitung Tunjangan Jabatan
int tunjanganJabatan(string jabatan, string pangkat) {
    int tunjanganJabatan = 0;
    if(jabatan == "struktural"){
        if(pangkat == "1a"){
            tunjanganJabatan = 5500000;
        }
        else if(pangkat == "1b"){
            tunjanganJabatan = 4375000;
        }
        else if(pangkat == "2a"){
            tunjanganJabatan = 3250000;
        }
        else if(pangkat == "2b"){
            tunjanganJabatan = 2025000;
        }
        else if(pangkat == "3a"){
            tunjanganJabatan =  1260000;
        }
        else if(pangkat == "3b"){
            tunjanganJabatan = 980000;
        }
        else if(pangkat == "4a"){
            tunjanganJabatan = 540000;
        }
        else if(pangkat == "4b"){
            tunjanganJabatan = 490000;
        }
    }
    else if(jabatan == "fungsional"){
        if(pangkat == "3a" || pangkat == "3b"){
            tunjanganJabatan =1200000;
        }
        else if(pangkat == "3c" || pangkat == "3d"){
            tunjanganJabatan = 2300000;
        }
        else if(pangkat == "4a" || pangkat == "4b" || pangkat == "4c"){
            tunjanganJabatan = 3200000;
        }
        else if(pangkat == "4d" || pangkat == "4e"){
            tunjanganJabatan = 500000;
        }
    }
    else{
        tunjanganJabatan = 0;
    }
    return tunjanganJabatan;
}

//Fungsi untuk Menghitung Tunjangan Umum (untuk Jabatan Selain Struktural dan Fungsional)
int tunjanganUmum(string jabatan, string pangkat) {
    int tunjanganUmum = 0;
    if(jabatan == "lainnya"){
        if (pangkat == "4a" || pangkat == "4b" || pangkat == "4c" || pangkat == "4d" || pangkat == "4e") {
            tunjanganUmum = 190000;
        }
        else if (pangkat == "3a" || pangkat == "3b" || pangkat == "3c" || pangkat == "3d") {
            tunjanganUmum = 185000;
        }
        else if (pangkat == "2a" || pangkat == "2b" || pangkat == "2c" || pangkat == "2d") {
            tunjanganUmum = 180000;
        }
        else if (pangkat == "1a" || pangkat == "1b" || pangkat == "1c" || pangkat == "1d") {
            tunjanganUmum = 175000;
        }
    }
    else{
        tunjanganUmum = 0;
    }
    return tunjanganUmum;
}

//Fungsi untuk Menghitung Tunjangan Beras
int tunjanganBeras(string statusKawin, int jumlahAnak) {
    int jumlahAnggota = 1;
    if (statusKawin == "kawin") {
        jumlahAnggota += 1 + jumlahAnak;
    }
    int beratBerasPerOrang = 10;
    int hargaBeras = 17620;
    return jumlahAnggota * beratBerasPerOrang * hargaBeras;
}

//Fungsi untuk Menghitung Total Tunjangan
int totalTunjangan(int tunjanganKeluarga, int tunjanganJabatan, int tunjanganUmum, int tunjanganBeras) {
    return tunjanganKeluarga + tunjanganJabatan + tunjanganUmum + tunjanganBeras;
}

int main() {
    //Memasukkan "4e" ke Dalam Array jenisPangkat
    jenisPangkat[3].push_back("4e");
    char ulang;

    //Meminta Input dari Pengguna Hingga Input Valid
    do {
        string pangkat;
        bool valuePangkat = false;

        while (!valuePangkat) {
            cout << "Masukkan pangkat pengguna (contoh: 1a): ";
            cin >> pangkat;

            for (int i = 0; i < jenisPangkat.size(); i++) {
                for (int j = 0; j < jenisPangkat[i].size(); j++) {
                    if (pangkat == jenisPangkat[i][j]) {
                        valuePangkat = true;
                        break;
                    }
                }
                if (valuePangkat) break;
            }

            if (!valuePangkat) {
                cout << "Masukkan input yang valid!" << endl;
            }
        }

        bool valueStatusKawin = false;
        while (!valueStatusKawin) {
            cout << "Masukkan status kawin pengguna (kawin/belum): ";
            cin >> statusKawin;
            if (statusKawin == "kawin" || statusKawin == "belum") {
                valueStatusKawin = true;
            } else {
                cout << "Masukkan input yang valid!" << endl;
            }
        }

        bool valueJumlahAnak = false;
        while (!valueJumlahAnak) {
            //Melewati Fungsi Apabila Status Perkawinan adalah "kawin"
            if(statusKawin == "belum"){
                break;
            }
            cout << "Masukkan jumlah anak (dalam angka): ";
            cin >> jumlahAnak;
            if (jumlahAnak >= 0) {
                valueJumlahAnak = true;
            } else {
                cout << "Masukkan input yang valid!" << endl;
            }
        }

        bool valueJabatan = false;
        while (!valueJabatan) {
            cout << "Masukkan jabatan pengguna (struktural/fungsional/lainnya): ";
            cin >> jabatan;
            if (jabatan == "struktural" || jabatan == "fungsional" || jabatan == "lainnya") {
                valueJabatan = true;
            } else {
                cout << "Masukkan input yang valid!" << endl;
            }
        }

        //Memanggil Fungsi
        int gaji = gajiPokok(pangkat);
        double tunjanganKeluargaVal = tunjanganKeluarga(statusKawin, jumlahAnak, pangkat);
        int tunjanganJabatanVal = tunjanganJabatan(jabatan, pangkat);
        int tunjanganUmumVal = tunjanganUmum(jabatan, pangkat);
        int tunjanganBerasVal = tunjanganBeras(statusKawin, jumlahAnak);

        //Mengeluarkan Output
        cout << endl;
        cout << "-------------------------------" << endl;
        cout << "Gaji pokok: " << gaji << endl;
        cout << "Total tunjangan: " << totalTunjangan(tunjanganKeluargaVal, tunjanganJabatanVal, tunjanganUmumVal, tunjanganBerasVal) << endl;
        cout << "Pendapatan bersih: " << gaji + totalTunjangan(tunjanganKeluargaVal, tunjanganJabatanVal, tunjanganUmumVal, tunjanganBerasVal) << endl;
        cout << "-------------------------------" << endl;
        cout << endl;

        //Memberikan Opsi Bagi User untuk Mengulang Program
        cout << "Apakah Anda ingin mengulangi program? (y/n): ";
        cin >> ulang;
    }
    while (ulang == 'y' || ulang == 'Y');

    //Keluar dari Program Jika Input Bukan 'y'/'Y'
    cout << "Program selesai. Tekan tombol apa saja untuk keluar." << endl;
    system("pause");
}