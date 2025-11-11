Program ini digunakan untuk **mendeteksi gerakan (motion detection)** menggunakan **sensor PIR (Passive Infrared Sensor)**.
Ketika PIR mendeteksi adanya gerakan (perubahan radiasi inframerah dari tubuh manusia atau hewan), maka **LED bawaan Arduino akan menyala**, dan pesan “Gerakan Terdeteksi!” akan muncul di **Serial Monitor**.

---

### 🔹 1. **Deklarasi Pin**

```cpp
int pirPin = 2;  // Sensor PIR terhubung ke pin digital 2
int ledPin = 13; // LED bawaan Arduino Uno (LED built-in)
```

* **pirPin (D2)** digunakan untuk membaca sinyal HIGH/LOW dari sensor PIR.
* **ledPin (D13)** digunakan untuk mengendalikan LED indikator bawaan Arduino.

---

### 🔹 2. **Setup**

```cpp
pinMode(pirPin, INPUT);   // Mengatur pin PIR sebagai input
pinMode(ledPin, OUTPUT);  // Mengatur LED sebagai output
Serial.begin(9600);       // Mengaktifkan komunikasi serial
digitalWrite(ledPin, LOW); // Mematikan LED saat awal
```

Pada tahap ini:

* Arduino menyiapkan pin yang digunakan.
* Menghidupkan komunikasi ke **Serial Monitor** untuk menampilkan data.

---

### 🔹 3. **Loop (Program Utama)**

```cpp
int pirState = digitalRead(pirPin); // Membaca kondisi dari PIR
```

Sensor PIR akan mengirim **sinyal HIGH** saat mendeteksi gerakan, dan **LOW** jika tidak ada gerakan.

---

### 🔹 4. **Logika Kondisi**

```cpp
if (pirState == HIGH) {
  Serial.println("Gerakan Terdeteksi!");
  digitalWrite(ledPin, LOW); // LED menyala
} else {
  digitalWrite(ledPin, HIGH); // LED mati
}
```

* Saat **PIR mendeteksi gerakan (HIGH)** →
  Arduino menampilkan pesan “Gerakan Terdeteksi!” dan **LED menyala**.

* Saat **tidak ada gerakan (LOW)** →
  **LED mati** dan tidak ada pesan tambahan.

> ⚠️ Catatan:
> LED bawaan Arduino Uno pada pin 13 sering menggunakan logika terbalik (LOW = ON, HIGH = OFF).
> Jadi, walaupun tampak “berlawanan”, ini benar untuk LED internal.

---

### 🔹 5. **Delay**

```cpp
delay(1000);
```

Arduino menunggu 1 detik sebelum membaca ulang sensor, agar hasil pembacaan tidak terlalu cepat berubah-ubah.

---

## ⚡ **Wiring Rangkaian Sensor PIR ke Arduino**

| Komponen           | Pin Arduino      | Keterangan                                  |
| ------------------ | ---------------- | ------------------------------------------- |
| **Sensor PIR**     | VCC → 5V         | Memberi daya ke sensor                      |
|                    | GND → GND        | Ground                                      |
|                    | OUT → D2         | Sinyal deteksi ke Arduino                   |
| **LED (opsional)** | Pin 13           | Bisa pakai LED internal atau LED eksternal  |
|                    | Katoda (-) → GND | Jika LED eksternal, tambahkan resistor 220Ω |

---

## 📊 **Cara Kerja Sensor PIR Secara Singkat**

* PIR mendeteksi **perubahan panas (inframerah)** dari tubuh manusia atau hewan.
* Bila tidak ada perubahan panas → sinyal **LOW**.
* Bila ada gerakan manusia/hewan lewat di depan sensor → sinyal **HIGH**.

Sensor PIR biasanya memiliki:

1. **Potensiometer sensitivitas (Sx)** → mengatur seberapa sensitif terhadap gerakan.
2. **Potensiometer waktu (Tx)** → mengatur lama sinyal HIGH bertahan setelah gerakan terdeteksi.

---

## 💡 **Tips Tambahan**

1. Tunggu **30–60 detik** setelah menyalakan Arduino untuk “kalibrasi” PIR.
2. Hindari penempatan sensor dekat kipas atau sinar matahari langsung.
3. Jika ingin menambahkan **buzzer alarm**, tambahkan kode:

   ```cpp
   int buzzerPin = 8;
   pinMode(buzzerPin, OUTPUT);

   if (pirState == HIGH) {
     digitalWrite(buzzerPin, HIGH);
   } else {
     digitalWrite(buzzerPin, LOW);
   }
   ```
