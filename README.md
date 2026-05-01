# 💊 Pharmacy Management System (PMS)

A console-based **Pharmacy Management System** built in **C++** that allows pharmacies to manage their medicine inventory, sell medicines, and apply government health scheme discounts.

---

## 📋 Features

- **View Medicine List** — Display all available medicines with name, formula, quantity, price, and total value
- **Search Medicine** — Search by medicine name; if not found, option to search by chemical formula
- **Add Medicine** — Add new medicines to the inventory (saved to file)
- **Sell Medicine** — Sell a medicine, update stock, and generate a bill
- **Sehat Card Scheme** — Apply discounts based on 12-digit government health card number:
  - Card ending in `1234` → **55% discount**
  - Card ending in `1111` → **75% discount** (Special Person Card)
  - All other valid cards → **40% discount**

---

## 🗂️ Project Structure

```
PMS_Project/
│
├── PMS_Project.cpp     # Main source code
└── PMS1.txt            # Medicine data file (auto-created/updated)
```

---

## ⚙️ How to Run

### Prerequisites
- A C++ compiler (e.g., **g++**, MinGW, or any IDE like Code::Blocks / Dev-C++)

### Compile & Run

```bash
# Compile
g++ PMS_Project.cpp -o PMS

# Run
./PMS
```

> **Note:** Make sure `PMS1.txt` exists in the same directory as the executable. The file stores all medicine records. If it doesn't exist, create an empty file named `PMS1.txt`.

---

## 📁 Data File Format (`PMS1.txt`)

Each medicine entry is stored as 5 lines:

```
MedicineName
ChemicalFormula
Amount
Price
Total
```

**Example:**
```
Panadol
Paracetamol
100
50
5000
Brufen
Ibuprofen
60
80
4800
```

---

## 🖥️ Menu Options

```
1) Show List
2) Search Medicine
3) Add Medicine
4) Sell Medicine
5) Exit
```

---

## 🏥 Sehat Card Scheme (Discount System)

After a sale, the system asks if the customer has a **Sehat Card**. If yes:
1. Enter the **12-digit card number**
2. Discount is automatically calculated based on the last 4 digits of the card

| Last 4 Digits | Discount |
|---------------|----------|
| `1234`        | 55%      |
| `1111`        | 75% (Special Person) |
| Any other     | 40%      |

---

## 🧱 Class Structure

| Class | Description |
|-------|-------------|
| `Pharmacy` | Core class — handles inventory (list, search, add, sell) |
| `Scheme` | Inherits from `Pharmacy` — handles Sehat Card validation and discount calculation |

---

## ⚠️ Known Limitations

- Maximum of **100 medicines** can be stored (fixed-size arrays)
- Medicine names are **case-sensitive** during search
- No password/authentication for admin operations (Add Medicine)
- Data is stored in a plain text file (no database)

---

## 🚀 Future Improvements

- Add login/authentication system
- Use dynamic data structures (vectors) to remove the 100-medicine limit
- Add medicine expiry date tracking
- Generate printable receipts/invoices
- Switch to a database (e.g., SQLite) for better data management

---

## 👨‍💻 Author
Amina Batool
> Developed as a semester project for learning Object-Oriented Programming in C++.

---

## 📄 License

This project is for **educational purposes only**.
